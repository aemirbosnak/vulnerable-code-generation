//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fIn = fopen("input_image.raw", "rb");
    FILE *fOut = fopen("output_image.raw", "wb");

    if (fIn == NULL || fOut == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    // Get image dimensions
    int width = 512;
    int height = 512;
    int size = width * height;

    // Allocate memory for input and output images
    unsigned char *inputImage = (unsigned char*)malloc(size * sizeof(unsigned char));
    unsigned char *outputImage = (unsigned char*)malloc(size * sizeof(unsigned char));
    
    // Read input image
    fread(inputImage, sizeof(unsigned char), size, fIn);

    // Flip image horizontally
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            outputImage[i*width + j] = inputImage[i*width + (width - 1 - j)];
        }
    }

    // Increase image brightness by 50%
    for (i = 0; i < size; i++) {
        int val = inputImage[i] + 0.5 * 255;
        outputImage[i] = (val > 255) ? 255 : val;
    }

    // Write output image
    fwrite(outputImage, sizeof(unsigned char), size, fOut);

    // Free memory and close files
    free(inputImage);
    free(outputImage);
    fclose(fIn);
    fclose(fOut);

    return 0;
}