//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)calloc(cols, sizeof(int));
    }
    return m;
}

void print_matrix(const matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%4d", m.data[i][j]);
        }
        printf("\n");
    }
}

matrix multiply_matrices(const matrix a, const matrix b) {
    matrix result;
    if (a.cols != b.rows) {
        fprintf(stderr, "Error: matrices can't be multiplied.\n");
        exit(EXIT_FAILURE);
    }

    result = create_matrix(a.rows, b.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    matrix a = create_matrix(3, 3);
    matrix b = create_matrix(3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a.data[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b.data[i][j] = i - j;
        }
    }

    printf("Matrix A:\n");
    print_matrix(a);

    printf("Matrix B:\n");
    print_matrix(b);

    matrix c = multiply_matrices(a, b);

    printf("Product of A and B:\n");
    print_matrix(c);

    for (int i = 0; i < 3; i++) {
        free(a.data[i]);
    }
    free(a.data);

    for (int i = 0; i < 3; i++) {
        free(b.data[i]);
    }
    free(b.data);

    for (int i = 0; i < 3; i++) {
        free(c.data[i]);
    }
    free(c.data);

    return EXIT_SUCCESS;
}