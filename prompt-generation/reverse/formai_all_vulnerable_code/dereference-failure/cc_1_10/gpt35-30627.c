//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols) {
    printf("Printing Matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **transpose(int **matrix, int rows, int cols) {
    int **transpose_matrix = (int **)malloc(sizeof(int *) * cols);
    for(int i=0; i<cols; i++) {
        transpose_matrix[i] = (int *)malloc(sizeof(int) * rows);
        for(int j=0; j<rows; j++) {
            transpose_matrix[i][j] = matrix[j][i];
        }
    }
    return transpose_matrix;
}

int **multiply(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        exit(0);
    }
    int **product_matrix = (int **)malloc(sizeof(int *) * rows1);
    for(int i=0; i<rows1; i++) {
        product_matrix[i] = (int *)malloc(sizeof(int) * cols2);
        for(int j=0; j<cols2; j++) {
            product_matrix[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                product_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return product_matrix;
}

int main() {
    int rows1 = 2, cols1 = 3;
    int **matrix1 = (int **)malloc(sizeof(int *) * rows1);
    for(int i=0; i<rows1; i++) {
        matrix1[i] = (int *)malloc(sizeof(int) * cols1);
        for(int j=0; j<cols1; j++) {
            matrix1[i][j] = i+j;
        }
    }
    print_matrix(matrix1, rows1, cols1);

    printf("\nTransforming Matrix:\n");
    
    // Transposing Matrix
    int **transpose_matrix = transpose(matrix1, rows1, cols1);
    print_matrix(transpose_matrix, cols1, rows1);
    
    printf("\nTransforming Matrix:\n");
    
    // Multiplying Matrix with Transpose
    int **product_matrix = multiply(matrix1, transpose_matrix, rows1, cols1, cols1, rows1);
    print_matrix(product_matrix, rows1, rows1);

    return 0;
}