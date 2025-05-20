//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void reshape(int **a, int r, int c)
{
    int i, j, k;
    int **b = (int **)malloc(r * sizeof(int *));
    for(i = 0; i < r; i++)
    {
        b[i] = (int *)malloc(c * sizeof(int));
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            for(k = 0; k < r; k++)
            {
                if(a[k][j] != 0)
                {
                    b[i][j] = a[k][j];
                }
            }
        }
    }

    free(a);
    a = b;
}

int main()
{
    int **a = (int **)malloc(5 * sizeof(int *));
    for(int i = 0; i < 5; i++)
    {
        a[i] = (int *)malloc(5 * sizeof(int));
    }

    a[2][2] = 10;
    a[3][3] = 20;
    a[1][1] = 30;

    reshape(a, 6, 6);

    printf("%d", a[2][2]);
    printf("%d", a[3][3]);
    printf("%d", a[1][1]);

    free(a);
    return 0;
}