//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 1024
#define NUM_THREADS 16

// Structure for passing arguments to the thread
typedef struct {
    double (*a)[MATRIX_SIZE];
    double (*b)[MATRIX_SIZE];
    double (*result)[MATRIX_SIZE];
    int start_row;
    int end_row;
} ThreadData;

// Function for matrix multiplication
void* multiply_matrices(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            data->result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                data->result[i][j] += data->a[i][k] * data->b[k][j];
            }
        }
    }
    pthread_exit(0);
}

int main() {
    double (*matrix_a)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*matrix_a));
    double (*matrix_b)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*matrix_b));
    double (*result)[MATRIX_SIZE] = malloc(MATRIX_SIZE * sizeof(*result));

    if (!matrix_a || !matrix_b || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }

    // Create threads for multiplication
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int rows_per_thread = MATRIX_SIZE / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].a = matrix_a;
        thread_data[i].b = matrix_b;
        thread_data[i].result = result;
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i == NUM_THREADS - 1) ? MATRIX_SIZE : thread_data[i].start_row + rows_per_thread;

        if (pthread_create(&threads[i], NULL, multiply_matrices, &thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Print the result matrix (optional)
    /*
    printf("Result matrix:\n");
    for (int i = 0; i < 10; i++) { // print only the first 10 rows for brevity
        for (int j = 0; j < 10; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }
    */

    // Clean up
    free(matrix_a);
    free(matrix_b);
    free(result);

    printf("Matrix multiplication completed successfully!\n");
    return EXIT_SUCCESS;
}