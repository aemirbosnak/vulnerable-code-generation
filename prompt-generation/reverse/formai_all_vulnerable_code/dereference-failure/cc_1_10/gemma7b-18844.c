//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[] = "C image to ASCII art converter";
    int i, j, k, l, width = 20, height = 10;
    char **ascii_art = (char**)malloc(height * sizeof(char *));

    for (k = 0; k < height; k++)
    {
        ascii_art[k] = (char*)malloc(width * sizeof(char));
    }

    for (i = 0; image[i] != '\0'; i++)
    {
        switch (image[i])
        {
            case '.':
                ascii_art[l][j] = '-';
                break;
            case '/':
                ascii_art[l][j] = '|';
                break;
            case '*':
                ascii_art[l][j] = '=';
                break;
            case '_':
                ascii_art[l][j] = '_';
                break;
            default:
                ascii_art[l][j] = image[i];
                break;
        }

        j++;
        if (j == width)
        {
            l++;
            j = 0;
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

    free(ascii_art);

    return 0;
}