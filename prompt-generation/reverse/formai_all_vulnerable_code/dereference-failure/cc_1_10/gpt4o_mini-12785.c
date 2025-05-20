//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 1024
#define NUM_THREADS 8

typedef struct {
    int id;
    int(*A)[MATRIX_SIZE];
    int(*B)[MATRIX_SIZE];
    int(*C)[MATRIX_SIZE];
} thread_data_t;

void* multiply_matrices(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int id = data->id;

    // Calculate start and end row for this thread
    int rows_per_thread = MATRIX_SIZE / NUM_THREADS;
    int start_row = id * rows_per_thread;
    int end_row = (id + 1) * rows_per_thread;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            data->C[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                data->C[i][j] += data->A[i][k] * data->B[k][j];
            }
        }
    }
    return NULL;
}

void initialize_matrix(int(*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10; // Fill matrix with random values
        }
    }
}

void print_matrix(int(*matrix)[MATRIX_SIZE]) {
    for (int i = 0; i < 10; i++) { // Printing just the first 10 rows for brevity
        for (int j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Allocate memory for the matrices
    int (*A)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*A));
    int (*B)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*B));
    int (*C)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*C));
    
    if (!A || !B || !C) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices A and B
    initialize_matrix(A);
    initialize_matrix(B);
    
    // Declare threads and thread data
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    // Create threads to perform matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i;
        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].C = C;
        pthread_create(&threads[i], NULL, multiply_matrices, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the resulting matrix C (for testing, printing just a part)
    printf("Resulting matrix C (first 10x10 block):\n");
    print_matrix(C);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}