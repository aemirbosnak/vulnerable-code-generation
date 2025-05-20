//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000 // size of array
#define MAX 100000 // maximum range of numbers
#define BSIZE 10 // size of each bucket

int main() {
    int i, j, n, max, min;
    int *array, *bucket;
    double start, end;

    srand(time(NULL));
    max = MAX;
    min = 0;

    // create an array of random integers
    array = (int *)malloc(sizeof(int) * SIZE);
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }

    // sort the array using bucket sort algorithm
    bucket = (int *)malloc(sizeof(int) * SIZE / BSIZE);
    for (i = 0; i < SIZE / BSIZE; i++) {
        bucket[i] = 0;
    }

    start = clock();
    for (i = 0; i < SIZE; i++) {
        j = array[i] / BSIZE;
        bucket[j]++;
    }

    for (i = 1; i < SIZE / BSIZE; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = SIZE - 1; i >= 0; i--) {
        j = array[i] / BSIZE;
        bucket[j]--;
        array[bucket[j] + j * BSIZE] = array[i];
    }

    end = clock();
    printf("Bucket Sort Algorithm took %lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // print the sorted array
    printf("Sorted Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    free(bucket);
    return 0;
}