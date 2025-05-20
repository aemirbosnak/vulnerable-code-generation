//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 512 // Matrix size, N x N

typedef struct {
    int id;
    int (*A)[N];
    int (*B)[N];
    int (*C)[N];
    int rows_per_thread;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    int i, j, k;
    int start_row = data->id * data->rows_per_thread;
    int end_row = start_row + data->rows_per_thread;

    for (i = start_row; i < end_row; i++) {
        for (j = 0; j < N; j++) {
            data->C[i][j] = 0;
            for (k = 0; k < N; k++) {
                data->C[i][j] += data->A[i][k] * data->B[k][j];
            }
        }
    }
    return NULL;
}

int main() {
    // Allocate matrices
    int (*A)[N] = malloc(N * N * sizeof(int));
    int (*B)[N] = malloc(N * N * sizeof(int));
    int (*C)[N] = malloc(N * N * sizeof(int));
    if (!A || !B || !C) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices A and B with random values
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0; // Initialize result matrix to zero
        }
    }

    // Set up threading
    int num_threads = 4;
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    int rows_per_thread = N / num_threads;

    // Start the clock for performance measurement
    clock_t start = clock();

    // Create threads for matrix multiplication
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].id = i;
        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].C = C;
        thread_data[i].rows_per_thread = rows_per_thread;
        pthread_create(&threads[i], NULL, multiply, &thread_data[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Stop the clock
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Optional: Print the result matrix (uncomment if needed)
    /*
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    */

    printf("Time taken for multiplication: %f seconds\n", time_taken);

    // Clean up
    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}