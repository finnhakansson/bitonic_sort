
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Item.hh"
#include "RainbowItem.hh"

using namespace std;


RainbowItem::RainbowItem() {
    number = rand() % 237;
}


RainbowItem::RainbowItem(int num) {
    number = num;
}


RainbowItem::~RainbowItem() {}


unsigned char RainbowItem::r() const {
    return 0xdd;
}


unsigned char RainbowItem::g() const {
    return 0x11;
}


unsigned char RainbowItem::b() const {
    return 0x44;
}


void RainbowItem::readRainbowColors() {
    ifstream inputStream("rainbow+white.rgb", ifstream::in);
    colors = (unsigned char**) new unsigned int[237];
    int index = 0;
    int lineNumber = 0;
    string line;
    while (getline(inputStream, line) && index < 237) {
        lineNumber++;
        index++;
        if (lineNumber <= 3) {
            index = 0;
            continue;
        }
        istringstream iss(line);
        iss >> colors[index][0];
        iss >> colors[index][1];
        iss >> colors[index][2];
    }
    inputStream.close();
}


