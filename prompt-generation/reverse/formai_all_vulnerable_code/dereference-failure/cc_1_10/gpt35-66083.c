//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function to flip an image horizontally
void flipHorizontally(unsigned char *imageData, int width, int height, int bytesPerPixel) {
    unsigned char temp;
    int i, j, k;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width / 2; j++) {
            for(k = 0; k < bytesPerPixel; k++) {
                temp = imageData[(i * width + j) * bytesPerPixel + k];
                imageData[(i * width + j) * bytesPerPixel + k] = imageData[(i * width + (width - j - 1)) * bytesPerPixel + k];
                imageData[(i * width + (width - j - 1)) * bytesPerPixel + k] = temp;
            }
        }
    }
}

//Function to adjust brightness of an image
void adjustBrightness(unsigned char *imageData, int width, int height, int bytesPerPixel, int brightnessAdjustment) {
    int i, j, k;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            for(k = 0; k < bytesPerPixel; k++) {
                imageData[(i * width + j) * bytesPerPixel + k] += brightnessAdjustment;
                if(imageData[(i * width + j) * bytesPerPixel + k] > 255)
                    imageData[(i * width + j) * bytesPerPixel + k] = 255;
                else if(imageData[(i * width + j) * bytesPerPixel + k] < 0)
                    imageData[(i * width + j) * bytesPerPixel + k] = 0;
            }
        }
    }
}

//Function to adjust contrast of an image
void adjustContrast(unsigned char *imageData, int width, int height, int bytesPerPixel, float contrastAdjustment) {
    int i, j, k;
    float pixelValue;
    float factor = (259 * (contrastAdjustment + 255)) / (255 * (259 - contrastAdjustment));
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            for(k = 0; k < bytesPerPixel; k++) {
                pixelValue = (float)imageData[(i * width + j) * bytesPerPixel + k];
                pixelValue = factor * (pixelValue - 128) + 128;
                if(pixelValue > 255)
                    pixelValue = 255;
                else if(pixelValue < 0)
                    pixelValue = 0;
                imageData[(i * width + j) * bytesPerPixel + k] = (unsigned char)pixelValue;
            }
        }
    }
}

int main(void) {
    FILE *filePointer;
    char *filename = "example.raw";
    char *outputFilename = "example_output.raw";
    int width = 512, height = 512, bytesPerPixel = 3;
    int imageSize = width * height * bytesPerPixel;

    //Allocate memory to store image data
    unsigned char *imageData = (unsigned char*) malloc(imageSize * sizeof(unsigned char));

    //Read image data from file
    filePointer = fopen(filename, "rb");
    fread(imageData, sizeof(unsigned char), imageSize, filePointer);
    fclose(filePointer);

    //Flip image horizontally
    flipHorizontally(imageData, width, height, bytesPerPixel);

    //Adjust brightness of image
    adjustBrightness(imageData, width, height, bytesPerPixel, 50);

    //Adjust contrast of image
    adjustContrast(imageData, width, height, bytesPerPixel, 50.0);

    //Write modified image data to file
    filePointer = fopen(outputFilename, "wb");
    fwrite(imageData, sizeof(unsigned char), imageSize, filePointer);
    fclose(filePointer);

    //Free allocated memory
    free(imageData);

    return 0;
}