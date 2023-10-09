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
        add_executable(server src/main.cpp)
        target_link_libraries(asio_tut ${Boost_LIBRARIES})
endif()
