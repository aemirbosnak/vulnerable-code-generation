//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 768

int main()
{
    int x, y, i, j;
    double d, r, g, b;

    // Allocate memory for the pixel buffer
    unsigned int *pixels = (unsigned int *)malloc(WIDTH * HEIGHT * sizeof(unsigned int));

    // Initialize pixel values
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            pixels[x * HEIGHT + y] = 0;
        }
    }

    // Get the number of iterations
    printf("Enter the number of iterations: ");
    scanf("%d", &i);

    // Generate the fractal
    for (j = 0; j < i; j++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                d = (x - WIDTH / 2) * (x - WIDTH / 2) + (y - HEIGHT / 2) * (y - HEIGHT / 2);
                r = d * 0.025;
                g = d * 0.025;
                b = d * 0.025;
                pixels[x * HEIGHT + y] = 0x00ff00 | (int)(r) << 16 | (int)(g) << 8 | (int)(b);
            }
        }
    }

    // Display the fractal
    system("display fractal.ppm");

    // Free the memory
    free(pixels);

    return 0;
}