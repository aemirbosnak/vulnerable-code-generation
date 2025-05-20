//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void readMatrix(int **mat, int row, int col) {
    int i, j;
    *mat = (int *)malloc(row * col * sizeof(int));
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &(*mat)[i * col + j]);
        }
    }
}

void printMatrix(int *mat, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", mat[i * col + j]);
        }
        printf("\n");
    }
}

void addMatrices(int *mat1, int *mat2, int row, int col, int *res) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            res[i * col + j] = mat1[i * col + j] + mat2[i * col + j];
        }
    }
}

int main(int argc, char *argv[]) {
    int m1, n1, m2, n2;
    int *mat1, *mat2, *res;

    if (argc != 5) {
        printf("Usage: %s <rows1 cols1 rows2 cols2>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d%d", &m1, &n1);
    sscanf(argv[3], "%d%d", &m2, &n2);

    if (n1 != n2) {
        printf("Error: Matrices must have the same number of columns!\n");
        return 1;
    }

    mat1 = (int *)malloc(m1 * n1 * sizeof(int));
    mat2 = (int *)malloc(m2 * n2 * sizeof(int));
    res = (int *)malloc((m1 > m2) ? m1 * n1 : m2 * n2 * sizeof(int));

    readMatrix(mat1, m1, n1);
    readMatrix(mat2, m2, n2);

    addMatrices(mat1, mat2, m1, n1, res);

    printf("Matrix 1:\n");
    printMatrix(mat1, m1, n1);

    printf("Matrix 2:\n");
    printMatrix(mat2, m2, n2);

    printf("Sum:\n");
    printMatrix(res, (m1 > m2) ? m1 : m2, n1);

    free(mat1);
    free(mat2);
    free(res);

    return 0;
}