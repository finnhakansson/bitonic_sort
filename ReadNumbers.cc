
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// g++ -std=c++11 -o x ReadNumbers.cc

unsigned int* numbers;


void readNumbers(const char* filename) {
    ifstream inputStream(filename, ifstream::in);
    numbers = new unsigned int[237];
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
        iss >> ((unsigned char[4]) numbers[index])[0];
        iss >> ((unsigned char[4]) numbers[index])[1];
        iss >> ((unsigned char[4]) numbers[index])[2];
    }
    inputStream.close();
}


int main(int argc, char** argv) {
    readNumbers("rainbow+white.rgb");
    for (int i = 0; i < 237; i++) {
        //cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;
        cout << ((unsigned char[4]) numbers[i])[0] << " " << ((unsigned char[4]) numbers[i])[1] << " " << ((unsigned char[4]) numbers[i])[2] << endl;
    }
}

