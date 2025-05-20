//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to rotate a matrix by 90 degrees clockwise
void rotate_matrix(int** matrix, int rows, int cols) {
    int** new_matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        new_matrix[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            new_matrix[i][j] = matrix[j][rows - i - 1];
        }
    }
    free(matrix);
    matrix = new_matrix;
}

// Function to reflect a matrix over the main diagonal
void reflect_matrix(int** matrix, int rows, int cols) {
    int** new_matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        new_matrix[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                new_matrix[i][j] = matrix[i][j];
            } else {
                new_matrix[i][j] = matrix[j][i];
            }
        }
    }
    free(matrix);
    matrix = new_matrix;
}

int main() {
    int rows = 4;
    int cols = 4;
    int** matrix = (int**) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }

    // Rotate the matrix by 90 degrees clockwise
    rotate_matrix(matrix, rows, cols);

    // Reflect the matrix over the main diagonal
    reflect_matrix(matrix, rows, cols);

    // Print the resulting matrix
    print_matrix(matrix, rows, cols);

    free(matrix);
    return 0;
}