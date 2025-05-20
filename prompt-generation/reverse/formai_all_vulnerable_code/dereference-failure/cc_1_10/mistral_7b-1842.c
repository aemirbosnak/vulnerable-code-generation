//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix newMatrix;
    newMatrix.rows = rows;
    newMatrix.cols = cols;
    newMatrix.data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++)
        newMatrix.data[i] = (int *)calloc(cols, sizeof(int));
    return newMatrix;
}

void displayMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

Matrix transposeMatrix(Matrix mat) {
    Matrix newMatrix;
    newMatrix.rows = mat.cols;
    newMatrix.cols = mat.rows;
    newMatrix.data = (int **)calloc(newMatrix.rows, sizeof(int *));
    for (int i = 0; i < newMatrix.rows; i++)
        newMatrix.data[i] = (int *)calloc(newMatrix.cols, sizeof(int));

    for (int i = 0; i < newMatrix.rows; i++) {
        for (int j = 0; j < newMatrix.cols; j++) {
            newMatrix.data[i][j] = mat.data[j][i];
        }
    }
    return newMatrix;
}

Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Error: Matrices can't be multiplied!\n");
        exit(EXIT_FAILURE);
    }

    Matrix result;
    result.rows = mat1.rows;
    result.cols = mat2.cols;
    result.data = (int **)calloc(result.rows, sizeof(int *));
    for (int i = 0; i < result.rows; i++)
        result.data[i] = (int *)calloc(result.cols, sizeof(int));

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }

    return result;
}

void destroyMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++)
        free(mat.data[i]);
    free(mat.data);
    mat.rows = 0;
    mat.cols = 0;
}

int main() {
    Matrix A = createMatrix(3, 3);
    Matrix B = createMatrix(3, 3);
    Matrix C = createMatrix(3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A.data[i][j] = i + j;
            B.data[i][j] = i - j;
        }
    }

    Matrix D = transposeMatrix(B);

    printf("Matrix A:\n");
    displayMatrix(A);
    printf("Matrix B:\n");
    displayMatrix(B);
    printf("Transpose of Matrix B:\n");
    displayMatrix(D);

    Matrix product = multiplyMatrices(A, D);
    printf("Product of Matrix A and Transpose of Matrix B:\n");
    displayMatrix(product);

    destroyMatrix(A);
    destroyMatrix(B);
    destroyMatrix(C);
    destroyMatrix(D);
    destroyMatrix(product);

    return EXIT_SUCCESS;
}