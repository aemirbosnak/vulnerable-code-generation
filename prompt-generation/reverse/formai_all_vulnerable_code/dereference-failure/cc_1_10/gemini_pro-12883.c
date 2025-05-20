//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int **matrix;
    int rows;
    int cols;
} matrix_t;

matrix_t *matrix_new(char *name, int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->name = name;
    matrix->matrix = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(int) * cols);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

void matrix_free(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix->name);
    free(matrix);
}

void matrix_print(matrix_t *matrix) {
    printf("%s:\n", matrix->name);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int matrix_evaluate(matrix_t *matrix) {
    int result = 0;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result += matrix->matrix[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *a = matrix_new("A", 3, 3);
    a->matrix[0][0] = 1;
    a->matrix[0][1] = 2;
    a->matrix[0][2] = 3;
    a->matrix[1][0] = 4;
    a->matrix[1][1] = 5;
    a->matrix[1][2] = 6;
    a->matrix[2][0] = 7;
    a->matrix[2][1] = 8;
    a->matrix[2][2] = 9;

    matrix_t *b = matrix_new("B", 3, 3);
    b->matrix[0][0] = 1;
    b->matrix[0][1] = 2;
    b->matrix[0][2] = 3;
    b->matrix[1][0] = 4;
    b->matrix[1][1] = 5;
    b->matrix[1][2] = 6;
    b->matrix[2][0] = 7;
    b->matrix[2][1] = 8;
    b->matrix[2][2] = 9;

    matrix_print(a);
    matrix_print(b);

    int result = matrix_evaluate(a) + matrix_evaluate(b);
    printf("Result: %d\n", result);

    matrix_free(a);
    matrix_free(b);

    return 0;
}