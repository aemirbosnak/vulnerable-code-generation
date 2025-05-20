//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Get a random number between min and max inclusive
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Generate a random array of size n with elements between min and max
int *rand_array(int n, int min, int max) {
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand_int(min, max);
    }
    return arr;
}

// Benchmark a function f with input size n
double benchmark(int n, int (*f)(int)) {
    clock_t start = clock();
    f(n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Find the maximum element in an array of size n
int find_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Find the minimum element in an array of size n
int find_min(int *arr, int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Array sizes to test
    int sizes[] = {10000, 100000, 1000000};

    // Benchmarking loop
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        int n = sizes[i];

        // Generate random array
        int *arr = rand_array(n, 0, 100);

        // Benchmark find_max
        double find_max_time = benchmark(n, find_max);

        // Benchmark find_min
        double find_min_time = benchmark(n, find_min);

        // Print results
        printf("Array size: %d\n", n);
        printf("find_max time: %.6f seconds\n", find_max_time);
        printf("find_min time: %.6f seconds\n\n", find_min_time);

        // Free memory
        free(arr);
    }

    return 0;
}