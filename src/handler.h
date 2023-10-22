#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H

#include <cstddef>
#include <boost/array.hpp>

class Handler {
public:
    Handler(std::size_t bytes_transferred, boost::array<char, 1024> buffer) :_buffer(buffer),
        _bytes_transferred(bytes_transferred) {};

    std::string get_response();
private:
    char * get_message();

    std::size_t _bytes_transferred;
    boost::array<char, 1024> _buffer;
};

#endif //SERVER_HANDLER_H
