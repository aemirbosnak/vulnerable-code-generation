//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c) {
    int i, j, k;
    int rows_a = *a;
    int cols_a = *a + 1;
    int rows_b = *b;
    int cols_b = *b + 1;
    int rows_c = rows_a + rows_b;
    int cols_c = cols_a + cols_b;

    c = (int **)malloc(rows_c * sizeof(int *));
    for (i = 0; i < rows_c; i++) {
        c[i] = (int *)malloc(cols_c * sizeof(int));
    }

    for (i = 0; i < rows_a; i++) {
        for (j = 0; j < cols_a; j++) {
            for (k = 0; k < rows_b; k++) {
                int product = 0;
                for (int l = 0; l < cols_b; l++) {
                    product += a[i][j] * b[k][l] * c[i][k] / 2;
                }
                c[i][k] = product;
            }
        }
    }

    return;
}

int main() {
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int rows_a = 2;
    int cols_a = 3;
    int rows_b = 3;
    int cols_b = 2;

    a = (int **)malloc(rows_a * sizeof(int *));
    for (int i = 0; i < rows_a; i++) {
        a[i] = (int *)malloc(cols_a * sizeof(int));
    }

    b = (int **)malloc(rows_b * sizeof(int *));
    for (int i = 0; i < rows_b; i++) {
        b[i] = (int *)malloc(cols_b * sizeof(int));
    }

    matrix_operations(&a, &b, &c);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            for (int k = 0; k < rows_b; k++) {
                printf("%d ", c[i][k]);
            }
            printf("\n");
        }
    }

    return 0;
}