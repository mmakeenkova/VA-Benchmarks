#include <stdlib.h>
#include <stdio.h>
#include "../sniper/include/sim_api.h"


int main(int argc, char** argv) {
    int size = atoi(argv[1]);
    int max = num_allocs(argv[2]); 
    random_access_two_arrays(size, num_allocs);
    return 0;
}

void random_access_two_arrays(int size, int num_allocs) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < num_allocs; i++) {
        int* buffer1 = (int*)malloc(sizeof(int)*size);
        int* buffer2 = (int*)malloc(sizeof(int)*size);
        for (int j = 0; j < size; j++) {
            int random_value = rand() % size;
            buffer1[j] = random_value;
        }

        SimRoiStart(); 
        for (int j = 0; j < size; j++) {
            buffer2[buffer1[j]] = 1; 
        }
        SimRoiEnd();

        free(buffer1);
        free(buffer2);
    }
}