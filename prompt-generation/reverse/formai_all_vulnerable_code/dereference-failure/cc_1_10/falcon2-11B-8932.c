//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <math.h>

// Define a function to generate a fractal
void generateFractal() {
    // Define the parameters for the fractal
    int rows = 500;
    int columns = 500;
    float scale = 1.0;

    // Calculate the maximum value for the x and y coordinates
    float maxX = rows * scale;
    float maxY = columns * scale;

    // Initialize the pixel array
    int *pixels = (int *)malloc(rows * columns * sizeof(int));
    for (int i = 0; i < rows * columns; i++) {
        pixels[i] = 0;
    }

    // Iterate over the pixels and generate the fractal
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            // Calculate the position of the current pixel
            float xCoord = x / columns * maxX;
            float yCoord = y / rows * maxY;

            // Calculate the color of the current pixel
            float distance = sqrt(xCoord * xCoord + yCoord * yCoord);
            int color = (int)((distance - 1) * 255);

            // Set the color of the current pixel in the pixel array
            pixels[y * columns + x] = color;
        }
    }

    // Print the generated fractal
    for (int i = 0; i < rows * columns; i++) {
        printf("%d ", pixels[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(pixels);
}

int main() {
    generateFractal();
    return 0;
}