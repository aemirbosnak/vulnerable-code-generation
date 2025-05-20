//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define N 1024 // Dimension of the matrices
#define THREADS 8 // Number of threads to use

typedef struct {
    int thread_id;
    double (*A)[N];
    double (*B)[N];
    double (*C)[N];
    int rows_per_thread;
} thread_data;

void* matrix_multiply(void* arg) {
    thread_data* data = (thread_data*)arg;
    int start_row = data->thread_id * data->rows_per_thread;
    int end_row = start_row + data->rows_per_thread;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += data->A[i][k] * data->B[k][j];
            }
            data->C[i][j] = sum;
        }
    }
    
    pthread_exit(NULL);
}

void check_allocation(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    double (*A)[N] = malloc(N * sizeof(*A));
    check_allocation(A);
    double (*B)[N] = malloc(N * sizeof(*B));
    check_allocation(B);
    double (*C)[N] = malloc(N * sizeof(*C));
    check_allocation(C);
    
    // Initialize matrices A and B and paranoidly check for initialization
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
        }
    }

    pthread_t threads[THREADS];
    thread_data thread_args[THREADS];
    
    int rows_per_thread = N / THREADS;

    for (int t = 0; t < THREADS; t++) {
        thread_args[t].thread_id = t;
        thread_args[t].A = A;
        thread_args[t].B = B;
        thread_args[t].C = C;
        thread_args[t].rows_per_thread = rows_per_thread;
        
        int rc = pthread_create(&threads[t], NULL, matrix_multiply, (void*)&thread_args[t]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", t, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int t = 0; t < THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Paranoidly verify the computation
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double expected = 0.0;
            for (int k = 0; k < N; k++) {
                expected += A[i][k] * B[k][j];
            }
            if (C[i][j] != expected) {
                fprintf(stderr, "Error in multiplication at C[%d][%d]: Expected %f but got %f\n", i, j, expected, C[i][j]);
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("Matrix multiplication completed successfully!\n");

    // Free allocated memory
    free(A);
    free(B);
    free(C);
    
    pthread_exit(NULL);
}