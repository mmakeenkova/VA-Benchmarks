#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "sim_api.h"

using namespace std;

int* get_arr1(int size);
int* get_arr2(int size);
void accumulate_two_arrs(int *arr1, int *arr2, int size);


int main(char *argv[]) {
    srand(time(NULL));

    int size = atoi(argv[1]);
    int reps = atoi(argv[2]); 

    int *arr1 = get_arr1(size); 
    int *arr2 = get_arr2(size); 

    SimRoiStart(); 
    for (int i=0; i<reps; i++) {
        accumulate_two_arrs(arr1, arr2, size); 
    }
    SimRoiEnd(); 

    free(arr1);
    free(arr2);
    
    return 0; 
}

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

void accumulate_two_arrs(int *arr1, int *arr2, int size) {
    for(int i=0; i<size; i++) {
        int end_index = arr1[i]; 
        for(int j=0; j<end_index; j++) {
            arr1[i] += arr2[j]; 
        }
    }
}