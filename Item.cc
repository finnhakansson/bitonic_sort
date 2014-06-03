
#include <stdlib.h>
#include <iostream>
#include "Item.hh"

using namespace std;


bool Item::randInit = false;


Item::Item() {
    if (!randInit) {
        srand(10);
        randInit = true;
    }
    number = rand() % 256;
}

Item::Item(int num) {
    number = num;
}

Item::~Item() {}

int Item::getNumber() const {
    return number;
}

bool Item::operator>(const Item &other) const {
    return number > other.getNumber();
}

