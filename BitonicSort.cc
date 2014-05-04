
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>
#include "Item.hh"

using namespace std;


template<class ITEM> class BitonicSort {
private:
    int num;
    ITEM** array;
    void cmp_swap(int a, int b);
public:
    BitonicSort(const int n);
    ~BitonicSort();
    void sort();
    void output_array() const;
};


template<class ITEM> void BitonicSort<ITEM>::output_array() const {
    for (int i = 0; i < num; i++) {
        printf("%d%s", array[i]->getNumber(), (i < (num - 1)) ? " " : "");
    }
    printf("\n");
}


template<class ITEM> void BitonicSort<ITEM>::cmp_swap(int a, int b) {
    if (*array[a] > *array[b]) {
        ITEM* tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
}


template<class ITEM> void BitonicSort<ITEM>::sort() {
    for (int chunk = 2; chunk <= num; chunk *= 2) {
        for (int offset = 0; offset < num; offset += chunk) {
            for (int a = 0; a < chunk / 2; a++) {
                int b = chunk - 1 - a;
                cmp_swap(a + offset, b + offset);
            }
            for (int m = chunk / 2; m > 1; m /= 2) {
                for (int step = 0; step < chunk; step += m) {
                    for (int a = 0; a < m / 2; a++) {
                        int b = a + m / 2;
                        cmp_swap(step + a + offset, step + b + offset);
                    }
                }
            }
        }
    }
}


template<class ITEM> BitonicSort<ITEM>::BitonicSort(int n) {
    num = n;
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

    int num = 1 << 5;

    while (arg < argc) {
        if (strcmp(argv[arg], "-n") == 0) {
            num = atoi(argv[++arg]);
            // TODO: Add support for arbitrary positive integers.
        } else if (strcmp(argv[arg], "-h") == 0) {
            printf("Usage:\n\tserial_bitonic_sort [-n NUMBER_OF_ELEMENTS]\n\n");
            exit(0);
        }
        arg++;
    }

    BitonicSort<Item> bs(num);
    cout << "Number of elements: " << num << endl;

    bs.output_array();
    bs.sort();
    bs.output_array();
    return 0;
}

