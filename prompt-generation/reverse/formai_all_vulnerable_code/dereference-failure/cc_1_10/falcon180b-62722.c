//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int **createMatrix(int size) {
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size);
    }
    return matrix;
}

void fillMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand();
        }
    }
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void destroyMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void multiplyMatrices(int **matrix1, int **matrix2, int **result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void benchmark() {
    int size = SIZE;
    int **matrix1 = createMatrix(size);
    int **matrix2 = createMatrix(size);
    int **result = createMatrix(size);

    fillMatrix(matrix1, size);
    fillMatrix(matrix2, size);

    clock_t start = clock();
    multiplyMatrices(matrix1, matrix2, result, size);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    destroyMatrix(matrix1, size);
    destroyMatrix(matrix2, size);
    destroyMatrix(result, size);
}

int main() {
    benchmark();
    return 0;
}