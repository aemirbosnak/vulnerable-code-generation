//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Reshape the reality
    int **a = (int**)malloc(4 * sizeof(int*));
    for(int i = 0; i < 4; i++)
    {
        a[i] = (int*)malloc(4 * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;

    a[1][0] = 5;
    a[1][1] = 6;
    a[1][2] = 7;
    a[1][3] = 8;

    a[2][0] = 9;
    a[2][1] = 10;
    a[2][2] = 11;
    a[2][3] = 12;

    a[3][0] = 13;
    a[3][1] = 14;
    a[3][2] = 15;
    a[3][3] = 16;

    // The One
    int one = 1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(a[i][j] == one)
            {
                a[i][j] = 0;
            }
        }
    }

    // Print the altered reality
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < 4; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}