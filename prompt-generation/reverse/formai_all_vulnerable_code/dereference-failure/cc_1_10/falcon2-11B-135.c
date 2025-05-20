//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create_matrix(int **matrix, int size) {
    matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
}

void assign_random_values(int **matrix, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matmul(int **matrix1, int **matrix2, int **result) {
    int size = (matrix1[0][0]) * (matrix2[0][0]);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int size = 3;
    int **matrix1, **matrix2, **result;
    create_matrix(&matrix1, size);
    create_matrix(&matrix2, size);
    assign_random_values(matrix1, size);
    assign_random_values(matrix2, size);
    create_matrix(&result, size);
    matmul(matrix1, matrix2, result);
    print_matrix(result, size);
    free(matrix1);
    free(matrix2);
    free(result);
    return 0;
}