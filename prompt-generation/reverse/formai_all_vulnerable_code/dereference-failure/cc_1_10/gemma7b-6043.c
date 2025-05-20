//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand(time(&t));

    int w, h, i, j, r, c, d;
    w = h = 20;
    r = w / 2;
    c = h - 1;

    int **arr = (int **)malloc(h * sizeof(int *)), **arr_p = (int **)malloc(h * sizeof(int *));

    for (i = 0; i < h; i++)
    {
        arr[i] = (int *)malloc(w * sizeof(int));
        arr_p[i] = (int *)malloc(w * sizeof(int));
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            arr[i][j] = rand() % 20;
            arr_p[i][j] = arr[i][j] * 2;
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }

    free(arr_p);
    free(arr);

    return 0;
}