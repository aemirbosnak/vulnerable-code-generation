//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

// Function to flip the image along the vertical axis
void flipVertically(unsigned char* image, int width, int height)
{
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width/2; col++) {
            int index1 = row * width + col;
            int index2 = row * width + width - col - 1;
            unsigned char temp = image[index1];
            image[index1] = image[index2];
            image[index2] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(unsigned char* image, int width, int height, int brightness)
{
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            int index = row * width + col;
            int newValue = image[index] + brightness;
            if(newValue > 255) {
                newValue = 255;
            } else if(newValue < 0) {
                newValue = 0;
            }
            image[index] = newValue;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(unsigned char* image, int width, int height, float contrast)
{
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            int index = row * width + col;
            int newValue = factor * (image[index] - 128) + 128;
            if(newValue > 255) {
                newValue = 255;
            } else if(newValue < 0) {
                newValue = 0;
            }
            image[index] = newValue;
        }
    }
}

int main()
{
    // Read the image from a file
    FILE* infile = fopen("lena.raw", "rb");
    unsigned char* image = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, infile);
    fclose(infile);

    // Flip the image vertically
    flipVertically(image, WIDTH, HEIGHT);

    // Change the brightness of the image by 50
    changeBrightness(image, WIDTH, HEIGHT, 50);

    // Change the contrast of the image by 50%
    changeContrast(image, WIDTH, HEIGHT, 50);

    // Write the resulting image to a file
    FILE* outfile = fopen("lena_processed.raw", "wb");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, outfile);
    fclose(outfile);

    // Free the memory
    free(image);

    return 0;
}