//FormAI DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define NUM_ITERATIONS 10000000

/**
 * This program is a benchmarking example to compare the performance of two
 * functions that calculate the sum of an array of integers.
 */

// First function to calculate the sum of an integer array
int sum1(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Second function to calculate the sum of an integer array
int sum2(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += arr[i] + ((i + 1 < n) ? arr[i+1] : 0);
    }
    return sum;
}

int main() {
    int arr_size = 100000;
    int* arr = (int*) malloc(sizeof(int) * arr_size);

    // Initialize array with random values
    srand(0); // Set random seed to 0 for reproducibility
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand();
    }

    // Calculate sum1 using gettimeofday for benchmarking
    struct timeval te1;
    gettimeofday(&te1, NULL);
    int sum = 0;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sum = sum1(arr, arr_size);
    }
    struct timeval te2, res1;
    gettimeofday(&te2, NULL);
    timersub(&te2, &te1, &res1);
    double time1 = res1.tv_sec + (double)res1.tv_usec/1000000.0;

    printf("sum1: %d\n", sum);
    printf("Time taken by sum1: %lf seconds\n", time1);

    // Calculate sum2 using gettimeofday for benchmarking
    struct timeval te3;
    gettimeofday(&te3, NULL);
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sum = sum2(arr, arr_size);
    }
    struct timeval te4, res2;
    gettimeofday(&te4, NULL);
    timersub(&te4, &te3, &res2);
    double time2 = res2.tv_sec + (double)res2.tv_usec/1000000.0;

    printf("sum2: %d\n", sum);
    printf("Time taken by sum2: %lf seconds\n", time2);

    // Calculate speedup
    double speedup = time1 / time2;
    printf("Speedup of sum2 over sum1: %lf\n", speedup);

    free(arr);
    return 0;
}