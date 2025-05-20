//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000 // size of the array
#define RANGE 1000000 // range of the numbers

int main() {
    int i, j, n, *array;
    double start_time, end_time;
    srand(time(NULL)); // seed the random number generator

    // allocate memory for the array
    array = (int *)malloc(SIZE * sizeof(int));

    // generate random numbers in the range [0, RANGE]
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % RANGE;
    }

    // print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // start timer
    start_time = clock();

    // sort the array using bucket sort
    for (i = 0; i < RANGE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (array[j] == i) {
                array[j] = -array[j]; // mark the element as visited
            }
        }
        for (j = 0; j < SIZE; j++) {
            if (array[j] == i) {
                array[j] = j; // store the index of the element in the array
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        array[array[i]] = i; // move the elements to their correct positions
    }

    // print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // stop timer
    end_time = clock();

    // calculate the time taken to sort the array
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %lf seconds\n", cpu_time_used);

    // free memory
    free(array);

    return 0;
}