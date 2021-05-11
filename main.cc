#include <seastar/core/app-template.hh>
#include <seastar/core/future.hh>
#include <seastar/core/thread.hh>
#include <seastar/http/httpd.hh>

using namespace seastar;

future<> run_server() {
  auto * my_server = new httpd::http_server_control;
  return my_server->start("my-http-server").then([&my_server] {
        return my_server->set_routes([](routes & r) {});
  }).then([&my_server] {
        return my_server->listen(ipv4_addr{"127.0.0.1", 2137});
    });
}

int main(int ac, char** av) {
    seastar::app_template app;
    app.run(ac, av, run_server);
}