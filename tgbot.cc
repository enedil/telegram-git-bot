#include <seastar/core/app-template.hh>
#include <seastar/core/future.hh>
int main(int argc, char** argv) {
    seastar::app_template app;
    app.run(argc, argv, [] {
           return seastar::make_ready_future<>(); 
    });
}
