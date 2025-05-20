//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;

    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)calloc(cols, sizeof(int));
    }

    return mat;
}

void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%4d", mat.data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(Matrix mat1, Matrix mat2) {
    Matrix result;

    if (mat1.rows != mat1.rows || mat1.cols != mat2.cols) {
        printf("Error: Matrices cannot be added.\n");
        return createMatrix(0, 0);
    }

    result = createMatrix(mat1.rows, mat1.cols);

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }

    return result;
}

Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    Matrix result;

    if (mat1.cols != mat2.rows) {
        printf("Error: Matrices cannot be multiplied.\n");
        return createMatrix(0, 0);
    }

    result = createMatrix(mat1.rows, mat2.cols);

    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1.cols; k++) {
                sum += mat1.data[i][k] * mat2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}

int main() {
    Matrix A = createMatrix(3, 3);
    Matrix B = createMatrix(3, 3);
    Matrix C = createMatrix(3, 3);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A.data[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B.data[i][j]);
        }
    }

    C = addMatrices(A, B);
    printf("\nSum of matrices A and B:\n");
    printMatrix(C);

    C = multiplyMatrices(A, B);
    printf("\nProduct of matrices A and B:\n");
    printMatrix(C);

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);

    return 0;
}