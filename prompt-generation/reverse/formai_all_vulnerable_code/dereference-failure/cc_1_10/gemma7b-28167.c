//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int width, int height, char **art)
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
    art = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        art[i] = (char *)malloc(10 * sizeof(char));
    }

    art[0][0] = '$';
    art[0][1] = '#';
    art[0][2] = '$';
    art[0][3] = '#';
    art[0][4] = '#';

    art[1][0] = '#';
    art[1][1] = '#';
    art[1][2] = '#';
    art[1][3] = '#';
    art[1][4] = '#';

    art[2][0] = '$';
    art[2][1] = '#';
    art[2][2] = '$';
    art[2][3] = '#';
    art[2][4] = '#';

    art[3][0] = '#';
    art[3][1] = '#';
    art[3][2] = '#';
    art[3][3] = '#';
    art[3][4] = '#';

    art[4][0] = '$';
    art[4][1] = '#';
    art[4][2] = '$';
    art[4][3] = '#';
    art[4][4] = '#';

    draw_ascii_art(10, 5, art);

    free(art);

    return 0;
}