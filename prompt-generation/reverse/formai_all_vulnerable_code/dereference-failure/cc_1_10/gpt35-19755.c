//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// function to fill a matrix with random values between 0 and 1
void fill_matrix(float **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (float)rand()/(float)(RAND_MAX/1);
        }
    }
}

// function to print a matrix
void print_matrix(float **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices together
float **matrix_multiply(float **matrix1, float **matrix2, int rows1, int cols1, int rows2, int cols2) {
    // check if matrices can be multiplied
    if (cols1 != rows2) {
        printf("Matrices cannot be multiplied.\n");
        exit(0);
    }

    // create result matrix
    float **result = (float **) malloc(rows1 * sizeof(float *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (float *) malloc(cols2 * sizeof(float));
    }

    // fill result matrix with zeros
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0.0;
        }
    }

    // multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    // set dimensions of matrices
    int rows1 = 3, cols1 = 2;
    int rows2 = 2, cols2 = 4;

    // create matrices
    float **matrix1 = (float **) malloc(rows1 * sizeof(float *));
    float **matrix2 = (float **) malloc(rows2 * sizeof(float *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (float *) malloc(cols1 * sizeof(float));
    }
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (float *) malloc(cols2 * sizeof(float));
    }

    // fill matrices with random values
    fill_matrix(matrix1, rows1, cols1);
    fill_matrix(matrix2, rows2, cols2);

    // print matrices
    print_matrix(matrix1, rows1, cols1);
    printf("\n");
    print_matrix(matrix2, rows2, cols2);
    printf("\n");

    // multiply matrices and print result
    float **result = matrix_multiply(matrix1, matrix2, rows1, cols1, rows2, cols2);
    print_matrix(result, rows1, cols2);

    // free memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }

    return 0;
}