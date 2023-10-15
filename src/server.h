#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <boost/asio/impl/io_context.ipp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind.hpp>
#include <boost/asio/placeholders.hpp>

using boost::asio::ip::tcp;

class tcp_server {
public:
    explicit tcp_server(boost::asio::io_context &io_context)
            : io_context_(io_context),
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 10000)) { // TODO: Change to be configurable
        start_accept();
    }

private:
    void start_accept() {
        acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::cout << "Session created on: "
                          << socket.remote_endpoint().address().to_string()
                          << ":" << socket.remote_endpoint().port() << '\n';

            } else {
                std::cout << "error: " << ec.message() << std::endl;
            }

            start_accept();
        });
    }

    boost::asio::io_context &io_context_;
    tcp::acceptor acceptor_;
};

#endif //SERVER_SERVER_H
