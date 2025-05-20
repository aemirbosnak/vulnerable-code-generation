//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix {
    int rows;
    int cols;
    int **data;
} matrix;

matrix *create_matrix(int rows, int cols) {
    matrix *m = malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
    }
    return m;
}

void destroy_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void print_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix *m = create_matrix(3, 3);
    m->data[0][0] = 1;
    m->data[0][1] = 2;
    m->data[0][2] = 3;
    m->data[1][0] = 4;
    m->data[1][1] = 5;
    m->data[1][2] = 6;
    m->data[2][0] = 7;
    m->data[2][1] = 8;
    m->data[2][2] = 9;
    print_matrix(m);
    destroy_matrix(m);
    return 0;
}