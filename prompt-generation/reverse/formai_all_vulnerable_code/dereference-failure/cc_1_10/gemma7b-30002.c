//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void reshape(int **arr, int n, int m)
{
    int i, j, k = 0;
    int *temp = (int *)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = temp[k];
            k++;
        }
    }

    free(temp);
}

int main()
{
    int **arr = NULL;
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(m * sizeof(int));

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    reshape(arr, n, m);

    printf("The rearranged matrix is: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}