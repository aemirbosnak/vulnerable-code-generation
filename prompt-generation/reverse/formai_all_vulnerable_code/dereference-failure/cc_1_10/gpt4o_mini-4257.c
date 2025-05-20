//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 500 // Size of the square matrices
#define NUM_THREADS 4 // Number of threads to be used

typedef struct {
    int thread_id;
    int **a;
    int **b;
    int **result;
    int size;
} thread_data;

// Thread function for matrix multiplication
void *multiply(void *threadarg) {
    thread_data *data = (thread_data *)threadarg;
    int thread_id = data->thread_id;
    int **a = data->a;
    int **b = data->b;
    int **result = data->result;
    int size = data->size;

    for (int i = thread_id; i < size; i += NUM_THREADS) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

// Function to create a matrix and initialize it
int **create_matrix(int size) {
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0-9
        }
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main() {
    srand(time(NULL));
    int **a = create_matrix(SIZE);
    int **b = create_matrix(SIZE);
    int **result = create_matrix(SIZE);

    pthread_t threads[NUM_THREADS];
    thread_data thread_args[NUM_THREADS];
    clock_t start, end;

    // Start time measurement
    start = clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].a = a;
        thread_args[i].b = b;
        thread_args[i].result = result;
        thread_args[i].size = SIZE;
        pthread_create(&threads[i], NULL, multiply, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // End time measurement
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Uncomment the following lines to print the result
    /* 
    printf("Result Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    */

    printf("Matrix multiplication completed in %f seconds.\n", cpu_time_used);

    // Free allocated memory
    free_matrix(a, SIZE);
    free_matrix(b, SIZE);
    free_matrix(result, SIZE);

    pthread_exit(NULL);
}