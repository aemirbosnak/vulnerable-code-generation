//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate an array of random numbers
int* generate_random_array(int size, int min, int max) {
    int* arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand_range(min, max);
    }
    return arr;
}

// Function to print an array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using bubble sort
void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort an array using selection sort
void selection_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to sort an array using insertion sort
void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to benchmark the sorting algorithms
void benchmark_sorting_algorithms(int size, int min, int max, int num_iterations) {
    // Generate an array of random numbers
    int* arr = generate_random_array(size, min, max);

    // Benchmark bubble sort
    clock_t start = clock();
    for (int i = 0; i < num_iterations; i++) {
        bubble_sort(arr, size);
    }
    clock_t end = clock();
    double bubble_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Benchmark selection sort
    start = clock();
    for (int i = 0; i < num_iterations; i++) {
        selection_sort(arr, size);
    }
    end = clock();
    double selection_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Benchmark insertion sort
    start = clock();
    for (int i = 0; i < num_iterations; i++) {
        insertion_sort(arr, size);
    }
    end = clock();
    double insertion_sort_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Sorting Algorithms Benchmark:\n");
    printf("Array size: %d\n", size);
    printf("Number of iterations: %d\n", num_iterations);
    printf("Bubble sort time: %f seconds\n", bubble_sort_time);
    printf("Selection sort time: %f seconds\n", selection_sort_time);
    printf("Insertion sort time: %f seconds\n", insertion_sort_time);

    // Free the allocated memory
    free(arr);
}

int main() {
    // Set the random seed
    srand(time(0));

    // Benchmark the sorting algorithms with different parameters
    benchmark_sorting_algorithms(10000, 0, 10000, 100);
    benchmark_sorting_algorithms(50000, 0, 50000, 100);
    benchmark_sorting_algorithms(100000, 0, 100000, 100);

    return 0;
}