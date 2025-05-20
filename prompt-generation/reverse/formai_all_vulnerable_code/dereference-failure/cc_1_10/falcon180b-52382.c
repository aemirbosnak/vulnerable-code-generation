//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_SIZE 100

typedef struct {
    int **matrix;
    int rows;
    int cols;
    int size;
} Matrix;

void create_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->size = rows * cols;
    matrix->matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *) malloc(cols * sizeof(int));
    }
}

void populate_matrix(Matrix *matrix, int size) {
    srand(time(NULL));
    for (int i = 0; i < matrix->size; i++) {
        matrix->matrix[i / matrix->cols][i % matrix->cols] = rand() % size;
    }
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}

int main() {
    Matrix matrix;
    create_matrix(&matrix, MAX_ROWS, MAX_COLS);
    populate_matrix(&matrix, MAX_SIZE);
    printf("Original matrix:\n");
    print_matrix(&matrix);

    int **transpose = (int **) malloc(matrix.cols * sizeof(int *));
    for (int i = 0; i < matrix.cols; i++) {
        transpose[i] = (int *) malloc(matrix.rows * sizeof(int));
    }

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            transpose[j][i] = matrix.matrix[i][j];
        }
    }

    printf("\nTranspose of matrix:\n");
    for (int i = 0; i < matrix.cols; i++) {
        for (int j = 0; j < matrix.rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    free_matrix(&matrix);
    for (int i = 0; i < matrix.cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}