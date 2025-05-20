//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024

int main()
{
    int x, y;
    double dx, dy, d, r, g, b, iterations;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Initialize the image with black pixels
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            image[x * HEIGHT + y] = 0;
        }
    }

    // Set the iterative limit
    iterations = 255;

    // Iterate over the pixels
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            dx = (x - WIDTH / 2) / WIDTH;
            dy = (y - HEIGHT / 2) / HEIGHT;

            // Calculate the distance to the origin
            d = sqrt(dx * dx + dy * dy);

            // Set the pixel color based on the distance
            image[x * HEIGHT + y] = 255 - iterations * d;
        }
    }

    // Save the image to a file
    FILE *file = fopen("fractal.bmp", "wb");
    fwrite(image, WIDTH * HEIGHT, sizeof(unsigned char), file);
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}