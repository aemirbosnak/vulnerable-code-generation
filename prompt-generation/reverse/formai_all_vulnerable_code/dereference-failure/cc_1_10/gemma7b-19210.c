//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define the canvas size
    int width = 1024;
    int height = 768;

    // Allocate memory for the canvas
    int *pixels = (int *)malloc(width * height * sizeof(int));

    // Initialize the pixel values
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixels[x * height + y] = 0;
        }
    }

    // Create a fractal
    for (int iter = 0; iter < 10; iter++)
    {
        // Define the fractal parameters
        double x1 = -width / 2;
        double x2 = width / 2;
        double y1 = -height / 2;
        double y2 = height / 2;
        double zoom = 2.0;

        // Iterate over the pixels
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                // Calculate the distance from the center of the canvas
                double distance = sqrt(pow(x - x2, 2) + pow(y - y2, 2)) / zoom;

                // Set the pixel color based on the distance
                pixels[x * height + y] = 255 - (int)(distance * 255);
            }
        }
    }

    // Display the fractal
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P Bitmap %d %d %d\n", width, height, 3);
    fprintf(fp, "RGB\n");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fprintf(fp, "%d %d %d ", pixels[x * height + y], pixels[x * height + y], pixels[x * height + y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Free the memory
    free(pixels);

    return 0;
}