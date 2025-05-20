//FormAI DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the size of our matrix
#define ROWS 3
#define COLS 3

// Function to print the matrix
void printMatrix(int matrix[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the matrix with random values
    int matrix[ROWS][COLS] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    // Transpose the matrix
    for(int i=0; i<ROWS; i++)
    {
        for(int j=i+1; j<COLS; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printf("\nTransposed Matrix:\n");
    printMatrix(matrix);

    // Calculate the determinant of the matrix
    int determinant = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]) - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]) + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
    printf("\nDeterminant of Matrix: %d\n", determinant);

    // Invert the matrix
    int invMatrix[ROWS][COLS];
    invMatrix[0][0] = (matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])/determinant;
    invMatrix[0][1] = (matrix[0][2]*matrix[2][1] - matrix[0][1]*matrix[2][2])/determinant;
    invMatrix[0][2] = (matrix[0][1]*matrix[1][2] - matrix[0][2]*matrix[1][1])/determinant;
    invMatrix[1][0] = (matrix[1][2]*matrix[2][0] - matrix[1][0]*matrix[2][2])/determinant;
    invMatrix[1][1] = (matrix[0][0]*matrix[2][2] - matrix[0][2]*matrix[2][0])/determinant;
    invMatrix[1][2] = (matrix[1][0]*matrix[0][2] - matrix[0][0]*matrix[1][2])/determinant;
    invMatrix[2][0] = (matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1])/determinant;
    invMatrix[2][1] = (matrix[2][0]*matrix[0][1] - matrix[0][0]*matrix[2][1])/determinant;
    invMatrix[2][2] = (matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1])/determinant;
    printf("\nInverted Matrix:\n");
    printMatrix(invMatrix);

    return 0;
}