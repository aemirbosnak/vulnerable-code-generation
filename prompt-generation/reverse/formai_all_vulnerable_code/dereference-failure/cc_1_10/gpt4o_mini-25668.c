//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Generates a random number from 0 to 9999
    }
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void benchmark_sorting(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    generate_random_array(arr, size);
    
    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting %d elements took: %f seconds\n", size, time_spent);
    
    free(arr);
}

void benchmark_factorial(int n) {
    clock_t start = clock();
    unsigned long long result = factorial(n);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Calculating factorial of %d took: %f seconds. Result: %llu\n", n, time_spent, result);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    printf("Benchmarking tasks:\n");
    
    int sort_sizes[] = {1000, 5000, 10000};
    for (int i = 0; i < 3; i++) {
        benchmark_sorting(sort_sizes[i]);
    }

    int factorial_numbers[] = {10, 15, 20};
    for (int i = 0; i < 3; i++) {
        benchmark_factorial(factorial_numbers[i]);
    }

    return 0;
}