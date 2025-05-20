//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_THREADS 4
#define MATRIX_SIZE 1000

struct matrix_data {
    int **matrix;
    int num_rows;
    int num_cols;
};

struct thread_data {
    struct matrix_data *matrix;
    int start_row;
    int end_row;
};

void *matrix_sum(void *thread_arg)
{
    struct thread_data *data = (struct thread_data *) thread_arg;
    int sum = 0;
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < data->matrix->num_cols; j++) {
            sum += data->matrix->matrix[i][j];
        }
    }

    pthread_exit((void *) sum);
}

int main()
{
    // Create a matrix of random numbers
    struct matrix_data matrix;
    matrix.num_rows = MATRIX_SIZE;
    matrix.num_cols = MATRIX_SIZE;
    matrix.matrix = (int **) malloc(sizeof(int *) * matrix.num_rows);
    for (int i = 0; i < matrix.num_rows; i++) {
        matrix.matrix[i] = (int *) malloc(sizeof(int) * matrix.num_cols);
        for (int j = 0; j < matrix.num_cols; j++) {
            matrix.matrix[i][j] = rand() % 100;
        }
    }

    // Create threads to sum the matrix
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];
    int sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].matrix = &matrix;
        thread_data[i].start_row = i * matrix.num_rows / NUM_THREADS;
        thread_data[i].end_row = (i + 1) * matrix.num_rows / NUM_THREADS;
        pthread_create(&threads[i], NULL, matrix_sum, &thread_data[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        void *result;
        pthread_join(threads[i], &result);
        sum += (int) result;
    }

    // Print the sum of the matrix
    printf("The sum of the matrix is: %d\n", sum);

    // Free the matrix
    for (int i = 0; i < matrix.num_rows; i++) {
        free(matrix.matrix[i]);
    }
    free(matrix.matrix);

    return 0;
}