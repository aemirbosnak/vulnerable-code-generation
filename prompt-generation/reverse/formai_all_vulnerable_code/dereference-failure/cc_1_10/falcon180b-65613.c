//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

void init_matrix(Matrix *matrix) {
    matrix->rows = 0;
    matrix->cols = 0;
    matrix->data = NULL;
}

void create_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
    }
}

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void random_matrix(Matrix *matrix) {
    srand(time(NULL));
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = rand() % 10;
        }
    }
}

void transpose_matrix(Matrix *matrix) {
    int temp_rows = matrix->cols;
    int temp_cols = matrix->rows;
    matrix->cols = temp_rows;
    matrix->rows = temp_cols;
    int **temp_data = (int **)malloc(temp_rows * sizeof(int *));
    for (int i = 0; i < temp_rows; i++) {
        temp_data[i] = (int *)malloc(temp_cols * sizeof(int));
    }
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            temp_data[j][i] = matrix->data[i][j];
        }
    }
    destroy_matrix(matrix);
    matrix->data = temp_data;
}

int main() {
    Matrix matrix;
    init_matrix(&matrix);
    create_matrix(&matrix, 3, 3);
    random_matrix(&matrix);
    print_matrix(&matrix);

    transpose_matrix(&matrix);
    print_matrix(&matrix);

    destroy_matrix(&matrix);
    return 0;
}