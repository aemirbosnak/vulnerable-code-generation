//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void generate_random_matrix(int **matrix, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int **matrix, int rows, int cols) {
    int **transposed_matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        transposed_matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    free(matrix);
    matrix = transposed_matrix;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Matrix size exceeds maximum limit.\n");
        return 1;
    }

    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    generate_random_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);

    transpose_matrix(matrix, rows, cols);
    printf("\nTransposed Matrix:\n");
    print_matrix(matrix, cols, rows);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}