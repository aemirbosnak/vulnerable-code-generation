//FormAI DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000 // Maximum size for array

// Function to generate random numbers between 0 and 1
double rand_float() {
    return (double) rand() / (double) RAND_MAX;
}

// Function to initialize array with random numbers
void init_array(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand_float();
    }
}

// Function to calculate sum of array elements using loop
double sum_array_loop(double *arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate sum of array elements using pointer arithmetic
double sum_array_ptr(double *arr, int n) {
    double sum = 0.0;
    double *ptr = arr; // Pointer to first element of array
    for (int i = 0; i < n; i++) {
        sum += *ptr++;
    }
    return sum;
}

// Function to calculate sum of array elements using array indexing
double sum_array_index(double *arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Main function to benchmark array sum functions
int main() {
    srand(time(NULL)); // Initialize random number generator
    double *arr = malloc(MAX_ARRAY_SIZE * sizeof(double)); // Declare and allocate array
    init_array(arr, MAX_ARRAY_SIZE); // Initialize array with random numbers
    
    clock_t start, end; // Declare clock variables
    double cpu_time_used; // Declare variable to store CPU time used
    
    // Benchmark loop version of sum_array function
    start = clock();
    double sum_loop = sum_array_loop(arr, MAX_ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Loop version of sum_array function: %f\n", sum_loop);
    printf("CPU time used: %f seconds\n", cpu_time_used);
    
    // Benchmark pointer version of sum_array function
    start = clock();
    double sum_ptr = sum_array_ptr(arr, MAX_ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Pointer version of sum_array function: %f\n", sum_ptr);
    printf("CPU time used: %f seconds\n", cpu_time_used);
    
    // Benchmark index version of sum_array function
    start = clock();
    double sum_index = sum_array_index(arr, MAX_ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Index version of sum_array function: %f\n", sum_index);
    printf("CPU time used: %f seconds\n", cpu_time_used);
    
    free(arr); // Free memory allocated for array
    
    return 0;
}