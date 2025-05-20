//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ROWS 10
#define MAX_NUM_COLS 10

void generate_matrix(int **matrix, int num_rows, int num_cols) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int num_rows, int num_cols) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int **matrix, int num_rows, int num_cols) {
    int i, j;
    for (i = 0; i < num_cols; i++) {
        for (j = 0; j < num_rows; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));

    int num_rows, num_cols;
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    if (num_rows > MAX_NUM_ROWS || num_cols > MAX_NUM_COLS) {
        printf("Error: Number of rows or columns exceeds maximum limit.\n");
        return 1;
    }

    int **matrix = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = (int *)malloc(num_cols * sizeof(int));
    }

    generate_matrix(matrix, num_rows, num_cols);
    printf("Original matrix:\n");
    print_matrix(matrix, num_rows, num_cols);

    transpose_matrix(matrix, num_rows, num_cols);
    printf("Transposed matrix:\n");
    print_matrix(matrix, num_rows, num_cols);

    for (int i = 0; i < num_rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}