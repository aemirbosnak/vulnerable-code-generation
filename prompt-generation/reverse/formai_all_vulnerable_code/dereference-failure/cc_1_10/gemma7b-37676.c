//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: careful
#include <stdio.h>
#include <math.h>

#define MAX 1000

void findCentroid(int **arr, int n)
{
    int i, j, x = 0, y = 0, area = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                int dx = arr[i][j] - arr[i][0];
                int dy = arr[j][0] - arr[i][0];
                area += dx * dy;
            }
        }
    }
    x = area / (n * (n - 1));
    y = area / (n * (n - 1));
    printf("Centroid coordinates: (%d, %d)\n", x, y);
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    findCentroid(arr, n);

    return 0;
}