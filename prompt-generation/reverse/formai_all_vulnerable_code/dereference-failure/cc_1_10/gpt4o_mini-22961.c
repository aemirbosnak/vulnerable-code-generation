//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 4

// Define the matrix structure
typedef struct {
    int row;
    int col;
    int *data;
} Matrix;

Matrix A, B, ResultSum, ResultMulti;
pthread_mutex_t lock;
pthread_cond_t cond_var;
int completed_operations = 0;

// Function to add matrices
void* add_matrices(void* arg) {
    int i, j;
    for (i = 0; i < A.row; i++) {
        for (j = 0; j < A.col; j++) {
            ResultSum.data[i * A.col + j] = A.data[i * A.col + j] + B.data[i * B.col + j];
        }
    }

    pthread_mutex_lock(&lock);
    completed_operations++;
    pthread_cond_signal(&cond_var);
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Function to multiply matrices
void* multiply_matrices(void* arg) {
    int i, j, k;
    for (i = 0; i < A.row; i++) {
        for (j = 0; j < B.col; j++) {
            ResultMulti.data[i * B.col + j] = 0;
            for (k = 0; k < A.col; k++) {
                ResultMulti.data[i * B.col + j] += A.data[i * A.col + k] * B.data[k * B.col + j];
            }
        }
    }

    pthread_mutex_lock(&lock);
    completed_operations++;
    pthread_cond_signal(&cond_var);
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Function to print a matrix
void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            printf("%d ", matrix.data[i * matrix.col + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to allocate memory for a matrix
Matrix create_matrix(int row, int col) {
    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.data = (int*) malloc(row * col * sizeof(int));
    return matrix;
}

// Function to fill a matrix with random values
void fill_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->col; j++) {
            matrix->data[i * matrix->col + j] = rand() % 10;
        }
    }
}

int main() {
    srand(time(NULL));

    A = create_matrix(MAX, MAX);
    B = create_matrix(MAX, MAX);
    ResultSum = create_matrix(MAX, MAX);
    ResultMulti = create_matrix(MAX, MAX);

    fill_matrix(&A);
    fill_matrix(&B);

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    pthread_t add_thread, multi_thread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond_var, NULL);

    // Create threads for addition and multiplication
    pthread_create(&add_thread, NULL, add_matrices, NULL);
    pthread_create(&multi_thread, NULL, multiply_matrices, NULL);

    pthread_mutex_lock(&lock);
    while (completed_operations < 2) {
        pthread_cond_wait(&cond_var, &lock);
    }
    pthread_mutex_unlock(&lock);

    pthread_join(add_thread, NULL);
    pthread_join(multi_thread, NULL);

    printf("Result of A + B:\n");
    print_matrix(ResultSum);
    printf("Result of A * B:\n");
    print_matrix(ResultMulti);

    // Free allocated memory
    free(A.data);
    free(B.data);
    free(ResultSum.data);
    free(ResultMulti.data);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond_var);

    return 0;
}