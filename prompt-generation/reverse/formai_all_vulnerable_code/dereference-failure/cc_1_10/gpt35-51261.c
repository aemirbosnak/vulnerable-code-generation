//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define constants for easier use
#define WIDTH 256
#define HEIGHT 256

// Define function for flipping an image horizontally
void flipHorizontal(unsigned char *image) {
    int i, j;
    unsigned char temp;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH / 2; j++) {
            // Swap left and right pixels
            temp = image[i * WIDTH + j];
            image[i * WIDTH + j] = image[i * WIDTH + WIDTH - j - 1];
            image[i * WIDTH + WIDTH - j - 1] = temp;
        }
    }
}

// Define function for changing brightness/contrast of an image
void changeBrightnessContrast(unsigned char *image, float brightness, float contrast) {
    int i;
    // Calculate scaling factor based on contrast
    float scale = (contrast + 100.0) / 100.0;
    // Apply brightness and contrast adjustments to each pixel
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = (unsigned char) (image[i] * scale + brightness);
    }
}

// Define example program for flipping an image and changing brightness/contrast
int main() {
    // Load image data from file (assumed to be grayscale)
    unsigned char *image = (unsigned char *) malloc(WIDTH * HEIGHT);
    FILE *file = fopen("input.raw", "rb");
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);
    
    // Flip the image horizontally and apply brightness/contrast adjustments
    flipHorizontal(image);
    changeBrightnessContrast(image, 50.0, 50.0);
    
    // Save the processed image to file
    file = fopen("output.raw", "wb");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);
    
    // Free allocated memory
    free(image);
    
    return 0;
}