//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void findCentroid(int **arr, int n, int *x, int *y)
{
    int i, j, totalX = 0, totalY = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                totalX += arr[i][j] * (i + 1);
                totalY += arr[i][j] * (j + 1);
            }
        }
    }

    *x = totalX / n;
    *y = totalY / n;
}

int main()
{
    int n, i, j, x, y;
    int **arr;

    printf("Enter the number of rows and columns:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n, &x, &y);

    printf("The centroid of the matrix is at (%d, %d)", x, y);

    return 0;
}