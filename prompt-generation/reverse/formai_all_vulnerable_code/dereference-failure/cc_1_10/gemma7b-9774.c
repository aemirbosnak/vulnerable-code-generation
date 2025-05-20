//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int n = 3;
    int m = 4;

    a = (int**)malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int **b = NULL;
    b = (int**)malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][j] = a[i][j] * 2;
        }
    }

    printf("Doubled Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}