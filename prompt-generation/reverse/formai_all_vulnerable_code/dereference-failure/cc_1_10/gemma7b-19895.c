//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **arr, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", arr[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr;
    int w, h;

    srand(time(NULL));

    w = rand() % MAX_WIDTH;
    h = rand() % MAX_WIDTH;

    arr = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            arr[y][x] = rand() % 26 + 65;
        }
    }

    draw_ascii_art(arr, w, h);

    for (int i = 0; i < h; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}