//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a fractal image
void generateFractal(int width, int height) {
    // Create an empty array to store the pixels
    int* pixels = (int*)malloc(width * height * sizeof(int));
    
    // Set all pixels to black
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 0;
    }
    
    // Set the middle pixel to white
    pixels[width * height / 2] = 255;
    
    // Iterate over the pixels to generate the fractal
    for (int i = 0; i < width * height; i++) {
        // Check if the current pixel is at the edge
        if (i == 0 || i == width * height - 1) {
            // Set the pixel to black
            pixels[i] = 0;
        } else {
            // Check if the current pixel is at the center
            if (i == width * height / 2) {
                // Set the pixel to white
                pixels[i] = 255;
            } else {
                // Calculate the next pixel value
                int nextPixel = (int)pow(2.0, (double)(i - width * height / 2)) * 0.5;
                // Check if the next pixel value is between 0 and 255
                if (nextPixel > 0 && nextPixel < 255) {
                    // Set the pixel to the next pixel value
                    pixels[i] = nextPixel;
                } else {
                    // Set the pixel to black
                    pixels[i] = 0;
                }
            }
        }
    }
    
    // Print the pixels
    for (int i = 0; i < width * height; i++) {
        printf("%d ", pixels[i]);
    }
    printf("\n");
    
    // Free the memory
    free(pixels);
}

int main() {
    int width = 500;
    int height = 500;
    
    generateFractal(width, height);
    
    return 0;
}