//Gemma-7B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void reshape(int **arr, int n, int m)
{
    int i, j, k = 0;
    int **arr_new = (int **)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr_new[i][j] = arr[k];
            k++;
        }
    }

    free(arr);
    arr = arr_new;
}

int main()
{
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    reshape(arr, n, m);

    printf("The reshaped matrix is: \n");
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