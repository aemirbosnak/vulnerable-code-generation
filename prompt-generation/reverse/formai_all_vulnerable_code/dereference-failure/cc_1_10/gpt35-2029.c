//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255

// Flip the input image horizontally
void flipImageHorizontally(unsigned char* image, int width, int height, int channels) {
    unsigned char tempPixel[channels];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            // Swap the pixels on the left and right side for each row
            memcpy(tempPixel, &image[(y * width + x) * channels], channels);
            memcpy(&image[(y * width + x) * channels], &image[(y * width + (width - x - 1)) * channels], channels);
            memcpy(&image[(y * width + (width - x - 1)) * channels], tempPixel, channels);
        }
    }
}

// Adjust the brightness of the input image by a given amount
void adjustBrightness(unsigned char* image, int width, int height, int channels, int brightness) {
    int pixelValue;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                // Get the current pixel value
                pixelValue = image[(y * width + x) * channels + c];

                // Increase or decrease the pixel value by the given brightness amount
                pixelValue += brightness;

                // Limit the pixel value to the valid range
                if (pixelValue < 0) {
                    pixelValue = 0;
                } else if (pixelValue > MAX_PIXEL_VALUE) {
                    pixelValue = MAX_PIXEL_VALUE;
                }

                // Set the new pixel value
                image[(y * width + x) * channels + c] = (unsigned char) pixelValue;
            }
        }
    }
}

// Adjust the contrast of the input image by a given amount
void adjustContrast(unsigned char* image, int width, int height, int channels, float contrast) {
    int pixelValue;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                // Get the current pixel value
                pixelValue = image[(y * width + x) * channels + c];

                // Increase or decrease the pixel value according to the contrast formula
                pixelValue = (int) (contrast * (pixelValue - MAX_PIXEL_VALUE / 2) + MAX_PIXEL_VALUE / 2);

                // Limit the pixel value to the valid range
                if (pixelValue < 0) {
                    pixelValue = 0;
                } else if (pixelValue > MAX_PIXEL_VALUE) {
                    pixelValue = MAX_PIXEL_VALUE;
                }

                // Set the new pixel value
                image[(y * width + x) * channels + c] = (unsigned char) pixelValue;
            }
        }
    }
}

int main(int argc, char** argv) {
    char* inputFilename = "input_image.bmp";
    char* outputFilename = "output_image.bmp";
    int brightness = 50;
    float contrast = 0.5;

    // Load the input image
    FILE* inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file '%s'\n", inputFilename);
        return 1;
    }

    // Read the BMP header
    unsigned char bmpHeader[54];
    fread(bmpHeader, sizeof(unsigned char), 54, inputFile);
    int width = *(int*)&bmpHeader[18];
    int height = *(int*)&bmpHeader[22];
    int bitDepth = *(int*)&bmpHeader[28];
    printf("Image statistics: Width = %d, Height = %d, Bit Depth = %d\n", width, height, bitDepth);

    // Allocate memory for the image data
    int imageSize = width * height * 3;
    unsigned char* image = (unsigned char*) malloc(imageSize);
    if (image == NULL) {
        printf("Error: Unable to allocate memory for image data\n");
        return 1;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), imageSize, inputFile);

    // Close the input file
    fclose(inputFile);

    // Perform image processing tasks
    flipImageHorizontally(image, width, height, 3);
    adjustBrightness(image, width, height, 3, brightness);
    adjustContrast(image, width, height, 3, contrast);

    // Save the output image
    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file '%s'\n", outputFilename);
        return 1;
    }

    // Write the BMP header
    fwrite(bmpHeader, sizeof(unsigned char), 54, outputFile);

    // Write the image data
    fwrite(image, sizeof(unsigned char), imageSize, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the memory allocated for the image data
    free(image);

    printf("Image processing completed!\n");

    return 0;
}