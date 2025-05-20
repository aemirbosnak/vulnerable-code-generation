//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    int w = 10, h = 10;
    int **pixels = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        pixels[i] = (int*)malloc(w * sizeof(int));
    }

    // Initialize pixels
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            pixels[y][x] = 0;
        }
    }

    // Draw a line
    pixels[1][0] = 1;
    pixels[1][1] = 1;
    pixels[1][2] = 1;

    // Draw a circle
    pixels[3][3] = 1;
    pixels[3][4] = 1;
    pixels[3][5] = 1;
    pixels[4][3] = 1;
    pixels[4][4] = 1;
    pixels[4][5] = 1;

    // Display pixels
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            if (pixels[y][x] == 1)
            {
                printf("%c", 240);
            }
            else
            {
                printf("%c", 0);
            }
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < h; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}