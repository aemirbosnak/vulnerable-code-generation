//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **arr, int h, int w)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%c ", arr[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int h = 5, w = 10;

    arr = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    arr[0][0] = '#';
    arr[0][1] = '#';
    arr[0][2] = '#';
    arr[0][3] = '#';
    arr[0][4] = '#';
    arr[0][5] = '#';
    arr[0][6] = '#';
    arr[0][7] = '#';
    arr[0][8] = '#';
    arr[0][9] = '#';

    arr[1][0] = ' ';
    arr[1][1] = ' ';
    arr[1][2] = ' ';
    arr[1][3] = ' ';
    arr[1][4] = ' ';
    arr[1][5] = ' ';
    arr[1][6] = ' ';
    arr[1][7] = ' ';
    arr[1][8] = ' ';
    arr[1][9] = ' ';

    draw_ascii_art(arr, h, w);

    for (int i = 0; i < h; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}