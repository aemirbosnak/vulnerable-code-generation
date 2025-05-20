//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_MATRIX_SIZE 10
#define SIZE_MATRIX(matrix) (sizeof(matrix) / sizeof(matrix[0]))
#define RANDOM(min, max) (rand() % ((max + 1) - (min)) + min)
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;
void print_matrix(const matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%4d", matrix->data[i][j]);
        }
        printf("\n");
    }
}
matrix create_random_matrix(int rows, int cols) {
    matrix matrix = {.rows = rows, .cols = cols};
    matrix.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = calloc(cols, sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix.data[i][j] = RANDOM(-10, 10);
        }
    }
    return matrix;
}
matrix multiply_matrices(const matrix *matrix1, const matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        fprintf(stderr, "Error: Matrices can't be multiplied\n");
        exit(EXIT_FAILURE);
    }
    matrix result = create_random_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result.data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}
int main() {
    srand(time(NULL));
    int rows1 = RANDOM(1, MAX_MATRIX_SIZE);
    int cols1 = RANDOM(1, MAX_MATRIX_SIZE);
    int rows2 = RANDOM(1, MAX_MATRIX_SIZE);
    int cols2 = RANDOM(1, MAX_MATRIX_SIZE);
    matrix matrix1 = create_random_matrix(rows1, cols1);
    matrix matrix2 = create_random_matrix(cols1, rows2);
    printf("Matrix 1:\n");
    print_matrix(&matrix1);
    printf("Matrix 2:\n");
    print_matrix(&matrix2);
    matrix result = multiply_matrices(&matrix1, &matrix2);
    printf("Result:\n");
    print_matrix(&result);
    for (int i = 0; i < rows1; i++) {
        free(matrix1.data[i]);
    }
    free(matrix1.data);
    for (int i = 0; i < cols1; i++) {
        free(matrix2.data[i]);
    }
    free(matrix2.data);
    free(matrix1.data);
    free(matrix2.data);
    free(matrix1.data);
    free(matrix2.data);
    return 0;
}