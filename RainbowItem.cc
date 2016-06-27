
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Item.hh"
#include "RainbowItem.hh"

using namespace std;

typedef struct { unsigned char* jump, unsigned char rgb[3]; } element;

RainbowItem::RainbowItem() {
    number = rand() % 256;
    rgb = hsv2rgb(number * 360.0 / 256.0, 1.0, 1.0);
}


RainbowItem::RainbowItem(int num) {
    number = num;
    rgb = hsv2rgb(number * 360.0 / 256.0, 1.0, 1.0);
}


RainbowItem::~RainbowItem() {}


unsigned char RainbowItem::r() const {
    return (unsigned char) ((rgb >> 24) & 0xff);
}


unsigned char RainbowItem::g() const {
    return (unsigned char) ((rgb >> 16) & 0xff);
}


unsigned char RainbowItem::b() const {
    return (unsigned char) ((rgb >> 8) & 0xff);
}


void RainbowItem::dump() const {
    printf("number = %d, v = %0.2f, rgb = %02x%02x%02x00\n", number, number * 360.0 / 256.0, r(), g(), b());
}


unsigned long RainbowItem::hsv2rgb(float h, float s, float v) {
    float r, g, b;
    if (s < 0.001) {
        // Achromatic (grey).
        r = g = b = v;
    } else {
        h /= 60.0; // Sector 0 to 5.
        float w = floorf(h);
        float f = h - w; // Factorial part of h.
        float p = v * (1.0 - s);
        float q = v * (1.0 - s * f);
        float t = v * (1.0 - s * (1.0 - f));
        switch ((unsigned long) w) {
            case 0:
                r = v; g = t; b = p;
                break;
            case 1:
                r = q; g = v; b = p;
                break;
            case 2:
                r = p; g = v; b = t;
                break;
            case 3:
                r = p; g = q; b = v;
                break;
            case 4:
                r = t; g = p; b = v;
                break;
            case 5:
            default:
                r = v; g = p; b = q;
                break;
        }
    }
    //printf("rgb = %0.2f, %0.2f, %0.2f  rgb = %08lx\n", r, g, b, (unsigned long) (((unsigned long)(r * 255.9)) << 24 | ((unsigned long)(g * 255.9)) << 16 | ((unsigned long)(b * 255.9)) << 8));
    return (unsigned long) (((unsigned long)(r * 255.9)) << 24 | ((unsigned long)(g * 255.9)) << 16 | ((unsigned long)(b * 255.9)) << 8);
}



void RainbowItem::readRainbowColors() {
    ifstream inputStream("rainbow+white.rgb", ifstream::in);
    int index = 0;
    string line;
    getline(inputStream, line);
    istringstream iss0(line);
    string text;
    iss0 >> text;
    iss0 >> size;
    colors = new element[size];
    for (int i = 0; i < size; i++) {
        colors[i].jump = &colors[i].rgb[0];
    }

    // Eat up two lines.
    getline(inputStream, line);
    getline(inputStream, line);

    while (getline(inputStream, line)) {
        istringstream iss(line);
        int r, g, b;
        iss >> r;
        iss >> g;
        iss >> b;
        colors[index].r = r;
        colors[index].g = g;
        colors[index].b = b;
        index++;
    }

    inputStream.close();
}



