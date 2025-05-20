//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a matrix
typedef struct {
    int rows;
    int cols;
    int** data; // Pointer to a pointer for dynamic 2D array
} Matrix;

// Function to create a matrix
Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int*)malloc(cols * sizeof(int));
    }
    return m;
}

// Function to free the memory allocated for a matrix
void free_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

// Function to fill the matrix with random integers
void fill_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = rand() % 10; // Random numbers from 0-9
        }
    }
}

// Function to print the matrix
void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix m1, Matrix m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        perror("Matrix dimensions must match for addition!");
        exit(EXIT_FAILURE);
    }

    Matrix result = create_matrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiply_matrices(Matrix m1, Matrix m2) {
    if (m1.cols != m2.rows) {
        perror("Matrix dimensions must match for multiplication!");
        exit(EXIT_FAILURE);
    }
 
    Matrix result = create_matrix(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transpose_matrix(Matrix m) {
    Matrix transposed = create_matrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            transposed.data[j][i] = m.data[i][j];
        }
    }
    return transposed;
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Create two matrices
    int rows1 = 3, cols1 = 3;
    Matrix A = create_matrix(rows1, cols1);
    fill_matrix(&A);
    printf("Matrix A:\n");
    print_matrix(A);

    int rows2 = 3, cols2 = 3;
    Matrix B = create_matrix(rows2, cols2);
    fill_matrix(&B);
    printf("Matrix B:\n");
    print_matrix(B);

    // Add matrices
    Matrix C = add_matrices(A, B);
    printf("Matrix C (A + B):\n");
    print_matrix(C);

    // Multiply matrices
    Matrix D = multiply_matrices(A, B);
    printf("Matrix D (A * B):\n");
    print_matrix(D);

    // Transpose matrix A
    Matrix E = transpose_matrix(A);
    printf("Matrix E (Transpose of A):\n");
    print_matrix(E);

    // Cleanup
    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&D);
    free_matrix(&E);

    return 0;
}