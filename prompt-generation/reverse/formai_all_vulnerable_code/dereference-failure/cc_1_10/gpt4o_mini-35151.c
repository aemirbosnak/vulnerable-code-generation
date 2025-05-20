//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MATRIX_SIZE 1000
#define NUM_THREADS 4

typedef struct {
    int id;
    int (*matrixA)[MATRIX_SIZE];
    int (*matrixB)[MATRIX_SIZE];
    int (*result)[MATRIX_SIZE];
} thread_data_t;

void *multiply_matrices(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int id = data->id;
    int (*matrixA)[MATRIX_SIZE] = data->matrixA;
    int (*matrixB)[MATRIX_SIZE] = data->matrixB;
    int (*result)[MATRIX_SIZE] = data->result;

    int i, j, k;
    // Divide workload among threads
    int chunk_size = MATRIX_SIZE / NUM_THREADS;
    int start_row = id * chunk_size;
    int end_row = (id + 1) * chunk_size;

    for (i = start_row; i < end_row; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return NULL;
}

void initialize_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10; // random values between 0-9
        }
    }
}

void print_matrix(int (*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < 10; i++) { // Print only the first 10 rows for brevity
        for (int j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness

    // Allocate matrices on the heap
    int (*matrixA)[MATRIX_SIZE] = malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(int));
    int (*matrixB)[MATRIX_SIZE] = malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(int));
    int (*result)[MATRIX_SIZE] = malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(int));

    if (!matrixA || !matrixB || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize matrices
    initialize_matrix(matrixA);
    initialize_matrix(matrixB);

    // Create and launch threads
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i;
        thread_data[i].matrixA = matrixA;
        thread_data[i].matrixB = matrixB;
        thread_data[i].result = result;
        pthread_create(&threads[i], NULL, multiply_matrices, &thread_data[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the resulting matrix (for verification)
    printf("Resulting Matrix (first 10x10):\n");
    print_matrix(result);

    // Free allocated memory
    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}