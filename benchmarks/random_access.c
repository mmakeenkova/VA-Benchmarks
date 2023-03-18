#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    random_access(100);
    return 0;
}

void random_access(int size) {
    int num_allocs = 10000;
    for (int i = 0; i < num_allocs; i++) {
        int* buffer = (int*)malloc(sizeof(int)*size);
        for (int j = 0; j < size; j++) {
            int randomIndex = rand() % size;
            buffer[randomIndex] = j;
        }
        free(buffer);
    }
}
