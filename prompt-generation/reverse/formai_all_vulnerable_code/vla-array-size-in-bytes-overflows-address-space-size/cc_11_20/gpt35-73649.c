//FormAI DATASET v1.0 Category: Matrix operations ; Style: immersive
#include<stdio.h>

// Welcome to the Matrix Operations Program!

int main(){
    // Let's begin by asking the user for the size of the matrix
    
    printf("Enter the number of rows: ");
    int rows;
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    int cols;
    scanf("%d", &cols);
    
    // Initializing the matrices
    
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];
    
    // Let's fill the matrices with the user input
    
    printf("\nEnter the elements of matrix1:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter the elements of matrix2:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Displaying the matrices
    
    printf("\nMatrix1:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix2:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Let's perform some matrix operations
    
    // Addition
    
    printf("\nAddition:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Subtraction
    
    printf("\nSubtraction:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Multiplication
    
    printf("\nMultiplication:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = 0;
            for(int k=0; k<cols; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Transpose
    
    printf("\nTranspose of Matrix1:\n");
    for(int i=0; i<cols; i++){
        for(int j=0; j<rows; j++){
            printf("%d ", matrix1[j][i]);
        }
        printf("\n");
    }
    
    // Determinant (for a 2x2 matrix only)
    if(rows == 2 && cols == 2){
        int determinant = matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
        printf("\nDeterminant of Matrix1: %d", determinant);
    }
    
    // Thank you for using the Matrix Operations Program!
    
    return 0;
}