#ifndef SERVER_SESSION_HANDLER_H
#define SERVER_SESSION_HANDLER_H

#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(tcp::socket socket) : m_socket(std::move(socket)) {}
    void run();
private:
    void wait_for_request();
    tcp::socket m_socket;
    boost::asio::streambuf m_buffer;
};

#endif //SERVER_SESSION_HANDLER_H
