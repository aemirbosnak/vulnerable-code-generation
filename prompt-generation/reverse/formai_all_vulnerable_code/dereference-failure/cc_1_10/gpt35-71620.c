//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main()
{
    double* arr1 = (double*)malloc(SIZE * sizeof(double));
    double* arr2 = (double*)malloc(SIZE * sizeof(double));
    double* arr3 = (double*)malloc(SIZE * sizeof(double));

    // Filling the arrays with random numbers
    srand(time(NULL));
    for(int i=0; i<SIZE; i++)
    {
        arr1[i] = (double)rand() / RAND_MAX;
        arr2[i] = (double)rand() / RAND_MAX;
    }

    clock_t start, end;

    // Benchmarking the multiplication loop
    start = clock();
    for(int i=0; i<SIZE; i++)
        arr3[i] = arr1[i] * arr2[i];
    end = clock();
    double time_mul = (double)(end - start) / CLOCKS_PER_SEC;

    // Benchmarking the addition loop
    start = clock();
    for(int i=0; i<SIZE; i++)
        arr3[i] = arr1[i] + arr2[i];
    end = clock();
    double time_add = (double)(end - start) / CLOCKS_PER_SEC;

    // Benchmarking the subtraction loop
    start = clock();
    for(int i=0; i<SIZE; i++)
        arr3[i] = arr1[i] - arr2[i];
    end = clock();
    double time_sub = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Benchmarking results:\n");
    printf("Multiplication loop: %.6lf seconds\n", time_mul);
    printf("Addition loop: %.6lf seconds\n", time_add);
    printf("Subtraction loop: %.6lf seconds\n", time_sub);

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}