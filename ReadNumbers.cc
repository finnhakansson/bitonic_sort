
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// g++ -std=c++11 -o x ReadNumbers.cc


class Rgb
{
private:
    unsigned char rgb[3];
public:
    Rgb() { rgb[0] = rgb[1] = rgb[2] = 0; }
    Rgb(unsigned char r, unsigned char g, unsigned char b) { rgb[0] = r; rgb[1] = g; rgb[2] = b; }
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
        colors[index].r(r);
        colors[index].g(g);
        colors[index].b(b);
        index++;
    }

    inputStream.close();
}


int main(int argc, char** argv) {
    readNumbers("rainbow+white.rgb");
    for (int i = 0; i < size; i++) {
        cout << colors[i].r() << " " << colors[i].g() << " " << colors[i].b() << endl;
    }
}

