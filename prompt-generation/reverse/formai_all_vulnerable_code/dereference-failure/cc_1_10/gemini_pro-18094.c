//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(double));
    }
    return matrix;
}

void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

Matrix *subtractMatrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

Matrix *multiplyMatrix(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        return NULL;
    }
    Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

Matrix *transposeMatrix(Matrix *matrix) {
    Matrix *result = createMatrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix *matrix1 = createMatrix(3, 3);
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;
    matrix1->data[2][0] = 7;
    matrix1->data[2][1] = 8;
    matrix1->data[2][2] = 9;

    Matrix *matrix2 = createMatrix(3, 3);
    matrix2->data[0][0] = 10;
    matrix2->data[0][1] = 11;
    matrix2->data[0][2] = 12;
    matrix2->data[1][0] = 13;
    matrix2->data[1][1] = 14;
    matrix2->data[1][2] = 15;
    matrix2->data[2][0] = 16;
    matrix2->data[2][1] = 17;
    matrix2->data[2][2] = 18;

    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    Matrix *addedMatrix = addMatrix(matrix1, matrix2);
    printf("\nAdded Matrix:\n");
    printMatrix(addedMatrix);
    freeMatrix(addedMatrix);

    Matrix *subtractedMatrix = subtractMatrix(matrix1, matrix2);
    printf("\nSubtracted Matrix:\n");
    printMatrix(subtractedMatrix);
    freeMatrix(subtractedMatrix);

    Matrix *multipliedMatrix = multiplyMatrix(matrix1, matrix2);
    printf("\nMultiplied Matrix:\n");
    printMatrix(multipliedMatrix);
    freeMatrix(multipliedMatrix);

    Matrix *transposedMatrix = transposeMatrix(matrix1);
    printf("\nTransposed Matrix:\n");
    printMatrix(transposedMatrix);
    freeMatrix(transposedMatrix);

    freeMatrix(matrix1);
    freeMatrix(matrix2);

    return 0;
}