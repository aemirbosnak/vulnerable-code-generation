//FormAI DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[ROWS][COLS]);
void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void subtract_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
int determinant(int matrix[ROWS][COLS]);
void inverse(int matrix[ROWS][COLS], int result[ROWS][COLS]);

int main() {
    // Initializing matrices
    int matrix1[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int sum[ROWS][COLS];
    int difference[ROWS][COLS];
    int product[ROWS][COLS];
    int determinant_matrix1;
    int determinant_matrix2;
    int inverse_matrix1[ROWS][COLS];
    int inverse_matrix2[ROWS][COLS];
    
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2);
    
    // Adding matrices
    add_matrices(matrix1, matrix2, sum);
    
    // Subtracting matrices
    subtract_matrices(matrix1, matrix2, difference);
    
    // Multiplying matrices
    multiply_matrices(matrix1, matrix2, product);
    
    // Determinant of matrices
    determinant_matrix1 = determinant(matrix1);
    determinant_matrix2 = determinant(matrix2);
    
    // Inverse of matrices
    inverse(matrix1, inverse_matrix1);
    inverse(matrix2, inverse_matrix2);
    
    printf("\nMatrix 1 + Matrix 2:\n");
    print_matrix(sum);
    
    printf("\nMatrix 1 - Matrix 2:\n");
    print_matrix(difference);
    
    printf("\nMatrix 1 * Matrix 2:\n");
    print_matrix(product);
    
    printf("\nDeterminant of Matrix 1: %d\n", determinant_matrix1);
    printf("Determinant of Matrix 2: %d\n", determinant_matrix2);
    
    printf("\nInverse of Matrix 1:\n");
    print_matrix(inverse_matrix1);
    
    printf("\nInverse of Matrix 2:\n");
    print_matrix(inverse_matrix2);
    
    return 0;
}

// Function to print a matrix
void print_matrix(int matrix[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to calculate determinant of a matrix
int determinant(int matrix[ROWS][COLS]) {
    int det;
    det = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]))
        - matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]))
        + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));
    return det;
}

// Function to calculate inverse of a matrix
void inverse(int matrix[ROWS][COLS], int result[ROWS][COLS]) {
    int det = determinant(matrix);
    int i, j;
    int temp[ROWS - 1][COLS - 1];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // Calculating the determinant of a submatrix
            temp[0][0] = matrix[(i + 1) % ROWS][(j + 1) % COLS];
            temp[0][1] = matrix[(i + 1) % ROWS][(j + 2) % COLS];
            temp[1][0] = matrix[(i + 2) % ROWS][(j + 1) % COLS];
            temp[1][1] = matrix[(i + 2) % ROWS][(j + 2) % COLS];
            int sub_det = determinant(temp);
            // Calculating the inverse of a matrix
            result[j][i] = ((-1)^(i+j)) * sub_det / det;
        }
    }
}