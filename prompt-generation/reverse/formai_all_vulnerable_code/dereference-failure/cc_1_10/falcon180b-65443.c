//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10000
#define MAX_VALUE 1000000
#define MIN_VALUE -1000000

int main() {
    int i, j, k;
    double sum, avg, max, min, range;
    double *arr;
    srand(time(NULL));

    arr = (double *) malloc(SIZE * sizeof(double));

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    printf("Random array of %d elements:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("%f ", arr[i]);
    }

    printf("\n");

    sum = 0.0;
    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    avg = sum / SIZE;
    printf("Average: %f\n", avg);

    max = arr[0];
    min = arr[0];
    for (i = 1; i < SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min;
    printf("Range: %f\n", range);

    free(arr);
    return 0;
}