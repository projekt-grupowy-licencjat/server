#include <iostream>
#include "session-handler.h"

void Session::run() {
    this->wait_for_request();
}

void Session::wait_for_request() {
    auto self(shared_from_this());

    boost::asio::async_read_until(m_socket, m_buffer, "\0",
                                  [this, self](boost::system::error_code ec, std::size_t length)
                                  {
                                      if (!ec)  {
                                          std::string data{
                                                  std::istreambuf_iterator<char>(&m_buffer),
                                                  std::istreambuf_iterator<char>()
                                          };
                                          std::cout << data << std::endl;
                                          wait_for_request();
                                      } else {
                                          std::cout << "error: " << ec << std::endl;;
                                      }
                                  });
}
