#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int stride = 2;
    int array_size = 100;
    strided_read(array_size, stride);
    return 0;
}

void strided_read (int size, int stride) {
    int num_allocs = 10000;
    for (int i = 0; i < num_allocs; i++) {
        int* buffer = (int*)malloc(sizeof(int)*size);
        for (int j = 0; j < size; j+=stride) {
           buffer[j] = 1;
        }
        free(buffer);
    }
}