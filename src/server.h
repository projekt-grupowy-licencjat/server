#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <boost/asio/impl/io_context.ipp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind.hpp>
#include "tcp-connection.h"

using boost::asio::ip::tcp;

class tcp_server {
public:
    explicit tcp_server(boost::asio::io_context &io_context)
            : io_context_(io_context),
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 10000)) {
        start_accept();
    }

private:
    void start_accept() {
        tcp_connection::pointer new_connection =
                tcp_connection::create(io_context_);

        acceptor_.async_accept(new_connection->socket(),
                               boost::bind(&tcp_server::handle_accept,
                                           this,
                                           new_connection,
                                           boost::placeholders::_1)); // TODO: This _1 may create error
    }

    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code &error) {
        if (!error) {
            new_connection->start();
        }
        start_accept();
    }

    boost::asio::io_context &io_context_;
    tcp::acceptor acceptor_;
};

#endif //SERVER_SERVER_H
