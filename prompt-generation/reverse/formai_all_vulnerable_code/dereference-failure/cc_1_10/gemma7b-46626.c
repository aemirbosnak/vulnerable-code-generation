//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void MatrixOperations(int **arr, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                arr[i][j] += arr[k][j] * arr[i][k];
            }
        }
    }
}

int main()
{
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    MatrixOperations(arr, n);

    printf("The result of the matrix operations is: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}