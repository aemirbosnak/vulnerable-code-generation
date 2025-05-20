//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows, cols;
    int **data;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix m = {rows, cols, NULL};
    m.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
    }
    return m;
}

void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%3d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix *a, const Matrix *b) {
    Matrix c = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int main(void) {
    char input_str[100];
    Matrix a, b, sum;

    printf("Enter the dimensions and elements of Matrix A (row col element):\n");
    fgets(input_str, sizeof(input_str), stdin);
    sscanf(input_str, "%d%d", &a.rows, &a.cols);
    a = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            fscanf(stdin, "%d", &a.data[i][j]);
        }
    }

    printf("Enter the dimensions and elements of Matrix B:\n");
    fgets(input_str, sizeof(input_str), stdin);
    sscanf(input_str, "%d%d", &b.rows, &b.cols);
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "Error: Matrices cannot be added.\n");
        free_matrix(&a);
        free_matrix(&b);
        return 1;
    }
    b = create_matrix(b.rows, b.cols);
    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            fscanf(stdin, "%d", &b.data[i][j]);
        }
    }

    sum = add_matrices(&a, &b);
    printf("Matrix A:\n");
    print_matrix(&a);
    printf("Matrix B:\n");
    print_matrix(&b);
    printf("Sum of Matrices A and B:\n");
    print_matrix(&sum);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&sum);

    return 0;
}