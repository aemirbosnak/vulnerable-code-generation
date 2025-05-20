//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void find_perimeter(int **arr, int n)
{
    int i, j, perimeter = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                int d = abs(arr[i][j] - arr[i][i]) + abs(arr[i][j] - arr[j][j]);
                perimeter += d;
            }
        }
    }
    printf("The perimeter of the triangle is: %d\n", perimeter);
}

int main()
{
    int n, i, j, k;
    int **arr;

    printf("Enter the number of triangles: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the side lengths of each triangle: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    find_perimeter(arr, n);

    return 0;
}