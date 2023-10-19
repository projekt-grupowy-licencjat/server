#include "equipment.h"

void Equipment::addItem(const std::pair<std::string, int>& item) {
    this->items.push_back(item);
}

std::vector<std::pair<std::string, int>> Equipment::getItems() {
    return this->items;
}
