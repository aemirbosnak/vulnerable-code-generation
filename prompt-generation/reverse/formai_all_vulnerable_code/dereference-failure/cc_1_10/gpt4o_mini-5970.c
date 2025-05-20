//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 4 // Change this for different sizes
#define NUM_THREADS 4 // Number of threads

typedef struct {
    int id;
    int **A;
    int **B;
    int **result;
    int row_start;
    int row_end;
} ThreadData;

void *multiply_matrices(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->row_start; i < data->row_end; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            data->result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                data->result[i][j] += data->A[i][k] * data->B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

void print_matrix(int **matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **allocate_matrix() {
    int **matrix = (int **)malloc(MATRIX_SIZE * sizeof(int *));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **A = allocate_matrix();
    int **B = allocate_matrix();
    int **result = allocate_matrix();

    // Initializing matrices A and B with random values
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = rand() % 10; // Random values between 0 and 9
            B[i][j] = rand() % 10;
        }
    }

    printf("Matrix A:\n");
    print_matrix(A);
    printf("\nMatrix B:\n");
    print_matrix(B);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int rows_per_thread = MATRIX_SIZE / NUM_THREADS;

    // Create threads for matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i;
        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].result = result;
        thread_data[i].row_start = i * rows_per_thread;
        thread_data[i].row_end = (i + 1) * rows_per_thread;

        if (i == NUM_THREADS - 1) {
            thread_data[i].row_end = MATRIX_SIZE; // Last thread handles any remaining rows
        }

        pthread_create(&threads[i], NULL, multiply_matrices, (void *)&thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nResultant Matrix:\n");
    print_matrix(result);

    // Clean up
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);

    return 0;
}