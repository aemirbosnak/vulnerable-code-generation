//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void solve()
{
    int n, i, j, k, x, y, minDistance = MAX;
    scanf("Enter the number of points: ", &n);

    // Allocate memory for points
    int **points = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        points[i] = (int*)malloc(2 * sizeof(int));
    }

    // Get the points
    for (i = 0; i < n; i++)
    {
        scanf("Enter the x-coordinate of point %d: ", &points[i][0]);
        scanf("Enter the y-coordinate of point %d: ", &points[i][1]);
    }

    // Calculate the minimum distance
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                x = points[i][0] - points[j][0];
                y = points[i][1] - points[j][1];
                k = x * x + y * y;
                minDistance = minDistance < k ? minDistance : k;
            }
        }
    }

    // Print the minimum distance
    printf("The minimum distance between any two points is: %d\n", minDistance);

    // Free memory
    for (i = 0; i < n; i++)
    {
        free(points[i]);
    }
    free(points);
}

int main()
{
    solve();
    return 0;
}