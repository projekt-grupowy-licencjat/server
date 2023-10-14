cmake_minimum_required(VERSION 3.25)
project(server)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost)

if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        add_executable(server src/main.cpp
                src/server.h
                src/tcp-connection.h
                src/config/config.cpp
                src/config/config.h)
        target_link_libraries(server ${Boost_LIBRARIES})
endif()
