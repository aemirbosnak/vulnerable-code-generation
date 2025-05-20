//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void imgToAscii(char **img, int w, int h)
{
    int i, j, k, l, r, g, b;
    char pixel, asciiChar;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            pixel = img[i][j];

            r = pixel >> 5 & 0x1F;
            g = pixel >> 2 & 0x1F;
            b = pixel & 0x1F;

            asciiChar = 0x2D + 16 * (r - g) + 4 * (g - b);
            printf("%c ", asciiChar);
        }

        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w, h;

    w = 5;
    h = 5;

    img = malloc(h * w * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        img[i] = malloc(w * sizeof(char));
    }

    img[0][0] = 0xFF;
    img[0][1] = 0x00;
    img[0][2] = 0x00;
    img[0][3] = 0x00;
    img[0][4] = 0xFF;

    img[1][0] = 0x00;
    img[1][1] = 0x00;
    img[1][2] = 0x00;
    img[1][3] = 0xFF;
    img[1][4] = 0x00;

    imgToAscii(img, w, h);

    free(img);

    return 0;
}