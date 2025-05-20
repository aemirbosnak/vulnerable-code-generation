//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 255

int main()
{
    int x, y, iteration, color, red, green, blue;

    // Initialize the fractal parameters
    red = 255;
    green = 0;
    blue = 0;

    // Set up the fractal canvas
    int width = 1024;
    int height = 1024;
    unsigned char *pixels = (unsigned char *)malloc(width * height * 3);

    // Iterate over the pixels
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            iteration = 0;
            color = 0;

            // Calculate the fractal distance
            double distance = sqrt(pow(x - width / 2.0, 2) + pow(y - height / 2.0, 2)) / 255.0;

            // Increment the iteration count if the distance is greater than the threshold
            if (distance > 1.0)
            {
                iteration++;
            }

            // Map the iteration count to a color value
            color = iteration * 3;

            // Set the pixel color
            pixels[3 * (x * height) + y] = red - color;
            pixels[3 * (x * height) + y + 1] = green + color;
            pixels[3 * (x * height) + y + 2] = blue + color;
        }
    }

    // Display the fractal
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P Bitmap %d %d %d\n", width, height, 3);
    fprintf(fp, " Palette\n");
    fprintf(fp, "  R %d G %d B %d\n", red, green, blue);
    fprintf(fp, "Image\n");
    fwrite(pixels, width * height * 3, 1, fp);
    fclose(fp);

    free(pixels);

    return 0;
}