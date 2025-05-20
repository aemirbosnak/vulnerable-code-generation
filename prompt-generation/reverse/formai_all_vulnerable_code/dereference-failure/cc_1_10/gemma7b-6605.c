//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter the number of rows:");
    scanf("%d", &n);
    printf("Enter the number of columns:");
    scanf("%d", &m);

    int **a = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements:");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is:");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    k = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            k = k + a[i][j];
        }
    }

    printf("The sum of the elements is:");
    printf("%d", k);

    for(i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}