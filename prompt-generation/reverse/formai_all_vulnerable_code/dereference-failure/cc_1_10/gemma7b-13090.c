//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main()
{
    int x, y, i, iter = 0;
    double r, g, b, hue, sat, val;

    // Allocate memory for the image
    unsigned char *img = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

    // Set the background color
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            img[x * HEIGHT * 3] = 0;
            img[x * HEIGHT * 3 + 1] = 0;
            img[x * HEIGHT * 3 + 2] = 0;
        }
    }

    // Generate the fractal
    for (i = 0; i < WIDTH * HEIGHT; i++)
    {
        // Calculate the fractal distance
        r = (double)x / WIDTH;
        g = (double)y / HEIGHT;
        hue = 0.5 + 0.5 * sin(r * g);
        sat = 1.0;
        val = 255.0 * hue;

        // Set the pixel color
        img[i * 3] = (unsigned char)val;
        img[i * 3 + 1] = (unsigned char)val;
        img[i * 3 + 2] = (unsigned char)val;
    }

    // Save the image
    FILE *fp = fopen("fractal.bmp", "wb");
    fwrite(img, WIDTH * HEIGHT * 3, 1, fp);
    fclose(fp);

    // Free the memory
    free(img);

    return 0;
}