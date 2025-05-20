//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions\n");
        return NULL;
    }

    Matrix *c = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

Matrix *subtract_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions\n");
        return NULL;
    }

    Matrix *c = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return c;
}

Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: number of columns in matrix A must equal number of rows in matrix B\n");
        return NULL;
    }

    Matrix *c = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

int main() {
    int rows_a = 2;
    int cols_a = 3;
    int data_a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int rows_b = 3;
    int cols_b = 2;
    int data_b[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    Matrix *a = create_matrix(rows_a, cols_a);
    Matrix *b = create_matrix(rows_b, cols_b);
    
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            a->data[i][j] = data_a[i][j];
        }
    }
    
    for (int i = 0; i < rows_b; i++) {
        for (int j = 0; j < cols_b; j++) {
            b->data[i][j] = data_b[i][j];
        }
    }

    printf("Matrix A:\n");
    print_matrix(a);

    printf("Matrix B:\n");
    print_matrix(b);

    printf("Matrix A + Matrix B:\n");
    Matrix *c = add_matrices(a, b);
    print_matrix(c);

    printf("Matrix A - Matrix B:\n");
    Matrix *d = subtract_matrices(a, b);
    print_matrix(d);

    printf("Matrix A * Matrix B:\n");
    Matrix *e = multiply_matrices(a, b);
    print_matrix(e);

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);
    free_matrix(e);

    return 0;
}