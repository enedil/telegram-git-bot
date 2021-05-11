#include <seastar/core/app-template.hh>
#include <seastar/core/future.hh>
#include <seastar/core/thread.hh>
#include <seastar/http/httpd.hh>
#include <seastar/http/handlers.hh>
#include <seastar/http/function_handlers.hh>
#include <seastar/http/file_handler.hh>
#include <seastar/core/sharded.hh>
#include <seastar/core/reactor.hh>
#include <seastar/core/condition-variable.hh>
#include <seastar/core/when_all.hh>

#include <iostream>

using namespace seastar;

class stop_signal {
    bool _caught = false;
    seastar::condition_variable _cond;
private:
    void signaled() {
        if (_caught) {
            return;
        }
        _caught = true;
        _cond.broadcast();
    }
public:
    stop_signal() {
        seastar::engine().handle_signal(SIGINT, [this] { signaled(); });
        seastar::engine().handle_signal(SIGTERM, [this] { signaled(); });
    }
    ~stop_signal() {
        // There's no way to unregister a handler yet, so register a no-op handler instead.
        seastar::engine().handle_signal(SIGINT, [] {});
        seastar::engine().handle_signal(SIGTERM, [] {});
    }
    seastar::future<> wait() {
        return _cond.wait([this] { return _caught; });
    }
    bool stopping() const {
        return _caught;
    }
};

void set_routes(routes& r) {
    function_handler* h1 = new function_handler([](const_req req) {
        return "hello";
    });
    r.add(operation_type::GET, url("/"), h1);
}

future<> run_server() {
  static thread_local stop_signal signal;
  auto * my_server = new httpd::http_server_control;
  engine().at_exit([my_server] {
    return my_server->stop();        
  });
  return my_server->start("my-http-server").then([my_server] {
        return my_server->set_routes(set_routes);
  }).then([my_server] {
        return my_server->listen(ipv4_addr {"127.0.0.1", 2137});
  }).then([] {
    return signal.wait();
  });
}

int main(int ac, char** av) {
    seastar::app_template app;
    app.run(ac, av, run_server);
}
