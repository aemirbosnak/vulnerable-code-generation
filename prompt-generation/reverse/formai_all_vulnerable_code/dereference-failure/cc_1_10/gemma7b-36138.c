//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void draw_ascii_art(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;
    arr[0][3] = 1;
    arr[0][4] = 1;

    arr[1][0] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[1][3] = 1;
    arr[1][4] = 1;

    arr[2][0] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;
    arr[2][3] = 1;
    arr[2][4] = 1;

    arr[3][0] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    arr[3][4] = 1;

    arr[4][0] = 1;
    arr[4][1] = 1;
    arr[4][2] = 1;
    arr[4][3] = 1;
    arr[4][4] = 1;

    draw_ascii_art(arr, n);

    free(arr);

    return 0;
}