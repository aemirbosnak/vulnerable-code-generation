//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_matrix(int **matrix, int rows, int cols);
void print_matrix(int *matrix, int rows, int cols);
void multiply_matrices(int **a, int **b, int **result, int rows, int cols);
void free_matrix(int **matrix, int rows, int cols);

int main() {
    int *matrix1, *matrix2, *result;
    int i, j;

    srand(time(NULL));

    init_matrix(&matrix1, ROWS, COLS);
    init_matrix(&matrix2, ROWS, COLS);

    print_matrix(matrix1, ROWS, COLS);
    print_matrix(matrix2, ROWS, COLS);

    multiply_matrices(&matrix1, &matrix2, &result, ROWS, COLS);

    print_matrix(result, ROWS, COLS);

    free_matrix(matrix1, ROWS, COLS);
    free_matrix(matrix2, ROWS, COLS);
    free_matrix(result, ROWS, COLS);

    return 0;
}

void init_matrix(int **matrix, int rows, int cols) {
    int *data;

    data = (int *)calloc(rows * cols, sizeof(int));

    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    *matrix = data;

    for (int i = 0; i < rows * cols; i++) {
        (*matrix)[i] = rand() % 10;
    }
}

void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * COLS + j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int **a, int **b, int **result, int rows, int cols) {
    int sum;

    *result = (int *)calloc(rows * cols, sizeof(int));

    if (*result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += (*a)[i * COLS + k] * (*b)[k * COLS + j];
            }
            (*result)[i * COLS + j] = sum;
        }
    }
}

void free_matrix(int **matrix, int rows, int cols) {
    free(matrix);
}