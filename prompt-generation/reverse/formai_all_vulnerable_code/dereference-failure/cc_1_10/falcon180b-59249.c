//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int** create_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int **matrix1 = create_matrix(size);
    int **matrix2 = create_matrix(size);
    int **result = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of matrices:\n");
    print_matrix(result, size);

    for (int i = 0; i < size; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    for (int i = 0; i < size; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}