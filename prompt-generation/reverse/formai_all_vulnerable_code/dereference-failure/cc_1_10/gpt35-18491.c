//FormAI DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
// Scene: Verona, Italy. A classroom at the Verona Academy of Mathematics.

#include <stdio.h>
#include <stdlib.h>

// Function to display the elements of a 2D matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    printf("\n\n");
    printf("Oh sweet Juliet, let us add these matrices,\n");
    printf("For only through their union, shall we achieve perfect bliss.\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    printf("\n\n");
    printf("Oh faithful Romeo, let us multiply these matrices,\n");
    printf("For only through their union, shall we achieve eternal happiness.\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    // Initialize matrices
    int matrix1[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7},
                         {6, 5, 4},
                         {3, 2, 1}};
    int result[3][3];
    
    // Display matrices
    printf("Behold fair Juliet, matrix1 is: \n");
    displayMatrix(3, 3, matrix1);
    printf("\n");
    printf("Behold loyal Romeo, matrix2 is: \n");
    displayMatrix(3, 3, matrix2);
    
    // Add matrices and display result
    addMatrices(3, 3, matrix1, matrix2, result);
    printf("Ah, my sweet Juliet, behold the result of our addition: \n");
    displayMatrix(3, 3, result);
    
    // Multiply matrices and display result
    multiplyMatrices(3, 3, matrix1, 3, 3, matrix2, result);
    printf("Ah, my devoted Romeo, behold the result of our multiplication: \n");
    displayMatrix(3, 3, result);
    
    printf("\n");
    return 0;
}