#include <iostream>
#include <stdlib.h> 
#include <time.h>

#include "sim_api.h"



//fill arr with random values up tp 100
int* get_arr(int size, int max) {
    int *arr = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) arr[i] = rand() % max; 
    return arr; 
}

void filter_array_elements(int *arr1, int *arr2, int size, int pred) {
    for(int i=0; i<size; i++) {
        if (arr1[i] > pred) arr1[i] = arr2[i]; 
        else arr1[i] = (arr2[i] + rand()) % size; 
    }
}

int main(char *argv[]) {
    srand(time(NULL));
    
    int size = atoi(argv[1]);
    int max = atoi(argv[2]);
    int pred = atoi(argv[3]);
    int reps = atoi(argv[4]); 

    int* arr1 = get_arr(size, max); 
    int* arr2 = get_arr(size, max); 

    SimRoiStart(); 
    for (int i=0; i<reps; i++) filter_array_elements(arr1, arr2, size, pred); 
    SimRoiEnd(); 

    free(arr1); 
    free(arr2); 
    return 0; 
}