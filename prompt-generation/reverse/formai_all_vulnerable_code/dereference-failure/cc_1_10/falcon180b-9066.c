//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

double *array1, *array2;
int size;

void init_array(int s){
    size = s;
    array1 = (double *) malloc(size * sizeof(double));
    array2 = (double *) malloc(size * sizeof(double));
    for(int i=0; i<size; i++){
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }
}

void print_array(double *arr, int s){
    for(int i=0; i<s; i++){
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void add_arrays(double *arr1, double *arr2, double *res, int s){
    for(int i=0; i<s; i++){
        res[i] = arr1[i] + arr2[i];
    }
}

void multiply_arrays(double *arr1, double *arr2, double *res, int s){
    for(int i=0; i<s; i++){
        res[i] = arr1[i] * arr2[i];
    }
}

int main(){
    int size = MAX_SIZE;
    init_array(size);

    double *result1 = (double *) malloc(size * sizeof(double));
    double *result2 = (double *) malloc(size * sizeof(double));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    add_arrays(array1, array2, result1, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for addition: %f seconds\n", cpu_time_used);

    start = clock();
    multiply_arrays(array1, array2, result2, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for multiplication: %f seconds\n", cpu_time_used);

    print_array(result1, size);
    print_array(result2, size);

    free(array1);
    free(array2);
    free(result1);
    free(result2);

    return 0;
}