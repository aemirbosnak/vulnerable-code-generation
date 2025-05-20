//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void text_to_ascii(char **ascii_art, int height, int width, char text[])
{
    int i, j;
    int text_len = strlen(text);
    int rows = height;
    int cols = width;

    *ascii_art = (char *)malloc(rows * cols * sizeof(char));

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (j < text_len && text[j] != '\0')
            {
                ascii_art[i][j] = text[j] + 32;
            }
            else
            {
                ascii_art[i][j] = 32;
            }
        }
    }
}

int main()
{
    char **ascii_art = NULL;
    int height = 5;
    int width = 20;
    char text[] = "HELLO, WORLD!";

    text_to_ascii(&ascii_art, height, width, text);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    free(ascii_art);

    return 0;
}