//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 20

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
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    art = (char **)malloc(height * sizeof(char *) + height);
    for (int i = 0; i < height; i++)
    {
        art[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    // Create ASCII art here
    art[0][0] = 'A';
    art[0][1] = 'A';
    art[0][2] = 'A';
    art[1][0] = 'A';
    art[1][1] = 'A';
    art[1][2] = 'A';
    art[2][0] = 'A';
    art[2][1] = 'A';

    draw_ascii_art(width, height, art);

    // Free memory
    for (int i = 0; i < height; i++)
    {
        free(art[i]);
    }
    free(art);

    return 0;
}