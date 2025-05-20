//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void findMinimumDistance(int **distance, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            distance[i][j] = MAX;
        }
    }

    distance[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            if (distance[i][j] != MAX)
            {
                continue;
            }

            distance[i][j] = distance[i - 1][j] + distance[i][j - 1] + 1;
        }
    }

    return;
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **distance = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        distance[i] = (int *)malloc(m * sizeof(int));
    }

    findMinimumDistance(distance, n, m);

    printf("The minimum distance is: %d", distance[n - 1][m - 1]);

    free(distance);

    return 0;
}