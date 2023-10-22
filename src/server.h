#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

class UDPServer {
public:
    explicit UDPServer(boost::asio::io_service& io_service)
            : _socket(io_service, udp::endpoint(udp::v4(), 10000)) // TODO: make configurable
    {
        startReceive();
    }
private:
    void startReceive() {
        _socket.async_receive_from(
                boost::asio::buffer(_recvBuffer), _remoteEndpoint,
                boost::bind(&UDPServer::handleReceive, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    }

    void handleReceive(const boost::system::error_code& error,
                       std::size_t bytes_transferred) {
        if (!error || error == boost::asio::error::message_size) {

            auto message = std::make_shared<std::string>("Hello, World\n");

            _socket.async_send_to(boost::asio::buffer(*message), _remoteEndpoint,
                                  boost::bind(&UDPServer::handleSend, this, message,
                                              boost::asio::placeholders::error,
                                              boost::asio::placeholders::bytes_transferred));
        }
    }

    void handleSend(std::shared_ptr<std::string> message,
                    const boost::system::error_code& ec,
                    std::size_t bytes_transferred) {
        startReceive();
    }

    udp::socket _socket;
    udp::endpoint _remoteEndpoint;
    std::array<char, 1024> _recvBuffer;
};

#endif //SERVER_SERVER_H
