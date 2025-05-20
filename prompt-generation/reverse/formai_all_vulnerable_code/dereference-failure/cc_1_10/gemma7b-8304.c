//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialization
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            a[i][j] = 0;
        }
    }

    // Simulating the Matrix
    a[1][1] = 1;
    a[2][2] = 2;
    a[3][3] = 3;

    // Transpose
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Print the Transposed Matrix
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Free Memory
    for (int i = 0; i < MAX; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}