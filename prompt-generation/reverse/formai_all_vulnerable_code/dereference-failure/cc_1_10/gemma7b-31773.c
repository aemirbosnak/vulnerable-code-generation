//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 3x3 matrix
    int **a = (int**)malloc(3 * sizeof(int*));
    for(int i = 0; i < 3; i++)
    {
        a[i] = (int*)malloc(3 * sizeof(int));
    }

    // Populate the matrix
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    // Transpose the matrix
    int **b = (int**)malloc(3 * sizeof(int*));
    for(int i = 0; i < 3; i++)
    {
        b[i] = (int*)malloc(3 * sizeof(int));
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            b[i][j] = a[j][i];
        }
    }

    // Print the transposed matrix
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < 3; i++)
    {
        free(a[i]);
    }
    free(a);
    for(int i = 0; i < 3; i++)
    {
        free(b[i]);
    }
    free(b);

    return 0;
}