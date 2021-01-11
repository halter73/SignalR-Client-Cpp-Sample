#include <iostream>
#include <future>
#include "signalrclient/hub_connection.h"
#include "signalrclient/hub_connection_builder.h"
#include "signalrclient/signalr_value.h"

class logger : public signalr::log_writer
{
    // Inherited via log_writer
    virtual void write(const std::string& entry) override
    {
        std::cout << entry;
    }
};

int main()
{
    //std::string input;
    //std::cin >> input;
    std::promise<void> start_task;
    signalr::hub_connection connection = signalr::hub_connection_builder::create("http://localhost:5000/hub")
        .with_logging(std::make_shared<logger>(), signalr::trace_level::all)
        .build();

    connection.on("echo", [](const signalr::value& m)
    {
        std::cout << m.as_array()[0].as_string() << std::endl;
    });

    connection.start([&start_task](std::exception_ptr exception) {
        start_task.set_value();
    });

    start_task.get_future().get();

    std::promise<void> send_task;
    std::vector<signalr::value> arr { "hello world" };
    signalr::value arg(arr);

    connection.invoke("echo", arg, [&send_task](const signalr::value& value, std::exception_ptr exception) {
        send_task.set_value();
    });

    send_task.get_future().get();

    std::promise<void> stop_task;
    connection.stop([&stop_task](std::exception_ptr exception) {
        stop_task.set_value();
    });

    stop_task.get_future().get();

    std::cout << "Done!" << std::endl;

    return 0;
}
