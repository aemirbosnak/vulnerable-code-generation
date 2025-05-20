//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void text_to_ascii(char *text)
{
    int i, j, k, l, height, width;
    char **ascii_art = NULL;

    l = strlen(text);
    height = l / 20 + 1;
    width = l / 80 + 1;

    ascii_art = (char **)malloc(height * sizeof(char *) + 1);
    for (i = 0; i < height; i++)
    {
        ascii_art[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    k = 0;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            ascii_art[i][j] = text[k] ? text[k] : ' ';
            k++;
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < height; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);
}

int main()
{
    char text[] = "Hello, world!";

    text_to_ascii(text);

    return 0;
}