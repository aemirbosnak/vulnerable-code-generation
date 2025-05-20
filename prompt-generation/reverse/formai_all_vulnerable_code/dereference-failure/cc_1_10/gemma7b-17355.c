//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, x, y, k, l, r, d, area, perimeter;
    char **arr;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices: ");
        scanf("%d", &k);

        arr = (char **)malloc(k * sizeof(char *));

        for (j = 0; j < k; j++)
        {
            arr[j] = (char *)malloc(MAX * sizeof(char));
        }

        printf("Enter the coordinates of the vertices: ");
        for (j = 0; j < k; j++)
        {
            scanf("%d %d", &x, &y);
            arr[j][0] = x;
            arr[j][1] = y;
        }

        l = 0;
        r = k - 1;
        d = 0;

        while (l < r)
        {
            for (j = l + 1; j <= r; j++)
            {
                area = abs(arr[l][0] - arr[j][0]) * abs(arr[l][1] - arr[j][1]) + abs(arr[r][0] - arr[j][0]) * abs(arr[r][1] - arr[j][1]);
                perimeter = abs(arr[l][0] - arr[j][0]) + abs(arr[l][1] - arr[j][1]) + abs(arr[r][0] - arr[j][0]) + abs(arr[r][1] - arr[j][1]);
                d = d + area - perimeter;
            }
            l++;
        }

        printf("The total area and perimeter are: \n");
        printf("Area: %d\n", d);
        printf("Perimeter: %d\n", perimeter);

        free(arr);
    }

    return 0;
}