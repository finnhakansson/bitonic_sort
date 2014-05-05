
#include <string.h>
#include <iostream>
#include "Bmp.hh"

using namespace std;


#define BMP_HEADER_SIZE 54


Bmp::Bmp(int width, int height) {
    this->width = width;
    this->height = height;
    pad = (4 - (width * 3 % 4)) % 4;
    size = height * (width * 3 + pad) + BMP_HEADER_SIZE;
    data = new unsigned char[size];
    index = 0;
    horizontal_pos = 0;
    cout << "width: " << this->width << endl;
    cout << "height: " << this->height << endl;
    cout << "pad: " << pad << endl;
    cout << "size: " << size << endl;
    createHeader();
}


Bmp::~Bmp() {
    delete[] data;
}


void Bmp::append(unsigned char r, unsigned char g, unsigned char b) {
    data[index++] = r;
    data[index++] = g;
    data[index++] = b;
    if (++horizontal_pos == width) {
        for (int p = 0; p < pad; p++) {
            data[index++] = (unsigned char)0x00;
        }
        horizontal_pos = 0;
    }
}


int Bmp::getDataSize() const {
    return size;
}


unsigned char* Bmp::getData(unsigned char* buf) {
    if (buf) {
        memcpy(buf, data, size);
        return buf;
    } else {
        return data;
    }
}


void Bmp::createHeader() {
    memset(data, 0, BMP_HEADER_SIZE);
    cout << "Bmp::createHeader: size = " << size << endl;
    cout << "Bmp::createHeader: width = " << width << endl;
    cout << "Bmp::createHeader: height = " << height << endl;

    data[0] = (unsigned char) 0x42;
    data[1] = (unsigned char) 0x4d;
    data[2] = (unsigned char) ((size << 24) >> 24);
    data[3] = (unsigned char) ((size << 16) >> 24);
    data[4] = (unsigned char) ((size << 8) >> 24);
    data[5] = (unsigned char) ((size << 0) >> 24);

    data[10] = 14 + 40;

    data[14 + 0] = 40;

    data[14 + 4] = (unsigned char) ((width << 24) >> 24);
    data[14 + 5] = (unsigned char) ((width << 16) >> 24);
    data[14 + 6] = (unsigned char) ((width << 8) >> 24);
    data[14 + 7] = (unsigned char) ((width << 0) >> 24);
    data[14 + 8] = (unsigned char) ((height << 24) >> 24);
    data[14 + 9] = (unsigned char) ((height << 16) >> 24);
    data[14 + 10] = (unsigned char) ((height << 8) >> 24);
    data[14 + 11] = (unsigned char) ((height << 0) >> 24);

    data[14 + 12] = 1; // Number of planes
    data[14 + 14] = 24;
    index = BMP_HEADER_SIZE;
}


