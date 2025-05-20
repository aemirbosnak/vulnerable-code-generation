//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024

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
    int w, h;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    art = malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        art[i] = malloc(w * sizeof(char) + 1);
    }

    // Get the ASCII art from the user
    printf("Enter the ASCII art: ");
    char line[MAX_WIDTH];
    for (int i = 0; i < h; i++)
    {
        scanf("%s", line);
        for (int j = 0; j < w; j++)
        {
            art[i][j] = line[j];
        }
    }

    draw_ascii_art(art, w, h);

    free(art);

    return 0;
}