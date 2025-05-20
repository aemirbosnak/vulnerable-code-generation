//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a macro to measure the elapsed time
#define START_TIME() \
    clock_t start = clock();
    
#define END_TIME(msg) \
    clock_t end = clock(); \
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; \
    printf("%s: %f seconds\n", msg, time_spent);

// Function to sample the performance of matrix multiplication
void matrix_multiplication(int size) {
    // Dynamically allocate matrices
    int **A = malloc(size * sizeof(int *));
    int **B = malloc(size * sizeof(int *));
    int **C = malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        A[i] = malloc(size * sizeof(int));
        B[i] = malloc(size * sizeof(int));
        C[i] = malloc(size * sizeof(int));
    }

    // Initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0; // Initialize C to 0
        }
    }

    // Start timing matrix multiplication
    START_TIME();

    // Perform matrix multiplication
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // End timing and output results
    END_TIME("Matrix Multiplication Time");

    // Clean up memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

// Function to sample the performance of calculating pi using the Monte Carlo method
void monte_carlo_pi(int iterations) {
    int inside_circle = 0;

    START_TIME();

    for (int i = 0; i < iterations; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (sqrt(x * x + y * y) <= 1.0) {
            inside_circle++;
        }
    }

    double pi = (double)inside_circle / iterations * 4.0;
    END_TIME("Monte Carlo Pi Estimation Time");
    printf("Estimated value of π: %f\n", pi);
}

// Main function to orchestrate benchmarking
int main() {
    int matrix_size = 500; // Matrix size for multiplication
    int monte_carlo_iterations = 1000000; // Iterations for pi estimation

    printf("Benchmarking Matrix Multiplication with size: %d\n", matrix_size);
    matrix_multiplication(matrix_size);

    printf("\nBenchmarking Monte Carlo Pi estimation with iterations: %d\n", monte_carlo_iterations);
    monte_carlo_pi(monte_carlo_iterations);

    return 0;
}