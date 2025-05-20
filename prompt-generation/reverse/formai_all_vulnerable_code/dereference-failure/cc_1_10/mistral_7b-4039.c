//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, cols;
    int **matrix;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix mat = {rows, cols, NULL};
    mat.matrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.matrix[i] = calloc(cols, sizeof(int));
    }
    return mat;
}

void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%3d ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Error: Matrices cannot be multiplied.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(mat1.rows, mat2.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < mat1.cols; k++) {
                result.matrix[i][j] += mat1.matrix[i][k] * mat2.matrix[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix A = createMatrix(3, 3);
    Matrix B = createMatrix(3, 3);
    Matrix C;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A.matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B.matrix[i][j]);
        }
    }

    C = multiplyMatrices(A, B);

    printf("Matrix A:\n");
    printMatrix(A);

    printf("Matrix B:\n");
    printMatrix(B);

    printf("Product of Matrix A and Matrix B:\n");
    printMatrix(C);

    for (int i = 0; i < 3; i++) {
        free(A.matrix[i]);
    }
    free(A.matrix);

    for (int i = 0; i < 3; i++) {
        free(B.matrix[i]);
    }
    free(B.matrix);

    for (int i = 0; i < 3; i++) {
        free(C.matrix[i]);
    }
    free(C.matrix);

    return EXIT_SUCCESS;
}