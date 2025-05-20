//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
// A matrix operations program that will blow your mind!

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Matrix Operations Program!\n");
    printf("Get ready to enter the matrix...\n");
    
    int rows, cols;
    printf("Enter the number of rows for your matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for your matrix: ");
    scanf("%d", &cols);
    
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    
    printf("Awesome! Time to enter the values for your first matrix...\n");
    
    // Populate first matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the value for element(%d,%d): ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("Cool beans! Now it's time to enter values for your second matrix...\n");
    
    // Populate second matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the value for element(%d,%d): ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    printf("Nice! Now we'll perform some matrix operations for you...\n");
    
    // Addition of matrices
    printf("The sum of your two matrices is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    // Transpose of first matrix
    printf("The transpose of your first matrix is:\n");
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            printf("%d\t", matrix1[j][i]);
        }
        printf("\n");
    }
    
    // Scalar multiplication of first matrix
    int scalar;
    printf("Enter a scalar value for multiplication: ");
    scanf("%d", &scalar);
    
    printf("The scalar product of your first matrix is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = scalar * matrix1[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    printf("You have reached the end of the matrix...\n");
    printf("We hope you enjoyed your journey in the matrix, goodbye!\n");
    
    return 0;
}