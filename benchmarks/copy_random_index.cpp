#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "sim_api.h"




//fill arr1 with random indices 
int* get_arr1(int size) {
    int *arr1 = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) arr1[i] = rand() % size; 
    return arr1; 
}

//fill arr2 with random values
int* get_arr2(int size) {
    int *arr2 = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) arr2[i] = rand(); 
    return arr2; 
}

//idea: access copy entry of arr2 to arr1 based on index given in arr1
void random_array_acees(int* arr1, int* arr2, int size) {
    for(int i=0; i<size; i++) arr1[i] = arr2[arr1[i]]; 
}

int main(char *argv[]) {
    srand(time(NULL));
    
    int size = atoi(argv[1]);
    int num_iter = atoi(argv[2]); 

    int* arr1 = get_arr1(size); 
    int* arr2 = get_arr2(size); 

    SimRoiStart(); 
    for(int i=0; i<num_iter; i++) {
        random_array_acees(arr1, arr2, size); 
    }
    SimRoiEnd(); 

    free(arr1);
    free(arr2);
    return 0; 
}