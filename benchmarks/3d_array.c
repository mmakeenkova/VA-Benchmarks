#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char** argv) {
    int x = 100;
    int y = 100;
    int z = 100;
    test_3d_array(x, y, z); 
    return 0;
}

void test_3d_array(int x, int y, int z) {
    int ***data = alloc_data(x, y, z); 
    if (data == NULL) return EXIT_FAILURE;

    for (int i=0; i < x; ++i)
        for (int j=0; j < y; ++j)
            for (int k=0; k < z; ++k)
                data[i][j][k] = rand();

    //printf("%d\n", data[1][2][1]);
    free_data(data, x, y);
    return 0;
}

int ***alloc_data(int x, int y, int z) {
    int *** p; 
    p = malloc(x * sizeof * p); 
    if (p == NULL) {
        perror("malloc x"); 
        return NULL; 
    }

    for (int i=0; i < x; ++i) {
        p[i] = NULL; 
        p[i] = malloc(y * sizeof *p[i]); 
        if (p[i] == NULL) {
            perror("malloc y"); 
            free_data(p, x, y); 
            return NULL; 
        }
    }
    for(int i=0; i<x; ++i) {
        for(int j=0; j<y; j++) {
            p[i][j] = malloc(z * sizeof *p[i][j]); 
            if (p[i][j] == NULL) {
                perror("malloc z"); 
                free_data(p, x, y); 
                return NULL; 
            }
        }
    }
    return p; 
}

void free_data(int ***data, int x, int y) {
    for (int i=0; i < x; ++i) {
        if (data[i] != NULL) {
            for (int j=0; j < y; ++j)
                free(data[i][j]);
            free(data[i]);
        }
    }
    free(data);
}