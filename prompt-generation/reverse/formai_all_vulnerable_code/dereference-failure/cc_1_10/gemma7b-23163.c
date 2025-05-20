//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <math.h>

void draw_fractal(int x, int y, int zoom, int color)
{
    int i, j, r, g, b;

    // Calculate the fractal's dimensions
    int width = 1024 * zoom;
    int height = 1024 * zoom;

    // Allocate memory for the fractal
    unsigned char *image = (unsigned char *)malloc(width * height * 3);

    // Set the fractal's color
    r = g = b = color;

    // Iterate over the fractal's pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int distance = abs(x - j) + abs(y - i);

            // If the pixel is within the fractal's boundary, set its color
            if (distance < zoom)
            {
                image[3 * (i * width) + 3 * j] = r;
                image[3 * (i * width) + 3 * j + 1] = g;
                image[3 * (i * width) + 3 * j + 2] = b;
            }
        }
    }

    // Display the fractal
    printf("Png image file: fractal.png\n");
    system("convert -scale 1024x1024 -fill black fractal.png -colorspace rgb -depth 24 -write fractal.png image.c");

    // Free the memory allocated for the fractal
    free(image);
}

int main()
{
    draw_fractal(0, 0, 2, 0x00ff00);
    draw_fractal(100, 100, 4, 0x00ff00);
    draw_fractal(200, 200, 6, 0x00ff00);

    return 0;
}