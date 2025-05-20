//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reshape(int **arr, int n, int m)
{
    int i, j, k, l;
    int **temp = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        temp[i] = (int *)malloc(m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }

    free(*arr);
    *arr = temp;

    n = m;
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(m * sizeof(int));

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    printf("Enter the new number of rows: ");
    scanf("%d ", &n);

    printf("Enter the new number of columns: ");
    scanf("%d ", &m);

    reshape(arr, n, m);

    printf("The reshaped matrix is: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}