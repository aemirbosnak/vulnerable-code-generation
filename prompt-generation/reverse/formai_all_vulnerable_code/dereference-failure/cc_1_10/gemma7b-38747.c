//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **a = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        a[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    int i, j, k, l, m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The elements of the matrix are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("The transpose of the matrix is: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);

    return 0;
}