//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

int main()
{
    int x, y, iteration, color, red, green, blue;
    double x_min, x_max, y_min, y_max, dx, dy;

    // Set the fractal parameters
    x_min = -2.0f;
    x_max = 1.0f;
    y_min = -1.0f;
    y_max = 1.0f;
    dx = 0.01f;
    dy = 0.01f;

    // Allocate memory for the image
    int image_width = (int) ((x_max - x_min) / dx) + 1;
    int image_height = (int) ((y_max - y_min) / dy) + 1;
    unsigned char *image = (unsigned char *) malloc(image_width * image_height * 3);

    // Iterate over the pixels
    for (x = 0; x < image_width; x++)
    {
        for (y = 0; y < image_height; y++)
        {
            iteration = 0;
            color = 0;
            red = 0;
            green = 0;
            blue = 0;

            // Iterate over the iterations
            for (iteration = 0; iteration < MAX_ITERATIONS && color == 0; iteration++)
            {
                double x_c = x_min + dx * x;
                double y_c = y_min + dy * y;
                double z = 0.0f;
                double z_prev = 0.0f;

                // Compute the fractal distance
                for (int i = 0; i < 20 && z_prev != z; i++)
                {
                    z = z_prev + (z_prev * z_prev) - z_prev * cos(x_c) * sin(y_c);
                    z_prev = z;
                }

                // If the distance is less than the threshold, color the pixel
                if (z < 2.0)
                {
                    color = 255;
                    red = 255 - iteration * 5;
                    green = iteration * 5;
                    blue = 0;
                }
            }

            // Set the pixel color
            image[x * image_width * 3 + y * image_width * 3] = red;
            image[x * image_width * 3 + y * image_width * 3 + 1] = green;
            image[x * image_width * 3 + y * image_width * 3 + 2] = blue;
        }
    }

    // Save the image
    FILE *file = fopen("fractal.bmp", "wb");
    fwrite(image, image_width * image_height * 3, 1, file);
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}