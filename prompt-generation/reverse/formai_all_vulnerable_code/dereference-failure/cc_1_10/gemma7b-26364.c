//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

void draw_ascii_art(char **art, int width, int height)
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
    char **art = NULL;
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    art = (char **)malloc(height * sizeof(char *) + 1);
    for (int r = 0; r < height; r++)
    {
        art[r] = (char *)malloc(width * sizeof(char) + 1);
    }

    art[0][0] = 'H';
    art[0][1] = 'A';
    art[0][2] = 'R';
    art[0][3] = 'D';
    art[1][0] = 'O';
    art[1][1] = 'R';
    art[1][2] = 'A';
    art[1][3] = 'T';
    art[2][0] = 'C';
    art[2][1] = 'O';
    art[2][2] = 'N';
    art[2][3] = 'R';

    draw_ascii_art(art, width, height);

    for (int r = 0; r < height; r++)
    {
        free(art[r]);
    }
    free(art);

    return 0;
}