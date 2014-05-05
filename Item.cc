
#include <stdlib.h>
#include <iostream>
#include "Item.hh"

using namespace std;


bool Item::randInit = false;


Item::Item() {
    if (!randInit) {
        srand(10);
        randInit = true;
cout << "Item::Item(): 1" << endl;
    }
    number = rand() % 255;
    cout << "Item::Item(): 2" << endl;
}

Item::~Item() {
    cout << "Item::~Item(): 1" << endl;
}

int Item::getNumber() const {
    return number;
}

bool Item::operator>(const Item &other) const {
    return number > other.getNumber();
}

