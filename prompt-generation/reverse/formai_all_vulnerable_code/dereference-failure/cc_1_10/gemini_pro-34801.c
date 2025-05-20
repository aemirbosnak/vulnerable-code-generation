//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *newMatrix(int rows, int cols) {
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(sizeof(int) * cols);
    }
    return m;
}

void deleteMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrix(Matrix *m1, Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        return NULL;
    }
    Matrix *m = newMatrix(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return m;
}

Matrix *subtractMatrix(Matrix *m1, Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        return NULL;
    }
    Matrix *m = newMatrix(m1->rows, m1->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return m;
}

Matrix *multiplyMatrix(Matrix *m1, Matrix *m2) {
    if (m1->cols != m2->rows) {
        return NULL;
    }
    Matrix *m = newMatrix(m1->rows, m2->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                m->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return m;
}

int main() {
    Matrix *m1 = newMatrix(2, 3);
    m1->data[0][0] = 1;
    m1->data[0][1] = 2;
    m1->data[0][2] = 3;
    m1->data[1][0] = 4;
    m1->data[1][1] = 5;
    m1->data[1][2] = 6;

    Matrix *m2 = newMatrix(3, 2);
    m2->data[0][0] = 7;
    m2->data[0][1] = 8;
    m2->data[1][0] = 9;
    m2->data[1][1] = 10;
    m2->data[2][0] = 11;
    m2->data[2][1] = 12;

    Matrix *m3 = addMatrix(m1, m2);
    printMatrix(m3);
    deleteMatrix(m3);

    m3 = subtractMatrix(m1, m2);
    printMatrix(m3);
    deleteMatrix(m3);

    m3 = multiplyMatrix(m1, m2);
    printMatrix(m3);
    deleteMatrix(m3);

    deleteMatrix(m1);
    deleteMatrix(m2);

    return 0;
}