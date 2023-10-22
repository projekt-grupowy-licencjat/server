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

        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
        set(PQXX /usr/local/include/pqxx)
        find_library(PQXX_LIB pqxx)
        find_library(PQ_LIB pq)

        add_executable(server src/main.cpp
                src/server.h
                src/config/config.cpp
                src/config/config.h
                src/equipment/equipment.h
                src/equipment/equipment.cpp
                src/handler.h
                src/handler.cpp
        )
        target_link_libraries(server ${Boost_LIBRARIES} ${PQXX_LIB} ${PQ_LIB})
endif()
