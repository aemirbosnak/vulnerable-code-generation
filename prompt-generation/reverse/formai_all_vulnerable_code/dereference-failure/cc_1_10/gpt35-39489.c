//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 3

// Matrix structure
typedef struct {
    int **values;
    int rows, cols;
} Matrix;

// Thread arguments structure
typedef struct {
    Matrix *m1, *m2, *result;
    int start_row, end_row;
} ThreadArgs;

// Initialize a matrix with random values
void init_matrix(Matrix *m) {
    int i, j;
    m->values = malloc(m->rows * sizeof(int *));
    for (i = 0; i < m->rows; i++) {
        m->values[i] = malloc(m->cols * sizeof(int));
        for (j = 0; j < m->cols; j++) {
            m->values[i][j] = rand() % 10;
        }
    }
}

// Print a matrix
void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->values[i][j]);
        }
        printf("\n");
    }
}

// Thread function to multiply a portion of two matrices
void *matrix_multiply(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *) args;
    int i, j, k, sum;
    for (i = thread_args->start_row; i < thread_args->end_row; i++) {
        for (j = 0; j < thread_args->m2->cols; j++) {
            sum = 0;
            for (k = 0; k < thread_args->m1->cols; k++) {
                sum += thread_args->m1->values[i][k] * thread_args->m2->values[k][j];
            }
            thread_args->result->values[i][j] = sum;
        }
    }
    free(thread_args);
    pthread_exit(NULL);
}

// Matrix multiplication function (multi-threaded)
Matrix *matrix_multiply_threaded(Matrix *m1, Matrix *m2, int num_threads) {
    int i, j, rc;
    Matrix *result = malloc(sizeof(Matrix));
    result->rows = m1->rows;
    result->cols = m2->cols;
    result->values = malloc(result->rows * sizeof(int *));
    for (i = 0; i < result->rows; i++) {
        result->values[i] = malloc(result->cols * sizeof(int));
    }
    pthread_t threads[num_threads];
    int rows_per_thread = m1->rows / num_threads;
    int remaining_rows = m1->rows % num_threads;
    int start_row = 0, end_row;
    for (i = 0; i < num_threads; i++) {
        ThreadArgs *thread_args = malloc(sizeof(ThreadArgs));
        thread_args->m1 = m1;
        thread_args->m2 = m2;
        thread_args->result = result;
        thread_args->start_row = start_row;
        end_row = start_row + rows_per_thread + (remaining_rows > 0 ? 1 : 0);
        remaining_rows--;
        thread_args->end_row = end_row;
        rc = pthread_create(&threads[i], NULL, matrix_multiply, (void *) thread_args);
        if (rc) {
            printf("Error: pthread_create returned %d\n", rc);
            exit(-1);
        }
        start_row = end_row;
    }
    for (i = 0; i < num_threads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: pthread_join returned %d\n", rc);
            exit(-1);
        }
    }
    return result;
}

int main() {
    srand(0);
    Matrix m1, m2, *result;
    m1.rows = m1.cols = m2.rows = 3;
    m2.cols = 2;
    init_matrix(&m1);
    init_matrix(&m2);
    printf("Matrix 1:\n");
    print_matrix(&m1);
    printf("Matrix 2:\n");
    print_matrix(&m2);
    result = matrix_multiply_threaded(&m1, &m2, 3);
    printf("Result:\n");
    print_matrix(result);
    return 0;
}