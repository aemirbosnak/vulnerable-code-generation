//Gemma-7B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, m;
    scanf("Enter the number of rows and columns:", &n);
    scanf("Enter the number of elements:", &m);
    int **arr = (int **)malloc(n * sizeof(int *)), **brr = (int **)malloc(n * sizeof(int *)), **arr_cpy = (int **)malloc(n * sizeof(int *)), **sum_arr = (int **)malloc(n * sizeof(int *)), **diff_arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
        brr[i] = (int *)malloc(m * sizeof(int));
        arr_cpy[i] = (int *)malloc(m * sizeof(int));
        sum_arr[i] = (int *)malloc(m * sizeof(int));
        diff_arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("Enter the element:", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            brr[i][j] = arr[i][j] * 2;
            arr_cpy[i][j] = arr[i][j] - 5;
            sum_arr[i][j] = arr[i][j] + 10;
            diff_arr[i][j] = abs(arr[i][j] - brr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("The doubled element is: %d\n", brr[i][j]);
            printf("The copied element is: %d\n", arr_cpy[i][j]);
            printf("The sum of the element and 10 is: %d\n", sum_arr[i][j]);
            printf("The difference between the element and its double is: %d\n", diff_arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            free(arr[i][j]);
            free(brr[i][j]);
            free(arr_cpy[i][j]);
            free(sum_arr[i][j]);
            free(diff_arr[i][j]);
        }
        free(arr[i]);
        free(brr[i]);
        free(arr_cpy[i]);
        free(sum_arr[i]);
        free(diff_arr[i]);
    }

    return 0;
}