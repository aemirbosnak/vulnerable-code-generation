//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 1000
#define N 500
#define K 256

typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *m = (Matrix *)calloc(1, sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (double *)calloc(rows * cols, sizeof(double));
    return m;
}

void free_matrix(Matrix *m) {
    free(m->data);
    free(m);
}

void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *m1, Matrix *m2) {
    Matrix *result = create_matrix(m1->rows, m2->cols);
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            for (k = 0; k < m1->cols; k++) {
                result->data[i * result->cols + j] += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
            }
        }
    }
    return result;
}

Matrix *multiply_matrices(Matrix *m1, Matrix *m2) {
    Matrix *result = create_matrix(m1->rows, m2->cols * m1->cols);
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            for (k = 0; k < m1->cols; k++) {
                result->data[i * result->cols + j * m1->cols + k] =
                    m1->data[i * m1->cols + k] * m2->data[j * m2->cols + k];
            }
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    Matrix *m1 = create_matrix(M, N);
    Matrix *m2 = create_matrix(M, K);
    Matrix *m3 = create_matrix(M, K);
    Matrix *m4 = create_matrix(M, K);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            m1->data[i * M + j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            m2->data[i * M + j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            m3->data[i * M + j] = (double)rand() / RAND_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            m4->data[i * M + j] = (double)rand() / RAND_MAX;
        }
    }

    Matrix *result1 = add_matrices(m1, m2);
    Matrix *result2 = add_matrices(m1, m3);
    Matrix *result3 = add_matrices(m2, m3);
    Matrix *result4 = add_matrices(m2, m4);

    print_matrix(result1);
    print_matrix(result2);
    print_matrix(result3);
    print_matrix(result4);

    free_matrix(result1);
    free_matrix(result2);
    free_matrix(result3);
    free_matrix(result4);

    return 0;
}