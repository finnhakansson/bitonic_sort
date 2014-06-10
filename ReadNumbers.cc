
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// g++ -std=c++11 -o x ReadNumbers.cc


class Rgb
{
public:
    unsigned char rgb[3];
    //unsigned char& r = rgb[0];
    //unsigned char& g = rgb[1];
    //unsigned char& b = rgb[2];
    Rgb() { rgb[0] = rgb[1] = rgb[2] = 0; }
    //Rgb() : r(rgb[0]), g(rgb[1]), b(rgb[2]) { rgb[0] = rgb[1] = rgb[2] = 0; }
    //Rgb() : r(rgb[0]), g(rgb[1]), b(rgb[2]) { }
    //Rgb(int r0, int g0, int b0) : r(rgb[0]), g(rgb[1]), b(rgb[2]) { rgb[0] = (unsigned char)r0; rgb[1] = (unsigned char)g0; rgb[2] = (unsigned char)b0; }
    unsigned char& operator[] (int i) { return rgb[i]; }
    int r() const { return (int) rgb[0]; }
    void r(int v) { rgb[0] = (unsigned char) v; }
    int g() const { return (int) rgb[1]; }
    void g(int v) { rgb[1] = (unsigned char) v; }
    int b() const { return (int) rgb[2]; }
    void b(int v) { rgb[2] = (unsigned char) v; }
};


int size;
Rgb* colors;


void readNumbers(const char* filename) {
    ifstream inputStream(filename, ifstream::in);
    int index = 0;
    string line;
    getline(inputStream, line);
    istringstream iss0(line);
    string text;
    iss0 >> text;
    iss0 >> size;
cout << size << endl;
    colors = new Rgb[size];

    // Eat up two lines.
    getline(inputStream, line);
    getline(inputStream, line);

    while (getline(inputStream, line)) {
        istringstream iss(line);
        int r, g, b;
        iss >> r;
        iss >> g;
        iss >> b;
cout << r << ", " << g << ", " << b << endl;
        colors[index].r(r);
        colors[index].g(g);
        colors[index].b(b);
        //iss >> colors[index].r;
        //iss >> colors[index].g;
        //iss >> colors[index].b;
    }

    inputStream.close();
}


int main(int argc, char** argv) {
    readNumbers("rainbow+white.rgb");
    for (int i = 0; i < size; i++) {
        cout << colors[i].r() << " " << colors[i].g() << " " << colors[i].b() << endl;
    }
}

