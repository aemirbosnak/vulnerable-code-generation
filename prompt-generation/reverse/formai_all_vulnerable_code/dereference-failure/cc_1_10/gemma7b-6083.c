//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void find_nearest_point(int x, int y, int **arr, int n)
{
    int min_distance = MAX;
    int nearest_point = -1;

    for (int i = 0; i < n; i++)
    {
        int dx = abs(x - arr[i][0]);
        int dy = abs(y - arr[i][1]);
        int distance = dx + dy;

        if (distance < min_distance)
        {
            min_distance = distance;
            nearest_point = i;
        }
    }

    printf("Nearest point to (%d, %d) is (%d, %d) with distance %d\n", x, y, arr[nearest_point][0], arr[nearest_point][1], min_distance);
}

int main()
{
    int n = 10;
    int **arr = (int *)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    // Fill the array with sample data
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 2;
    arr[2][0] = 3;
    arr[2][1] = 3;
    arr[3][0] = 4;
    arr[3][1] = 4;
    arr[4][0] = 5;
    arr[4][1] = 5;

    find_nearest_point(2, 2, arr, n);

    return 0;
}