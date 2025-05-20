//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = 0;
    m->cols = 0;
    m->matrix = NULL;
}

void free_matrix(matrix_t *m) {
    if (m->matrix != NULL) {
        free(m->matrix);
        m->matrix = NULL;
    }
}

int add_matrix(matrix_t *a, matrix_t *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrix dimensions must be equal.\n");
        return -1;
    }

    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }

    return 0;
}

int mult_matrix(matrix_t *a, matrix_t *b) {
    if (a->rows != b->cols) {
        printf("Matrix dimensions must be compatible for multiplication.\n");
        return -1;
    }

    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            for (k = 0; k < a->cols; k++) {
                a->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }

    return 0;
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Initialize matrix A
    a.rows = 5;
    a.cols = 3;
    a.matrix = (int **)malloc(a.rows * sizeof(int *));
    for (int i = 0; i < a.rows; i++) {
        a.matrix[i] = (int *)malloc(a.cols * sizeof(int));
        for (int j = 0; j < a.cols; j++) {
            a.matrix[i][j] = i * j;
        }
    }

    // Initialize matrix B
    b.rows = 3;
    b.cols = 4;
    b.matrix = (int **)malloc(b.rows * sizeof(int *));
    for (int i = 0; i < b.rows; i++) {
        b.matrix[i] = (int *)malloc(b.cols * sizeof(int));
        for (int j = 0; j < b.cols; j++) {
            b.matrix[i][j] = i * j;
        }
    }

    // Add matrices A and B
    if (add_matrix(&a, &b) == -1) {
        printf("Error adding matrices A and B.\n");
        return 1;
    }

    // Multiply matrices A and B
    if (mult_matrix(&a, &b) == -1) {
        printf("Error multiplying matrices A and B.\n");
        return 1;
    }

    // Print matrix C
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}