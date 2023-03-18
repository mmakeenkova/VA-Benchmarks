#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void regular_access() {
    int size = 100;
    int num_allocs = 10000;
    for (int i = 0; i < num_allocs; i++) {
        int* buffer = (int*)malloc(sizeof(int)*size);
        for (int j = 0; j < size; j++) {
           buffer[j] = 1;
        }
        free(buffer);
    }
}

int main(int argc, char** argv) {
    regular_access();
    return 0;
}