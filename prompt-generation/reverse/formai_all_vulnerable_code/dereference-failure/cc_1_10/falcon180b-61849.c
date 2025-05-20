//Falcon-180B DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VALUES 10000

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

matrix *create_matrix(int rows, int cols) {
    matrix *m = (matrix *)malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *)malloc(cols * sizeof(int));
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

void fill_matrix(matrix *m, int start_row, int start_col, int end_row, int end_col, int value) {
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            m->data[i][j] = value;
        }
    }
}

int count_values(matrix *m, int value) {
    int count = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (m->data[i][j] == value) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    matrix *m = create_matrix(MAX_ROWS, MAX_COLS);
    fill_matrix(m, 0, 0, MAX_ROWS - 1, MAX_COLS - 1, rand() % 100);
    int value = 42;
    int count = count_values(m, value);
    printf("Value %d appears %d times in the matrix.\n", value, count);
    destroy_matrix(m);
    return 0;
}