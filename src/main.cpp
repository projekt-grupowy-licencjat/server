#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "server.h"

using boost::asio::ip::tcp;

int main() {
    // TODO: first load all of equipment etc data to memory
    // TODO: Maybe change everything to UDP? idk if tcp is even needed here
    // TODO: Save all the data to files every minute or so
    // TODO: Send players location and movement direction eg 32 times per second
    // TODO: Send equipment and other stuff when it changes
    try {
        boost::asio::io_context io_context;
        tcp_server server(io_context);
        io_context.run();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
