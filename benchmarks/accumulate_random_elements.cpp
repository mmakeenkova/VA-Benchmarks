#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "sim_api.h"

using namespace std;

int* get_arr1(int size);
void accumulate(int *arr, int size, int max);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int size = atoi(argv[1]);
    int max = atoi(argv[2]); 
    int reps = atoi(argv[3]); 

    int *arr = get_arr1(size); 

    SimRoiStart(); 
    for(int i=0; i<reps; i++) accumulate(arr, size, max); 
    SimRoiEnd(); 

    free(arr);
    return 0; 
}

int* get_arr1(int size) {
    int *arr1 = (int*) malloc(size * sizeof(int));
    //int arr1[size]; 
    for(int i=0; i<size; i++) arr1[i] = rand(); 
    return arr1; 
}

void accumulate(int *arr, int size, int max) {
    for(int i=0; i<size; i++) {
        int num_elements = rand() % max; 
        for(int j=0; j<num_elements; j++) arr[i] += arr[rand() % size]; 
    }
}