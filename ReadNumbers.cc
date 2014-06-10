
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// g++ -std=c++11 -o x ReadNumbers.cc

int size;
unsigned int* numbers;


class Rgb
{
public:
    unsigned char rgb[3];
    unsigned char& r;
    unsigned char& g;
    unsigned char& b;
    Rgb() : r(rgb[0]), g(rgb[1]), b(rgb[2]) { rgb[0] = rgb[1] = rgb[2] = 0; }
    int sum() { return r + g + b; }
    unsigned char& operator[] (int i) { return rgb[i]; }
};


void readNumbers(const char* filename) {
    ifstream inputStream(filename, ifstream::in);
    int index = 0;
    string line;
    getline(inputStream, line);
    istringstream iss0(line);
    string n;
    iss0 >> n;
    iss0 >> size;
    numbers = new unsigned int[size];
    getline(inputStream, line);
    getline(inputStream, line);
    while (getline(inputStream, line)) {
        istringstream iss(line);
        unsigned int r, g, b;
        iss >> r;
        iss >> g;
        iss >> b;
        numbers[index++] = (r << 24) | (g << 16) | (b << 8);
    }
    inputStream.close();
}


int main(int argc, char** argv) {
    readNumbers("rainbow+white.rgb");
    for (int i = 0; i < size; i++) {
        cout << " " << (numbers[i] >> 24) << " " << ((numbers[i] >> 16) & 0xff) << " " << ((numbers[i] >> 8) & 0xff) << endl;
    }
}

