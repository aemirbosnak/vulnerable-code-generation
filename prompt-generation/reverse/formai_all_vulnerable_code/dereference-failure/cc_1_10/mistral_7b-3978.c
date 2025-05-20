//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

matrix createMatrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;

    m.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = 0;
        }
    }

    return m;
}

void printMatrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%4d ", m.data[i][j]);
        }
        printf("\n");
    }
}

matrix addMatrices(matrix a, matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices must have the same dimensions to be added.\n");
        exit(1);
    }

    matrix c;
    c.rows = a.rows;
    c.cols = a.cols;

    c.data = (int **)malloc(c.rows * sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = (int *)malloc(c.cols * sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return c;
}

matrix subtractMatrices(matrix a, matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Error: Matrices must have the same dimensions to be subtracted.\n");
        exit(1);
    }

    matrix c;
    c.rows = a.rows;
    c.cols = a.cols;

    c.data = (int **)malloc(c.rows * sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = (int *)malloc(c.cols * sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }

    return c;
}

void destroyMatrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

int main() {
    int m = 3, n = 3;

    matrix a = createMatrix(m, n);
    matrix b = createMatrix(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a.data[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b.data[i][j]);
        }
    }

    printMatrix(a);
    printf("\n");
    printMatrix(b);
    printf("\n");

    matrix c = addMatrices(a, b);
    printMatrix(c);
    printf("\n");

    matrix d = subtractMatrices(a, b);
    printMatrix(d);
    printf("\n");

    destroyMatrix(a);
    destroyMatrix(b);
    destroyMatrix(c);
    destroyMatrix(d);

    return 0;
}