//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void findCentroid(int **arr, int n)
{
    int i, j, x = 0, y = 0, total = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                x += arr[i][j] * (i + 1);
                y += arr[i][j] * (j + 1);
                total += arr[i][j];
            }
        }
    }

    printf("Centroid coordinates: (%f, %f)\n", (float)x / total, (float)y / total);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *) + n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int) + n);
    }

    printf("Enter the matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n);

    free(arr);

    return 0;
}