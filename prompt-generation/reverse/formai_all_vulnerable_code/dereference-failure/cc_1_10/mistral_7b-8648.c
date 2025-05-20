//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int*)calloc(cols, sizeof(int));
    }

    return matrix;
}

void display_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(Matrix matrix1, Matrix matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("Error: Matrices cannot be added.\n");
        exit(1);
    }

    Matrix result = create_matrix(matrix1.rows, matrix1.cols);

    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrices(Matrix matrix1, Matrix matrix2) {
    if (matrix1.cols != matrix2.rows) {
        printf("Error: Matrices cannot be multiplied.\n");
        exit(1);
    }

    Matrix result = create_matrix(matrix1.rows, matrix2.cols);

    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix1.cols; k++) {
                sum += matrix1.data[i][k] * matrix2.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

int main() {
    Matrix A = create_matrix(SIZE, SIZE);
    Matrix B = create_matrix(SIZE, SIZE);
    Matrix C = create_matrix(SIZE, SIZE);
    Matrix D = create_matrix(SIZE, SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A.data[i][j] = i + j;
            B.data[i][j] = i - j;
        }
    }

    display_matrix(A);
    printf("\n");
    display_matrix(B);
    printf("\n");

    C = add_matrices(A, B);
    display_matrix(C);
    printf("\n");

    D = multiply_matrices(A, B);
    display_matrix(D);
    printf("\n");

    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(D);

    return 0;
}