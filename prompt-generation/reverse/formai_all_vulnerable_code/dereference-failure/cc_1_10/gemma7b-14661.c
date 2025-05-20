//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **matrix = NULL;
    int rows = 0, cols = 0;

    // Get the matrix dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    matrix = (char **)malloc(rows * sizeof(char *) + cols * sizeof(char));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (char *)malloc(cols * sizeof(char));
    }

    // Get the matrix data from the user
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%c", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}