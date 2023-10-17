#include <iostream>
#include "db.h"

db::db(std::string db_name, std::string user, std::string password, std::string host_addr, int port) {
    std::string params = std::format("dbname = {} user = {} password = {} hostaddr = {} port = {}",
                                     db_name, user, password, host_addr, port); // TODO: handle exception
    this->c = std::make_unique<pqxx::connection>(pqxx::connection(params));

    if (this->c->is_open()) std::cout << "Database connection opened.\n";
}

db::~db() {
    this->c->close();
}

void db::runTransaction(std::string query) {

}

template<class Deserializable>
Deserializable db::select(std::string query) {
    return nullptr;
}

