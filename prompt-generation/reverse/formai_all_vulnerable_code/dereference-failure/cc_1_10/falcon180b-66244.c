//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 10000000

int main(int argc, char **argv) {
    int i, j, k;
    int *arr;
    long int start, end;

    // Allocate memory for the array
    arr = (int *) malloc(MAX_NUM * sizeof(int));

    // Initialize the array with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 100;
    }

    // Perform different operations on the array
    start = clock();
    for (i = 0; i < MAX_NUM; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            k = arr[i] + arr[j];
        }
    }
    end = clock();
    printf("Time taken for addition: %ld ms\n", (end - start));

    start = clock();
    for (i = 0; i < MAX_NUM; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            k = arr[i] * arr[j];
        }
    }
    end = clock();
    printf("Time taken for multiplication: %ld ms\n", (end - start));

    start = clock();
    for (i = 0; i < MAX_NUM; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            k = arr[i] - arr[j];
        }
    }
    end = clock();
    printf("Time taken for subtraction: %ld ms\n", (end - start));

    // Free the memory allocated for the array
    free(arr);
    return 0;
}