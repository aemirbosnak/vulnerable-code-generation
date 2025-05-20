//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(Matrix *matrix) {
    int rows = matrix->rows;
    int cols = matrix->cols;

    Matrix *transposed_matrix = create_matrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed_matrix->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    free(matrix->matrix);
    matrix->matrix = transposed_matrix->matrix;
    matrix->rows = transposed_matrix->rows;
    matrix->cols = transposed_matrix->cols;
    free(transposed_matrix);
}

void add_matrix(Matrix *matrix1, Matrix *matrix2) {
    int rows1 = matrix1->rows;
    int cols1 = matrix1->cols;
    int rows2 = matrix2->rows;
    int cols2 = matrix2->cols;

    if (rows1!= rows2 || cols1!= cols2) {
        printf("Cannot add matrices with different dimensions.\n");
        return;
    }

    Matrix *result = create_matrix(rows1, cols1);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }

    free(matrix1->matrix);
    matrix1->matrix = result->matrix;
    matrix1->rows = result->rows;
    matrix1->cols = result->cols;
    free(result);
}

void multiply_matrix(Matrix *matrix1, Matrix *matrix2) {
    int rows1 = matrix1->rows;
    int cols1 = matrix1->cols;
    int rows2 = matrix2->rows;
    int cols2 = matrix2->cols;

    if (cols1!= rows2) {
        printf("Cannot multiply matrices with incompatible dimensions.\n");
        return;
    }

    Matrix *result = create_matrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }

    free(matrix2->matrix);
    matrix2->matrix = result->matrix;
    matrix2->rows = result->rows;
    matrix2->cols = result->cols;
    free(result);
}

int main() {
    int rows = 3;
    int cols = 4;

    Matrix *matrix1 = create_matrix(rows, cols);
    Matrix *matrix2 = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1->matrix[i][j] = i + j;
            matrix2->matrix[i][j] = 2 * (i + j);
        }
    }

    print_matrix(matrix1);
    print_matrix(matrix2);

    transpose_matrix(matrix1);
    transpose_matrix(matrix2);

    print_matrix(matrix1);
    print_matrix(matrix2);

    add_matrix(matrix1, matrix2);
    add_matrix(matrix2, matrix1);

    print_matrix(matrix1);
    print_matrix(matrix2);

    multiply_matrix(matrix1, matrix2);
    multiply_matrix(matrix2, matrix1);

    print_matrix(matrix1);
    print_matrix(matrix2);

    free(matrix1->matrix);
    free(matrix2->matrix);
    free(matrix1);
    free(matrix2);

    return 0;
}