//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 10
#define MAT_NAME_LEN 20

typedef struct {
    char name[MAT_NAME_LEN];
    int rows, cols;
    float** elements;
} Matrix;

Matrix createMatrix(const char* name, int rows, int cols) {
    Matrix mat = {0};
    strcpy(mat.name, name);
    mat.rows = rows;
    mat.cols = cols;
    mat.elements = (float**)calloc(rows, sizeof(float*));
    for (int i = 0; i < rows; i++) {
        mat.elements[i] = (float*)calloc(cols, sizeof(float));
    }
    return mat;
}

void printMatrix(const Matrix mat) {
    printf("\n%s:\n", mat.name);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%.2f ", mat.elements[i][j]);
        }
        printf("\n");
    }
}

Matrix multiplyMatrices(const Matrix a, const Matrix b) {
    Matrix result = createMatrix("Result", a.rows, b.cols);
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.elements[i][j] += a.elements[i][k] * b.elements[k][j];
            }
        }
    }
    return result;
}

int main() {
    Matrix A = createMatrix("Matrix A", SIZE, SIZE);
    Matrix B = createMatrix("Matrix B", SIZE, SIZE);
    Matrix C = createMatrix("Matrix C", SIZE, SIZE);

    // Fill matrices with unique values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A.elements[i][j] = (float)(rand() % 101) / 100.0;
            B.elements[i][j] = (float)(rand() % 101) / 100.0;
        }
    }

    // Print initial matrices
    printMatrix(A);
    printMatrix(B);

    // Multiply matrices A and B
    Matrix product = multiplyMatrices(A, B);

    // Print multiplication result
    printMatrix(product);

    // Free memory
    for (int i = 0; i < SIZE; i++) {
        free(A.elements[i]);
    }
    free(A.elements);

    for (int i = 0; i < SIZE; i++) {
        free(B.elements[i]);
    }
    free(B.elements);

    for (int i = 0; i < SIZE; i++) {
        free(product.elements[i]);
    }
    free(product.elements);

    return 0;
}