//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

// Function to display a matrix on the console
void displayMatrix(int** matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int** matrix1, int** matrix2, int** result, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main(){
    int rows, cols;

    // Get input from the user for the number of rows and columns of the matrix
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &cols);

    // Allocate memory for the first matrix
    int **matrix1 = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        matrix1[i] = (int *) malloc(cols * sizeof(int));
    }

    // Get input from the user for the first matrix
    printf("\nEnter the elements of the first matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Allocate memory for the second matrix
    int **matrix2 = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        matrix2[i] = (int *) malloc(cols * sizeof(int));
    }

    // Get input from the user for the second matrix
    printf("\nEnter the elements of the second matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Allocate memory for the result matrix
    int **resultMatrix = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        resultMatrix[i] = (int *) malloc(cols * sizeof(int));
    }

    // Add the two matrices
    addMatrices(matrix1, matrix2, resultMatrix, rows, cols);

    // Display the result matrix
    printf("\nThe result of the addition of the two matrices:\n");
    displayMatrix(resultMatrix, rows, cols);

    // Free memory allocated for matrices
    for(int i=0; i<rows; i++){
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}