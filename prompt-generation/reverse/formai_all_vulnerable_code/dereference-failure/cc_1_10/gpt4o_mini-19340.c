//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_SIZE 512 // Maximum size for our matrices
#define THREADS 4 // Number of threads for parallel execution

// Global configuration variables
int use_strassen = 0; // Flag to use Strassen's algorithm
int use_threads = 0; // Flag to use threading
int matrix_size = 4; // Default matrix size

// Matrix structure
typedef struct {
    int **data;
    int size;
} Matrix;

// Function prototypes
Matrix* create_matrix(int size);
void free_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
void multiply_matrices(Matrix* a, Matrix* b, Matrix* result);
void strassen_multiply(Matrix* A, Matrix* B, Matrix* C);
void *threaded_multiply(void *arg);

// Function to create a matrix initialized with random values
Matrix* create_matrix(int size) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->size = size;
    matrix->data = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix->data[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix->data[i][j] = rand() % 10; // Fill matrix with random values
        }
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to print a matrix
void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Standard matrix multiplication
void multiply_matrices(Matrix* a, Matrix* b, Matrix* result) {
    for (int i = 0; i < a->size; i++) {
        for (int j = 0; j < b->size; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->size; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
}

// Strassen's algorithm for matrix multiplication
void strassen_multiply(Matrix* A, Matrix* B, Matrix* C) {
    // Strassen's multiplication is much more complex and requires splitting matrices,
    // we will leave the implementation for simplicity. Here is a stub for demonstration.
    multiply_matrices(A, B, C); // Placeholder: use standard multiplication
}

// Structure to hold parameters for threaded multiplication
typedef struct {
    Matrix* A;
    Matrix* B;
    Matrix* C;
    int row;
} ThreadArgs;

// Threaded multiplication function
void *threaded_multiply(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int i = args->row;

    for (int j = 0; j < args->B->size; j++) {
        args->C->data[i][j] = 0;
        for (int k = 0; k < args->A->size; k++) {
            args->C->data[i][j] += args->A->data[i][k] * args->B->data[k][j];
        }
    }
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc > 1) {
        use_strassen = atoi(argv[1]);
    }
    if (argc > 2) {
        use_threads = atoi(argv[2]);
    }
    if (argc > 3) {
        matrix_size = atoi(argv[3]);
    }

    if (matrix_size > MAX_SIZE) {
        printf("Size exceeds the maximum limit of %d\n", MAX_SIZE);
        return -1;
    }

    srand(time(NULL));
    
    // Matrix creation
    Matrix *A = create_matrix(matrix_size);
    Matrix *B = create_matrix(matrix_size);
    Matrix *C = create_matrix(matrix_size);

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    // Matrix multiplication
    if (use_threads) {
        pthread_t threads[THREADS];
        ThreadArgs args[THREADS];

        // Create threads to perform multiplication
        for (int i = 0; i < matrix_size; i++) {
            args[i % THREADS] = (ThreadArgs){A, B, C, i};
            pthread_create(&threads[i % THREADS], NULL, threaded_multiply, &args[i % THREADS]);
            if (i % THREADS == (THREADS - 1) || i == matrix_size - 1) {
                for (int j = 0; j < THREADS; j++) {
                    pthread_join(threads[j], NULL);
                }
            }
        }
    } else if (use_strassen) {
        strassen_multiply(A, B, C);
    } else {
        multiply_matrices(A, B, C);
    }

    printf("Resultant Matrix C:\n");
    print_matrix(C);

    // Freeing memory
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}