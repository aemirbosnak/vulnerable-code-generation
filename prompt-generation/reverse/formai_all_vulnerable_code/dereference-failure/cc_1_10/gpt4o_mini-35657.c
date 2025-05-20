//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 1024 // Define size of the square matrix
#define MAX_THREAD 8     // Maximum number of threads

// Struct to hold thread arguments
typedef struct {
    int thread_id;
    int num_threads;
    int (*matrix_a)[MATRIX_SIZE];
    int (*matrix_b)[MATRIX_SIZE];
    int (*result)[MATRIX_SIZE];
} ThreadArgs;

void *multiply(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int row, col;

    // Calculate the range of rows this thread will handle
    int rows_per_thread = MATRIX_SIZE / args->num_threads;
    int start_row = args->thread_id * rows_per_thread;
    int end_row = (args->thread_id == args->num_threads - 1) ? MATRIX_SIZE : start_row + rows_per_thread;

    for (row = start_row; row < end_row; row++) {
        for (col = 0; col < MATRIX_SIZE; col++) {
            args->result[row][col] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                args->result[row][col] += args->matrix_a[row][k] * args->matrix_b[k][col];
            }
        }
    }

    return NULL;
}

void multiply_matrices(int (*matrix_a)[MATRIX_SIZE], int (*matrix_b)[MATRIX_SIZE], int (*result)[MATRIX_SIZE], int num_threads) {
    pthread_t threads[MAX_THREAD];
    ThreadArgs thread_args[MAX_THREAD];

    // Create threads for multiplication
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].num_threads = num_threads;
        thread_args[i].matrix_a = matrix_a;
        thread_args[i].matrix_b = matrix_b;
        thread_args[i].result = result;

        pthread_create(&threads[i], NULL, multiply, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void initialize_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10; // Random numbers between 0-9
        }
    }
}

void print_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int (*matrix_a)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*matrix_b)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*result)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));

    // Initialize random matrices
    initialize_matrix(matrix_a);
    initialize_matrix(matrix_b);

    // Perform matrix multiplication with multiple threads
    multiply_matrices(matrix_a, matrix_b, result, MAX_THREAD);
    
    // Uncomment below lines for debugging
    // printf("Matrix A:\n");
    // print_matrix(matrix_a);
    // printf("Matrix B:\n");
    // print_matrix(matrix_b);
    // printf("Result:\n");
    // print_matrix(result);

    // Free dynamically allocated memory
    free(matrix_a);
    free(matrix_b);
    free(result);

    return 0;
}