
#include <stdlib.h>
#include "Item.hh"


bool Item::randInit = false;


Item::Item() {
    if (!randInit) {
        srand(10);
        randInit = true;
    }
    number = rand() % 255;
}

Item::~Item() {
}

int Item::getNumber() const {
    return number;
}

bool Item::operator>(const Item &other) const {
    return number > other.getNumber();
}

