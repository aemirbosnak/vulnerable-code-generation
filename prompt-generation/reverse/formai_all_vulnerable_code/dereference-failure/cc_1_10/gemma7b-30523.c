//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

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

    printf("Enter the width of the artwork (max %d): ", MAX_WIDTH);
    scanf("%d", &w);

    printf("Enter the height of the artwork (max %d): ", MAX_HEIGHT);
    scanf("%d", &h);

    art = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        art[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    // Get the artwork data from the user
    printf("Enter the artwork data (separate lines for each row):\n");
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            scanf("%c", &art[y][x]);
        }
        scanf("\n");
    }

    draw_ascii_art(art, w, h);

    free(art);

    return 0;
}