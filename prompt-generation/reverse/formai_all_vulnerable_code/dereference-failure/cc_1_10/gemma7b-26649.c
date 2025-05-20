//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void percolate(int **arr, int r, int c)
{
    int i, j, k, l;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            k = rand() % 4;
            if (arr[i][j] == 0 && k == 0)
            {
                for (l = 0; l < r; l++)
                {
                    for (int m = 0; m < c; m++)
                    {
                        if (arr[l][m] == 1)
                        {
                            arr[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int **arr;
    int r, c;

    srand(time(NULL));

    r = ROWS;
    c = COLS;
    arr = (int **)malloc(r * sizeof(int *) + r);
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int) + c);
    }

    percolate(arr, r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}