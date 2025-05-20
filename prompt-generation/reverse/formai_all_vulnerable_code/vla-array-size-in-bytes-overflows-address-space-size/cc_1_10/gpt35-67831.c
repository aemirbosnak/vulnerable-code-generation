//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>

int main()
{
    int row, col;
   
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
   
    int matrix[row][col];

    printf("Enter the elements of the matrix:\n");

    // Populate the matrix with user input
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }   
    }

    printf("The entered matrix is:\n");

    // Display the entered matrix
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
           printf("%d\t", matrix[i][j]);
        }  
        printf("\n"); 
    } 

    printf("The transposed matrix is:\n");

    // Calculate and display the transpose of the matrix
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            printf("%d\t", matrix[j][i]);
        }   
        printf("\n");
    }

    return 0;
}