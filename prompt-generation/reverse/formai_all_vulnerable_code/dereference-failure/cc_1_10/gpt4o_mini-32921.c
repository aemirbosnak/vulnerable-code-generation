//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 8
#define MATRIX_SIZE 1024

typedef struct {
    int start_row;
    int end_row;
    int (*matrix_a)[MATRIX_SIZE];
    int (*matrix_b)[MATRIX_SIZE];
    int (*result_matrix)[MATRIX_SIZE];
} ThreadData;

void* multiply_matrices(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int (*matrix_a)[MATRIX_SIZE] = data->matrix_a;
    int (*matrix_b)[MATRIX_SIZE] = data->matrix_b;
    int (*result_matrix)[MATRIX_SIZE] = data->result_matrix;

    for (int i = data->start_row; i < data->end_row; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result_matrix[i][j] = 0; // Initialize the result matrix cell
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return NULL;
}

void initialize_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 10; // Random numbers between 0 to 9
        }
    }
}

void print_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Allocate memory for the matrices
    int (*matrix_a)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*matrix_b)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*result_matrix)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));

    if (matrix_a == NULL || matrix_b == NULL || result_matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    initialize_matrix(matrix_a);
    initialize_matrix(matrix_b);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    // Divide workload among threads
    int rows_per_thread = MATRIX_SIZE / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i + 1) * rows_per_thread;
        thread_data[i].matrix_a = matrix_a;
        thread_data[i].matrix_b = matrix_b;
        thread_data[i].result_matrix = result_matrix;

        // Create threads
        if (pthread_create(&threads[i], NULL, multiply_matrices, &thread_data[i]) != 0) {
            fprintf(stderr, "Thread creation failed\n");
            return EXIT_FAILURE;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the result (uncomment for large matrices)
    //print_matrix(result_matrix);

    // Free allocated memory
    free(matrix_a);
    free(matrix_b);
    free(result_matrix);

    return EXIT_SUCCESS;
}