//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int row;
    int col;
    int **data;
} matrix;

matrix createMatrix(int row, int col) {
    int i;
    matrix m = {row, col, (int **)calloc(row, sizeof(int *))};
    m.data = (int **)realloc(m.data, row * sizeof(int *));
    for (i = 0; i < row; i++) {
        m.data[i] = (int *)calloc(col, sizeof(int));
    }
    return m;
}

void inputMatrix(matrix *m) {
    int i, j;
    printf("Enter elements of matrix %d x %d:\n", m->row, m->col);
    for (i = 0; i < m->row; i++) {
        for (j = 0; j < m->col; j++) {
            scanf("%d", &m->data[i][j]);
        }
    }
}

void printMatrix(matrix m) {
    int i, j;
    for (i = 0; i < m.row; i++) {
        for (j = 0; j < m.col; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

matrix multiplyMatrices(matrix a, matrix b) {
    int i, j, k;
    matrix result = createMatrix(a.row, b.col);
    for (i = 0; i < a.row; i++) {
        for (j = 0; j < b.col; j++) {
            for (k = 0; k < a.col; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

void destroyMatrix(matrix *m) {
    int i;
    for (i = 0; i < m->row; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int main() {
    int choice;
    matrix a, b, result;

    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d%d", &a.row, &a.col);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d%d", &b.row, &b.col);

    if (a.col != b.row) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    a = createMatrix(a.row, a.col);
    b = createMatrix(b.row, b.col);

    printf("Enter elements of first matrix:\n");
    inputMatrix(&a);
    printf("\n");

    printf("Enter elements of second matrix:\n");
    inputMatrix(&b);
    printf("\n");

    result = multiplyMatrices(a, b);

    printf("Product of given matrices:\n");
    printMatrix(result);

    destroyMatrix(&a);
    destroyMatrix(&b);
    destroyMatrix(&result);

    return 0;
}