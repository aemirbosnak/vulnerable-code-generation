//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void solve()
{
    int n, i, j, k, l, r, x, y, z;
    scanf("Enter the number of test cases:", &n);
    for (i = 0; i < n; i++)
    {
        scanf("Enter the number of points:", &k);
        int points[k][2];
        for (j = 0; j < k; j++)
        {
            scanf("Enter the coordinates of point %d:", points[j][0], points[j][1]);
        }
        scanf("Enter the number of lines:", &l);
        int lines[l][2];
        for (j = 0; j < l; j++)
        {
            scanf("Enter the endpoints of line %d:", lines[j][0], lines[j][1]);
        }
        int intersected = 0;
        for (j = 0; j < l; j++)
        {
            for (k = 0; k < k; k++)
            {
                if (points[k][0] >= lines[j][0] && points[k][0] <= lines[j][1] && points[k][1] >= lines[j][0] && points[k][1] <= lines[j][1])
                {
                    intersected = 1;
                }
            }
        }
        if (intersected)
        {
            printf("The points are intersected by the lines.\n");
        }
        else
        {
            printf("The points are not intersected by the lines.\n");
        }
    }
}

int main()
{
    solve();
    return 0;
}