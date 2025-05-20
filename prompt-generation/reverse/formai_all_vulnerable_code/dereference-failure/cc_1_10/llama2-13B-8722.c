//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100
#define N 100

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void init_matrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * cols * sizeof(int));
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void add_matrix(Matrix *m1, Matrix *m2, Matrix *res) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            res->data[i * res->cols + j] = m1->data[i * m1->cols + j] + m2->data[i * m2->cols + j];
        }
    }
}

void multiply_matrix(Matrix *m1, Matrix *m2, Matrix *res) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < m1->cols; k++) {
                sum += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
            }
            res->data[i * res->cols + j] = sum;
        }
    }
}

int main() {
    Matrix m1, m2, res;

    init_matrix(&m1, 5, 4);
    init_matrix(&m2, 4, 3);
    init_matrix(&res, 5, 3);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * m1.cols + j] = i * j;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i * m2.cols + j] = i * j + 1;
        }
    }

    add_matrix(&m1, &m2, &res);
    print_matrix(&res);

    multiply_matrix(&m1, &m2, &res);
    print_matrix(&res);

    return 0;
}