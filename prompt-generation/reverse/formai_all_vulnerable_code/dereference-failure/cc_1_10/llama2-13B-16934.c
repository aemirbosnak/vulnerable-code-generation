//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

// Function to print a matrix
void print_matrix(int (*mat)[COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int add_matrices(int (*mat1)[COLS], int (*mat2)[COLS], int (*result)[COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
int multiply_matrix_by_scalar(int (*mat)[COLS], int scalar) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            mat[i][j] *= scalar;
        }
    }
    return mat;
}

// Function to transpose a matrix
int transpose_matrix(int (*mat)[COLS]) {
    int i, j, k;
    int temp[COLS][ROWS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            temp[j][i] = mat[i][j];
        }
    }
    return temp;
}

int main() {
    int (*mat1)[COLS] = malloc(ROWS * sizeof(int[COLS]));
    int (*mat2)[COLS] = malloc(ROWS * sizeof(int[COLS]));
    int (*result)[COLS] = malloc(ROWS * sizeof(int[COLS]));

    // Initialize mat1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat1[i][j] = i * j;
        }
    }

    // Initialize mat2
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat2[i][j] = i * j * 2;
        }
    }

    // Add mat1 and mat2
    add_matrices(mat1, mat2, result);

    // Multiply result by 3
    multiply_matrix_by_scalar(result, 3);

    // Transpose result
    transpose_matrix(result);

    // Print the result
    print_matrix(result);

    free(mat1);
    free(mat2);
    free(result);

    return 0;
}