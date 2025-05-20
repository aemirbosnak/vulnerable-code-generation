//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, x, y, z, centroid_x, centroid_y, area, perimeter, polygon_type;
    int **arr;

    printf("Enter the number of polygons:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices for polygon %d:", i + 1);
        scanf("%d", &k);

        arr[i] = (int *)malloc(k * sizeof(int));

        printf("Enter the coordinates of vertices:");
        for (j = 0; j < k; j++)
        {
            scanf("%d %d", &arr[i][j], &arr[i][j + 1]);
        }

        l = arr[i][0] - arr[i][k - 1];
        x = arr[i][1] - arr[i][k - 1];

        area = (l * x) / 2;
        perimeter = l + x + k - 2;

        centroid_x = (arr[i][0] * area) / perimeter;
        centroid_y = (arr[i][1] * area) / perimeter;

        printf("The area of polygon %d is: %d\n", i + 1, area);
        printf("The perimeter of polygon %d is: %d\n", i + 1, perimeter);
        printf("The centroid of polygon %d is: (%d, %d)\n", i + 1, centroid_x, centroid_y);

        printf("---------------------------------------------------\n");
    }

    return 0;
}