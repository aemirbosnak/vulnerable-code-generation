//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void findConvexHull(int **arr, int n)
{
    int i, j, k;
    int *convexHull = (int *)malloc(n * sizeof(int));

    // Calculate the convex hull
    convexHull[0] = arr[0];
    convexHull[1] = arr[1];
    for (i = 2; i < n; i++)
    {
        int flag = 0;
        for (j = 0; j < i; j++)
        {
            if (convexHull[j] > arr[i] && arr[i] - convexHull[j] < MAX)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            convexHull[i] = arr[i];
        }
    }

    // Print the convex hull
    for (k = 0; k < n; k++)
    {
        printf("%d ", convexHull[k]);
    }
    printf("\n");

    free(convexHull);
}

int main()
{
    int n;
    scanf("Enter the number of points: ", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    // Get the points
    for (int i = 0; i < n; i++)
    {
        printf("Enter the x-coordinate: ");
        scanf("%d", &arr[i][0]);

        printf("Enter the y-coordinate: ");
        scanf("%d", &arr[i][1]);
    }

    findConvexHull(arr, n);

    free(arr);

    return 0;
}