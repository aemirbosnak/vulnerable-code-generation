//Gemma-7B DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>

int main()
{
    int n;
    scanf("Enter the number of rows: ", &n);

    // Allocate memory for the paranoia matrix
    int *matrix = (int *)malloc(n * sizeof(int));

    // Initialize the paranoia matrix
    for (int i = 0; i < n; i++)
    {
        matrix[i] = 0;
    }

    // Generate the paranoia matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i] = 1;
            }
            else if (i - j == 1)
            {
                matrix[i] = 2;
            }
            else if (i + j == n - 1)
            {
                matrix[i] = 3;
            }
        }
    }

    // Print the paranoia matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[j]);
        }
        printf("\n");
    }

    // Free the paranoia matrix
    free(matrix);

    return 0;
}