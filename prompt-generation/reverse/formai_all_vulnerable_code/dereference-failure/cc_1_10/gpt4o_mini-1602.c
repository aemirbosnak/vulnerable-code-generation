//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the sum of an array
void calculate_sum(int *arr, int n, long long *sum) {
    *sum = 0;
    for (int i = 0; i < n; i++) {
        *sum += arr[i];
    }
}

// Function to calculate the average of an array
void calculate_average(int *arr, int n, double *avg) {
    long long sum;
    calculate_sum(arr, n, &sum);
    *avg = (double)sum / n;
}

// Function to generate a random array
void generate_random_array(int *arr, int n, int max_value) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_value;
    }
}

// Function to benchmark the performance of the sum calculation
void benchmark_sum(int *arr, int n) {
    long long sum;
    clock_t start, end;

    start = clock();
    calculate_sum(arr, n, &sum);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sum: %lld, Time taken for sum: %f seconds\n", sum, time_taken);
}

// Function to benchmark the performance of the average calculation
void benchmark_average(int *arr, int n) {
    double avg;
    clock_t start, end;

    start = clock();
    calculate_average(arr, n, &avg);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Average: %f, Time taken for average: %f seconds\n", avg, time_taken);
}

// Function to benchmark both sum and average calculations
void benchmark_operations(int *arr, int n) {
    printf("Benchmarking operations for array size: %d\n", n);
    benchmark_sum(arr, n);
    benchmark_average(arr, n);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if the user provided an array size
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_elements> <max_random_value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int max_value = atoi(argv[2]);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the random array
    generate_random_array(arr, n, max_value);

    // Benchmark the sum and average calculations
    benchmark_operations(arr, n);

    // Free the allocated memory
    free(arr);
    return EXIT_SUCCESS;
}