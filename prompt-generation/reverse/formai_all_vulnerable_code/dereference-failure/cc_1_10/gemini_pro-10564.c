//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000

// Matrix structures
typedef struct {
    int rows, cols;
    int **data;
} Matrix;

// Thread data structure
typedef struct {
    Matrix *A, *B, *C;
    int start_row, end_row;
} ThreadData;

// Function to create a new matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to initialize a matrix with random values
void initialize_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiply_matrices(Matrix *A, Matrix *B, Matrix *C) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            C->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                C->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
}

// Thread function to multiply a portion of two matrices
void* multiply_matrices_thread(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < data->B->cols; j++) {
            data->C->data[i][j] = 0;
            for (int k = 0; k < data->A->cols; k++) {
                data->C->data[i][j] += data->A->data[i][k] * data->B->data[k][j];
            }
        }
    }
    return NULL;
}

int main() {
    // Create matrices A, B, and C
    Matrix *A = create_matrix(N, N);
    Matrix *B = create_matrix(N, N);
    Matrix *C = create_matrix(N, N);

    // Initialize matrices A and B with random values
    initialize_matrix(A);
    initialize_matrix(B);

    // Create thread pool
    pthread_t threads[N];

    // Create thread data structures
    ThreadData data[N];

    // Divide the rows of matrix A into N chunks and assign each chunk to a thread
    int chunk_size = N / N;
    for (int i = 0; i < N; i++) {
        data[i].A = A;
        data[i].B = B;
        data[i].C = C;
        data[i].start_row = i * chunk_size;
        data[i].end_row = (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, multiply_matrices_thread, &data[i]);
    }

    // Join all threads
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result matrix C
    print_matrix(C);

    // Free the matrices
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}