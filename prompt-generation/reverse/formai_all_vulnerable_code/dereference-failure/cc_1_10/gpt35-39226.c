//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

// flipping the image horizontally
void flipHorizontal(unsigned char** pixels, int height, int width) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            unsigned char temp = pixels[i][j];
            pixels[i][j] = pixels[i][width - j - 1];
            pixels[i][width - j - 1] = temp;
        }
    }
}

// changing the brightness of the image
void changeBrightness(unsigned char** pixels, int height, int width, int value) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int newPixelValue = pixels[i][j] + value;

            if (newPixelValue < 0) {
                newPixelValue = 0;
            } else if (newPixelValue > MAX_PIXEL_VALUE) {
                newPixelValue = MAX_PIXEL_VALUE;
            }

            pixels[i][j] = newPixelValue;
        }
    }
}

// changing the contrast of the image
void changeContrast(unsigned char** pixels, int height, int width, float value) {
    int i, j;
    float contrastFactor = (259 * (value + 255)) / (255 * (259 - value));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float newPixelValue = contrastFactor * (pixels[i][j] - 128) + 128;

            if (newPixelValue < 0) {
                newPixelValue = 0;
            } else if (newPixelValue > MAX_PIXEL_VALUE) {
                newPixelValue = MAX_PIXEL_VALUE;
            }

            pixels[i][j] = (unsigned char)newPixelValue;
        }
    }
}

int main() {
    char* inputFilename = "input.raw";
    int height = 256;
    int width = 256;

    unsigned char** pixels = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        pixels[i] = (unsigned char*)malloc(width * sizeof(unsigned char));
    }

    FILE* inputFile = fopen(inputFilename, "rb");
    fread(pixels[0], sizeof(unsigned char), height * width, inputFile);
    fclose(inputFile);

    // Flip the image horizontally
    flipHorizontal(pixels, height, width);

    // Change brightness of the image
    changeBrightness(pixels, height, width, 50);

    // Change contrast of the image
    changeContrast(pixels, height, width, 0.5);

    char* outputFilename = "output.raw";
    FILE* outputFile = fopen(outputFilename, "wb");
    fwrite(pixels[0], sizeof(unsigned char), height * width, outputFile);
    fclose(outputFile);

    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}