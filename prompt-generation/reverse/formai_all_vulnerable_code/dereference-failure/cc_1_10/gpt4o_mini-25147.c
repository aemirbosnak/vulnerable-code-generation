//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MATRIX_SIZE 512
#define CHUNK_SIZE (MATRIX_SIZE / NUM_THREADS)

// Function to initialize a matrix with random values
void initialize_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    srand(time(NULL));  // Seed the random number generator
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 100;  // Random value between 0-99
        }
    }
}

// Function to print a matrix
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Structure to hold parameters for each thread
typedef struct {
    int (*A)[MATRIX_SIZE];
    int (*B)[MATRIX_SIZE];
    int (*C)[MATRIX_SIZE];
    int start_row;
    int end_row;
} ThreadParams;

// Function to multiply a chunk of the matrix
void *matrix_multiply_chunk(void *params) {
    ThreadParams *p = (ThreadParams *)params;
    int (*A)[MATRIX_SIZE] = p->A;
    int (*B)[MATRIX_SIZE] = p->B;
    int (*C)[MATRIX_SIZE] = p->C;

    // Perform matrix multiplication on the given chunk
    for (int i = p->start_row; i < p->end_row; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0;  // Initialize the result cell
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

// Main function
int main() {
    // Allocate matrices A, B, and C
    int (*A)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*B)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));
    int (*C)[MATRIX_SIZE] = malloc(sizeof(int[MATRIX_SIZE][MATRIX_SIZE]));

    // Initialize matrices A and B
    initialize_matrix(A);
    initialize_matrix(B);

    printf("Matrix A:\n");
    print_matrix(A);
    printf("\nMatrix B:\n");
    print_matrix(B);

    // Create threads
    pthread_t threads[NUM_THREADS];
    ThreadParams thread_params[NUM_THREADS];

    // Divide work among threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_params[i].A = A;
        thread_params[i].B = B;
        thread_params[i].C = C;
        thread_params[i].start_row = i * CHUNK_SIZE;
        thread_params[i].end_row = (i + 1) * CHUNK_SIZE;
        pthread_create(&threads[i], NULL, matrix_multiply_chunk, &thread_params[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nMatrix C (Result of A x B):\n");
    print_matrix(C);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}