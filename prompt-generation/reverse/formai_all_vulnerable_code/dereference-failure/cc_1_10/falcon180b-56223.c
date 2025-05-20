//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int **create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int **matrix1 = create_matrix(ROWS, COLS);
    int **matrix2 = create_matrix(ROWS, COLS);
    int **result = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        result[i] = (int *)malloc(COLS * sizeof(int));
    }

    printf("Matrix 1:\n");
    print_matrix(matrix1, ROWS, COLS);

    printf("Matrix 2:\n");
    print_matrix(matrix2, ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Result:\n");
    print_matrix(result, ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < ROWS; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < ROWS; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}