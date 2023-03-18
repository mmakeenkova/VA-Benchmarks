#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "sim_api.h"


int* get_arr1(int size);
int* get_arr2(int size);
void accumulate_two_arrs(int *arr1, int *arr2, int size);

//idea: randomly fill arr1 with 1 or 0, if 1 is read, copy from 1, else copy from 2
void copy_on_one_test(int* arr1, int* arr2, int size) {
    for(int i=0; i<size; i++) {
        if (arr1[i] == 1) arr1[i] = arr2[i]; 
    }
}

//fill arr1 with 1 or 0 randomly
int* get_arr1(int size) {
    int *arr1 = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) arr1[i] = rand() % 2; 
    return arr1; 
}

//fill arr2 with random values
int* get_arr2(int size) {
    int *arr2 = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++) arr2[i] = rand(); 
    return arr2; 
}

int main(char *argv[]) {
    srand(time(NULL));
    int size = atoi(argv[1]);
    int reps = atoi(argv[2]); 

    int* arr1 = get_arr1(size); 
    int* arr2 = get_arr2(size); 

    SimRoiStart(); 
    for (int i=0; i<reps; i++) copy_on_one_test(arr1, arr2, size); 
    SimRoiEnd(); 

    free(arr1);
    free(arr2);

    return 0; 
}