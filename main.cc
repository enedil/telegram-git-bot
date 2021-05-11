#include <seastar/core/app-template.hh>
#include <seastar/core/future.hh>
#include <seastar/http/httpd.hh>

/* int main(int argc, char** argv) {
    seastar::app_template app;
    app.run(argc, argv, [] {
           return seastar::make_ready_future<>(); 
    });
}*/
using namespace seastar;
int main() {
	httpd::http_server_control my_server;
	my_server.start("my-http-server").then([&my_server] {
    		return my_server.set_routes([](routes & r) {
	});
	}).then([&my_server] {
	return my_server.listen(ipv4_addr{"127.0.0.1", 2137}).then([] {
    });
});
}
