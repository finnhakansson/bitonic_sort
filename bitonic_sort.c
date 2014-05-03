
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int num;


int generate_random_numbers(int num, int min_num, int max_num, int* array) {
    int interval = max_num - min_num;
    if (max_num < min_num) {
        return -1;
    }
    srand(10);
    for (int i = 0; i < num; i++) {
        int r = (rand() % interval) + min_num;
        array[i] = r;
    }
    return 0;
}


void output_array(int num, int* array) {
    for (int i = 0; i < num; i++) {
        printf("%d%s", array[i], (i < (num - 1)) ? " " : "");
    }
    printf("\n");
}


void cmp_swap(int a, int b, int* array) {
    if (array[a] > array[b]) {
        int tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
}


void bitonic_sort(int num, int* array) {
    for (int chunk = 2; chunk <= num; chunk *= 2) {
        for (int offset = 0; offset < num; offset += chunk) {
            for (int a = 0; a < chunk / 2; a++) {
                int b = chunk - 1 - a;
                cmp_swap(a + offset, b + offset, array);
            }
            for (int m = chunk / 2; m > 1; m /= 2) {
                for (int step = 0; step < chunk; step += m) {
                    for (int a = 0; a < m / 2; a++) {
                        int b = a + m / 2;
                        cmp_swap(step + a + offset, step + b + offset, array);
                    }
                }
            }
        }
    }
}


int main(int argc, char** argv) {
    int min_num = 0;
    int max_num = 256;
    int* array;
    int arg = 0;

    num = 1 << 5;

    while (arg < argc) {
        if (strcmp(argv[arg], "-n") == 0) {
            num = atoi(argv[++arg]);
        } else if (strcmp(argv[arg], "-h") == 0) {
            printf("Usage:\n\tserial_bitonic_sort [-n NUMBER_OF_ELEMENTS]\n\n");
            exit(0);
        }
        arg++;
    }

    array = (int*) malloc(num * sizeof(int));
    printf("Number of elements: %d\n", num);

    generate_random_numbers(num, min_num, max_num, array);
    output_array(num, array);

    bitonic_sort(num, array);
    output_array(num, array);

    free((void*) array);
    return 0;
}

