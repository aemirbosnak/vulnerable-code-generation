//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

// Function to print a matrix of size rows x cols
void print_matrix(int matrix[][3], int rows, int cols){
    printf("\nMatrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices matrix1 and matrix2 of sizes rows1 x cols1 and rows2 x cols2 respectively
void multiply_matrices(int matrix1[][3], int rows1, int cols1, int matrix2[][2], int rows2, int cols2, int result[][2]){
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            result[i][j] = 0;
            for(int k=0; k<cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){
    // Example 1: Addition of two matrices
    int matrix_a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrix_b[2][3] = {{6, 5, 4}, {3, 2, 1}};
    int result_matrix_a_b[2][3];

    // Add matrices matrix_a and matrix_b and store the result in result_matrix_a_b
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            result_matrix_a_b[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    // Print all matrices
    print_matrix(matrix_a, 2, 3);
    print_matrix(matrix_b, 2, 3);
    print_matrix(result_matrix_a_b, 2, 3);

    // Example 2: Multiplication of two matrices
    int matrix_c[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_d[3][2] = {{10, 11}, {12, 13}, {14, 15}};
    int result_matrix_c_d[3][2];

    // Multiply matrices matrix_c and matrix_d and store the result in result_matrix_c_d
    multiply_matrices(matrix_c, 3, 3, matrix_d, 3, 2, result_matrix_c_d);

    // Print all matrices
    print_matrix(matrix_c, 3, 3);
    print_matrix(matrix_d, 3, 2);
    print_matrix(result_matrix_c_d, 3, 2);

    return 0;
}