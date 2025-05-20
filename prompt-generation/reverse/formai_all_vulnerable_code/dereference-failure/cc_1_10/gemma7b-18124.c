//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int width, int height, char **art)
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            printf("%c ", art[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **art = malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        art[i] = malloc(10 * sizeof(char));
    }

    art[0][0] = 'A';
    art[0][1] = 'A';
    art[0][2] = 'A';
    art[0][3] = 'A';
    art[0][4] = 'A';
    art[0][5] = 'A';
    art[0][6] = 'A';
    art[0][7] = 'A';
    art[0][8] = 'A';
    art[0][9] = 'A';

    art[1][0] = 'A';
    art[1][1] = 'A';
    art[1][2] = 'A';
    art[1][3] = 'A';
    art[1][4] = 'A';
    art[1][5] = 'A';
    art[1][6] = 'A';
    art[1][7] = 'A';
    art[1][8] = 'A';
    art[1][9] = 'A';

    art[2][0] = 'A';
    art[2][1] = 'A';
    art[2][2] = 'A';
    art[2][3] = 'A';
    art[2][4] = 'A';
    art[2][5] = 'A';
    art[2][6] = 'A';
    art[2][7] = 'A';
    art[2][8] = 'A';
    art[2][9] = 'A';

    art[3][0] = 'A';
    art[3][1] = 'A';
    art[3][2] = 'A';
    art[3][3] = 'A';
    art[3][4] = 'A';
    art[3][5] = 'A';
    art[3][6] = 'A';
    art[3][7] = 'A';
    art[3][8] = 'A';
    art[3][9] = 'A';

    art[4][0] = 'A';
    art[4][1] = 'A';
    art[4][2] = 'A';
    art[4][3] = 'A';
    art[4][4] = 'A';
    art[4][5] = 'A';
    art[4][6] = 'A';
    art[4][7] = 'A';
    art[4][8] = 'A';
    art[4][9] = 'A';

    draw_ascii_art(10, 5, art);

    for (int i = 0; i < 5; i++)
    {
        free(art[i]);
    }
    free(art);

    return 0;
}