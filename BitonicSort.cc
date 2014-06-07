
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Item.hh"
#include "RainbowItem.hh"
#include "Bmp.hh"

using namespace std;


template<class ITEM> class BitonicSort {
private:
    int num;
    ITEM** array;
    vector<ITEM**> records;
    int num_rec;
    void cmp_swap(int a, int b);
public:
    BitonicSort(const int n);
    ~BitonicSort();
    void sort();
    void sort_orig();
    void dump_array() const;
    void recordPos();
    void addDivider(const int val);
    int getNumRec() const { return num_rec; };
    void exportImage(const char* file);
};


template<class ITEM> void BitonicSort<ITEM>::dump_array() const {
    for (int i = 0; i < num; i++) {
        cout << array[i]->getNumber() << ((i < (num - 1)) ? " " : "");
    }
    cout << endl;
}


template<class ITEM> void BitonicSort<ITEM>::cmp_swap(int a, int b) {
    //cout << "cmp(array[" << a << "], array[" << b << "])   (" << array[a]->getNumber() << ", " << array[b]->getNumber() << ")";
    if (*array[a] > *array[b]) {
        ITEM* tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
        //cout << " swap!";
    }
    //cout << endl;
}


template<class ITEM> void BitonicSort<ITEM>::recordPos() {
    ITEM** rec = new ITEM*[num];
    for (int i = 0; i < num; i++) {
        rec[i] = array[i];
    }
    records.push_back(rec);
    num_rec++;
}


template<class ITEM> void BitonicSort<ITEM>::addDivider(const int val) {
    ITEM** rec = new ITEM*[num];
    ITEM* r = new ITEM(val);
    for (int i = 0; i < num; i++) {
        rec[i] = r;
    }
    records.push_back(rec);
    num_rec++;
}


template<class ITEM> void BitonicSort<ITEM>::exportImage(const char* file) {
    int height = num;
    int width = num_rec;
    Bmp bmp(width, height);

    // For BMP images, the data starts from the bottom left corner.
    for (int row = height - 1; row >= 0; row--) {
        for (typename vector<ITEM**>::const_iterator items = records.begin(); items != records.end(); items++) {
            unsigned char intenisity = (unsigned char) (*items)[row]->getNumber();
            bmp.append(intenisity, intenisity, intenisity);
        }
    }

    unsigned char *data = new unsigned char[bmp.getDataSize()];
    bmp.getData(data);
    ofstream bmpstream(file, std::ios::out | std::ios::binary);
    bmpstream.write((char *) data, bmp.getDataSize());
    bmpstream.close();
}


// The original algorithm.
template<class ITEM> void BitonicSort<ITEM>::sort_orig() {
    for (int chunk = 2; chunk <= num; chunk *= 2) {
        for (int offset = 0; offset < num; offset += chunk) {
            for (int a = 0; a < chunk / 2; a++) {
                int b = chunk - 1 - a;
                cmp_swap(a + offset, b + offset);
            }
            recordPos();
            for (int m = chunk / 2; m > 1; m /= 2) {
                for (int step = 0; step < chunk; step += m) {
                    for (int a = 0; a < m / 2; a++) {
                        int b = a + m / 2;
                        cmp_swap(step + a + offset, step + b + offset);
                    }
                }
            }
            recordPos();
        }
    }
}


// An algorithm that appears more parallel.
template<class ITEM> void BitonicSort<ITEM>::sort() {
    for (int chunk_size = 2; chunk_size <= num; chunk_size *= 2) {
        for (int a = 0; a < chunk_size / 2; a++) {
            int b = chunk_size - 1 - a;
            for (int offset = 0; offset < num; offset += chunk_size) {
                assert(a < b);
                cmp_swap(a + offset, b + offset);
            }
            recordPos();
        }
        //addDivider(255);
        for (int m = chunk_size / 2; m > 1; m /= 2) {
            int step = m / 2;
            for (int a = 0; a < step; a++) {
                int b = a + step;
                for (int offset = 0; offset < num; offset += m) {
                    assert(a < b);
                    cmp_swap(a + offset, b + offset);
                }
                recordPos();
            }
        }
        //addDivider(0);
    }
}


template<class ITEM> BitonicSort<ITEM>::BitonicSort(int n) {
    num = n;
    num_rec = 0;
    array = new ITEM*[num];
    for (int i = 0; i < num; i++) {
        array[i] = new ITEM();
    }
}


template<class ITEM> BitonicSort<ITEM>::~BitonicSort() {
    for (int i = 0; i < num; i++) {
        delete array[i];
    }
    delete [] array;
}


int main(int argc, char** argv) {
    int min_num = 0;
    int max_num = 256;
    int arg = 0;
    char* output_file = NULL;
    int num = 1 << 5;

    while (arg < argc) {
        if (strcmp(argv[arg], "-n") == 0) {
            num = atoi(argv[++arg]);
            // TODO: Add support for arbitrary positive integers.
        } else if (strcmp(argv[arg], "-o") == 0) {
            output_file = argv[++arg];
        } else if (strcmp(argv[arg], "-h") == 0) {
            printf("Usage:\n\tserial_bitonic_sort [-n NUMBER_OF_ELEMENTS]\n\n");
            exit(0);
        }
        arg++;
    }

    BitonicSort<Item> bs(num);

    for (int i = 0; i < 10; i++) {
        bs.recordPos();
    }

    bs.sort();

    for (int i = 0; i < 10; i++) {
        bs.recordPos();
    }

    if (output_file) {
        cout << "Calling exportImage(\"" << output_file << "\")" << endl;
        bs.exportImage(output_file);
    }

    return 0;
}

