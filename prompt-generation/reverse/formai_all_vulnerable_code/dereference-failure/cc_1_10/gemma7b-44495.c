//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

void percolate(int **arr, int w, int h)
{
    srand(time(NULL));
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            arr[r][c] = rand() % 2;
        }
    }

    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            if (arr[r][c] == 1)
            {
                arr[r][c] = 2;
                percolate(arr, w, h);
            }
        }
    }
}

int main()
{
    int **arr = NULL;
    int w = MAX_WIDTH;
    int h = MAX_HEIGHT;

    arr = (int**)malloc(h * sizeof(int*));
    for (int r = 0; r < h; r++)
    {
        arr[r] = (int*)malloc(w * sizeof(int));
    }

    percolate(arr, w, h);

    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}