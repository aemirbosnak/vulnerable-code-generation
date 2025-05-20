//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }
    return m;
}

// Function to print a matrix
void print_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix* add_matrices(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Invalid matrix dimensions\n");
        return NULL;
    }
    Matrix* result = create_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix* scalar_multiply(Matrix* m, int scalar) {
    if (m->rows != m->cols) {
        printf("Matrix must be square\n");
        return NULL;
    }
    Matrix* result = create_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->data[i][j] = m->data[i][j] * scalar;
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix* transpose(Matrix* m) {
    if (m->rows != m->cols) {
        printf("Matrix must be square\n");
        return NULL;
    }
    Matrix* result = create_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix* m1 = create_matrix(3, 3);
    Matrix* m2 = create_matrix(3, 3);
    Matrix* result;

    // Initialize matrix 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1->data[i][j] = i + j;
        }
    }

    // Initialize matrix 2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2->data[i][j] = i + j * 2;
        }
    }

    // Add matrices
    result = add_matrices(m1, m2);
    if (result == NULL) {
        printf("Invalid matrix dimensions\n");
        return 1;
    }
    print_matrix(result);

    // Multiply matrix by scalar
    result = scalar_multiply(m1, 2);
    if (result == NULL) {
        printf("Invalid matrix dimensions\n");
        return 1;
    }
    print_matrix(result);

    // Transpose matrix
    result = transpose(m1);
    if (result == NULL) {
        printf("Invalid matrix dimensions\n");
        return 1;
    }
    print_matrix(result);

    return 0;
}