//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", art[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    char **art = NULL;
    int w = MAX_WIDTH;
    int h = 5;

    art = malloc(h * sizeof(char *) + h);
    for (int i = 0; i < h; i++)
    {
        art[i] = malloc(w * sizeof(char) + w);
    }

    art[0][0] = '*';
    art[0][1] = '*';
    art[0][2] = '*';
    art[1][0] = '=';
    art[1][1] = '=';
    art[1][2] = '=';
    art[2][0] = '\\';
    art[2][1] = '\\';
    art[2][2] = '\\';
    art[3][0] = '/';
    art[3][1] = '/';
    art[3][2] = '/';
    art[4][0] = '*';
    art[4][1] = '*';
    art[4][2] = '*';

    draw_ascii_art(art, w, h);

    free(art);

    return 0;
}