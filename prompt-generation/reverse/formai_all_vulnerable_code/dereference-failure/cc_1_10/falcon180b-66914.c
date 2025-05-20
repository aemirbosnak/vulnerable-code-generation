//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int **create_matrix(int rows, int cols) {
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

void destroy_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix_with_random_data(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int rows = 10;
    int cols = 10;

    int **matrix = create_matrix(rows, cols);
    fill_matrix_with_random_data(matrix, rows, cols);

    printf("Original matrix:\n");
    print_matrix(matrix, rows, cols);

    int **transpose = create_matrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of matrix:\n");
    print_matrix(transpose, cols, rows);

    destroy_matrix(matrix, rows);
    destroy_matrix(transpose, cols);

    return 0;
}