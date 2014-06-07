
#include <stdlib.h>
#include <iostream>
#include "Item.hh"
#include "RainbowItem.hh"

using namespace std;


RainbowItem::RainbowItem() {
    number = rand() % 137;
}

RainbowItem::RainbowItem(int num) {
    number = num;
}

RainbowItem::~RainbowItem() {}

unsigned char RainbowItem::r() const {
}

unsigned char RainbowItem::g() const {
}

unsigned char RainbowItem::b() const {
}

static void RainbowItem::readRainbowColors() {
    // Open file.
    // Read the first line containing number of colors.
    // Allocate colors array.
    // Read all the colors.
}


