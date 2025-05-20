//FormAI DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix with random values
void init_matrix(int **matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int rows, int cols){
    int **result = malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        result[i] = malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2){
    int **result = malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++){
        result[i] = malloc(cols2 * sizeof(int));
        for(int j=0; j<cols2; j++){
            result[i][j] = 0;
            for(int k=0; k<cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main(){
    int rows1 = 3, cols1 = 4, rows2 = 4, cols2 = 3;
    int **matrix1 = malloc(rows1 * sizeof(int *));
    int **matrix2 = malloc(rows2 * sizeof(int *));
    int **add_result, **mult_result;
    
    // Allocate memory for matrices
    for(int i=0; i<rows1; i++){
        matrix1[i] = malloc(cols1 * sizeof(int));
    }
    for(int i=0; i<rows2; i++){
        matrix2[i] = malloc(cols2 * sizeof(int));
    }
    
    // Initialize matrices with random values
    init_matrix(matrix1, rows1, cols1);
    init_matrix(matrix2, rows2, cols2);
    
    // Print matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);
    
    // Add matrices and print result
    add_result = add_matrices(matrix1, matrix2, rows1, cols1);
    printf("Addition of matrices:\n");
    print_matrix(add_result, rows1, cols1);
    
    // Multiply matrices and print result
    mult_result = multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);
    printf("Multiplication of matrices:\n");
    print_matrix(mult_result, rows1, cols2);
    
    // Free memory allocated for matrices
    for(int i=0; i<rows1; i++){
        free(matrix1[i]);
        free(add_result[i]);
        free(mult_result[i]);
    }
    for(int i=0; i<rows2; i++){
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(add_result);
    free(mult_result);
    
    return 0;
}