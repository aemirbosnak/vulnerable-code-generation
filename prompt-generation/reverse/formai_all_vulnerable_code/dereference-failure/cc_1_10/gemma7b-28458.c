//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void draw_ascii_art(char **art, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            printf("%c ", art[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    char **art = NULL;
    int width = MAX_WIDTH;
    int height = 5;

    art = malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        art[i] = malloc(width * sizeof(char) + 1);
    }

    art[0][0] = '$';
    art[0][1] = '$';
    art[0][2] = '$';
    art[0][3] = '$';
    art[0][4] = '$';
    art[1][0] = '#';
    art[1][1] = '#';
    art[1][2] = '#';
    art[1][3] = '#';
    art[1][4] = '#';
    art[2][0] = '#';
    art[2][1] = '#';
    art[2][2] = '#';
    art[2][3] = '#';
    art[2][4] = '#';
    art[3][0] = '&';
    art[3][1] = '&';
    art[3][2] = '&';
    art[3][3] = '&';
    art[3][4] = '&';
    art[4][0] = '$';
    art[4][1] = '$';
    art[4][2] = '$';
    art[4][3] = '$';
    art[4][4] = '$';

    draw_ascii_art(art, width, height);

    free(art);

    return 0;
}