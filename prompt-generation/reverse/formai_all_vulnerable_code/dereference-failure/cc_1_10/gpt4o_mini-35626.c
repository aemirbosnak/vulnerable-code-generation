//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Function to fill the array with random numbers
void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Function to perform a basic bubble sort
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the average of an array
double calculate_average(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

// Function to print the array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Benchmarking function to time the sorting algorithm
void benchmark_sort(void (*sort_func)(int*, int), int *array, int size) {
    clock_t start_time = clock();
    sort_func(array, size);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorting took %f seconds.\n", time_taken);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    
    // Fill the array with random numbers
    fill_array(array, ARRAY_SIZE);
    
    // Print the unsorted array
    printf("Unsorted Array:\n");
    print_array(array, ARRAY_SIZE);
    
    // Benchmark the sorting function
    printf("Starting benchmark for bubble sort...\n");
    benchmark_sort(bubble_sort, array, ARRAY_SIZE);
    
    // Calculate the average of sorted values
    double average = calculate_average(array, ARRAY_SIZE);
    printf("Average of sorted values: %f\n", average);
    
    // Print sorted array
    printf("Sorted Array:\n");
    print_array(array, ARRAY_SIZE);
    
    // Free allocated memory
    free(array);
    
    return 0;
}