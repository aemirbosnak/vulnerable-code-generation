//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random matrix
void generate_random_matrix(int n, int m, int **matrix) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to transpose a matrix
void transpose(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = matrix[i][j];
            matrix[j][i] = matrix[j][i];
            matrix[i][j] = temp;
        }
    }
}

// Function to print a matrix
void print_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int m = 3;
    int **matrix;

    matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    generate_random_matrix(n, m, matrix);

    printf("Original matrix:\n");
    print_matrix(n, matrix);

    transpose(n, matrix);

    printf("Transposed matrix:\n");
    print_matrix(n, matrix);

    free(matrix[0]);
    free(matrix[1]);
    free(matrix[2]);
    free(matrix);

    return 0;
}