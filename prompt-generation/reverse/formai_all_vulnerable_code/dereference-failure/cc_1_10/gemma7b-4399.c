//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_multiplication(int **a, int **b, int **c, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n, i, j;
    scanf("Enter the number of matrices: ", &n);

    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    int **b = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    int **c = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("Enter the elements of matrix A (%d, %d): ", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("Enter the elements of matrix B (%d, %d): ", &b[i][j]);
        }
    }

    matrix_multiplication(a, b, c, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("The elements of matrix C (%d, %d): ", c[i][j]);
        }
    }

    free(a);
    free(b);
    free(c);

    return 0;
}