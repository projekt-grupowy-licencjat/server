#ifndef SERVER_TCP_CONNECTION_H
#define SERVER_TCP_CONNECTION_H

#include <boost/asio/impl/io_context.ipp>

using boost::asio::ip::tcp;

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context &io_context) {
        return pointer(new tcp_connection(io_context));
    }

    tcp::socket &socket() {
        return socket_;
    }

    void start() {
        message_ = "test";

        boost::asio::async_write(socket_, boost::asio::buffer(message_),
                                 boost::bind(&tcp_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }

private:
    tcp_connection(boost::asio::io_context &io_context)
            : socket_(io_context) {
    }

    void handle_write(const boost::system::error_code & /*error*/,
                      size_t /*bytes_transferred*/) {
    }

    tcp::socket socket_;
    std::string message_;
};

#endif //SERVER_TCP_CONNECTION_H
