//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_MATRIX_SIZE (MAX_ROWS * MAX_COLS)

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = 0;
    m->cols = 0;
    m->matrix = NULL;
}

void free_matrix(matrix_t *m) {
    if (m->matrix != NULL) {
        free(m->matrix);
        m->matrix = NULL;
    }
}

void print_matrix(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *m = (matrix_t *)malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->matrix = (int **)malloc(m->rows * sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = (int *)malloc(m->cols * sizeof(int));
    }
    return m;
}

void add_matrix(matrix_t *m1, matrix_t *m2) {
    int i, j;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            m1->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }
}

void mult_matrix(matrix_t *m1, matrix_t *m2) {
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (k = 0; k < m2->rows; k++) {
                sum += m1->matrix[i][k] * m2->matrix[k][j];
            }
            m1->matrix[i][j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_t *m1 = create_matrix(10, 10);
    matrix_t *m2 = create_matrix(5, 5);
    matrix_t *result;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m1->matrix[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            m2->matrix[i][j] = rand() % 10;
        }
    }

    add_matrix(m1, m2);
    print_matrix(m1);

    mult_matrix(m1, m2);
    print_matrix(m1);

    free_matrix(m2);
    free_matrix(m1);

    return 0;
}