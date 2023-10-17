#ifndef SERVER_DB_H
#define SERVER_DB_H

#include <pqxx/pqxx>

class db {
public:
    db(std::string db_name, std::string user, std::string password, std::string host_addr, int port);
    template <class Deserializable> Deserializable select(std::string query);
    void runTransaction(std::string query);
    ~db();
private:
    std::unique_ptr<pqxx::connection> c; // TODO: maybe use async connection later
};

#endif //SERVER_DB_H
