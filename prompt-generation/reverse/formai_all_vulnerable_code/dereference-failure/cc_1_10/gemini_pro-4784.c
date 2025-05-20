//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(double));
    }
    return m;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *m1, Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Matrices must have the same dimensions to be added.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

Matrix *subtract_matrices(Matrix *m1, Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Matrices must have the same dimensions to be subtracted.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return result;
}

Matrix *multiply_matrices(Matrix *m1, Matrix *m2) {
    if (m1->cols != m2->rows) {
        printf("Matrices cannot be multiplied because the number of columns in the first matrix does not match the number of rows in the second matrix.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return result;
}

Matrix *transpose_matrix(Matrix *m) {
    Matrix *result = create_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }
    return result;
}

Matrix *inverse_matrix(Matrix *m) {
    if (m->rows != m->cols) {
        printf("Matrix must be square to be inverted.\n");
        return NULL;
    }
    Matrix *result = create_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (i == j) {
                result->data[i][j] = 1;
            } else {
                result->data[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m->rows; i++) {
        double pivot = m->data[i][i];
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] /= pivot;
            result->data[i][j] /= pivot;
        }
        for (int j = 0; j < m->rows; j++) {
            if (j != i) {
                double factor = m->data[j][i];
                for (int k = 0; k < m->cols; k++) {
                    m->data[j][k] -= factor * m->data[i][k];
                    result->data[j][k] -= factor * result->data[i][k];
                }
            }
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *m1 = create_matrix(3, 3);
    m1->data[0][0] = 1;
    m1->data[0][1] = 2;
    m1->data[0][2] = 3;
    m1->data[1][0] = 4;
    m1->data[1][1] = 5;
    m1->data[1][2] = 6;
    m1->data[2][0] = 7;
    m1->data[2][1] = 8;
    m1->data[2][2] = 9;

    Matrix *m2 = create_matrix(3, 3);
    m2->data[0][0] = 10;
    m2->data[0][1] = 11;
    m2->data[0][2] = 12;
    m2->data[1][0] = 13;
    m2->data[1][1] = 14;
    m2->data[1][2] = 15;
    m2->data[2][0] = 16;
    m2->data[2][1] = 17;
    m2->data[2][2] = 18;

    // Add the matrices
    Matrix *result = add_matrices(m1, m2);
    printf("The sum of the two matrices is:\n");
    print_matrix(result);
    free_matrix(result);

    // Subtract the matrices
    result = subtract_matrices(m1, m2);
    printf("The difference of the two matrices is:\n");
    print_matrix(result);
    free_matrix(result);

    // Multiply the matrices
    result = multiply_matrices(m1, m2);
    printf("The product of the two matrices is:\n");
    print_matrix(result);
    free_matrix(result);

    // Transpose the first matrix
    result = transpose_matrix(m1);
    printf("The transpose of the first matrix is:\n");
    print_matrix(result);
    free_matrix(result);

    // Inverse the first matrix
    result = inverse_matrix(m1);
    printf("The inverse of the first matrix is:\n");
    print_matrix(result);
    free_matrix(result);

    // Free the matrices
    free_matrix(m1);
    free_matrix(m2);

    return 0;
}