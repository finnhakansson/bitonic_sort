
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// g++ -std=c++11 -o x ReadNumbers.cc

unsigned char** numbers;


void readNumbers() {
    ifstream inputStream("rainbow+white.rgb", ifstream::in);
    numbers = (unsigned char**) new unsigned int[237];
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
        iss >> numbers[index][0];
        iss >> numbers[index][1];
        iss >> numbers[index][2];
    }
    inputStream.close();
}


int main(int argc, char** argv) {
    readNumbers();
    for (int i = 0; i < 237; i++) {
        cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;
    }
}

