//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Benchmarking function
double benchmark(void (*func)(int *), int *arr, int n) {
    clock_t start, end;
    double time_taken;

    // Warm up the function
    func(arr);

    start = clock();
    
    for (int i = 0; i < n; i++) {
        func(arr);
    }
    
    end = clock();
    time_taken = (end - start) / (double)CLOCKS_PER_SEC;
    
    return time_taken;
}

// Function to be benchmarked
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 10000;
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Initialize the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    // Benchmark the bubble sort function
    double time_taken = benchmark(bubble_sort, arr, n);

    printf("Time taken to sort %d elements using bubble sort: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}