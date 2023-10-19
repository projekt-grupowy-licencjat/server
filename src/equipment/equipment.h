#ifndef SERVER_EQUIPMENT_H
#define SERVER_EQUIPMENT_H

#include <vector>
#include <string>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class Equipment {
public:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive & ar, const unsigned int version) {
        ar & character_id;
        ar & items;
    }
    explicit Equipment(long character_id) : character_id(character_id) {}

    void addItem(const std::pair<std::string, int>& item);
    std::vector<std::pair<std::string, int>> getItems();
private:
    long character_id;
    std::vector<std::pair<std::string, int>> items; // with count
};

#endif //SERVER_EQUIPMENT_H
