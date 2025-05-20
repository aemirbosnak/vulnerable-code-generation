//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip the image horizontally
void flipHorizontal(unsigned char *image, int width, int height, int channels) {
    int row, col, c;

    for (row = 0; row < height; ++row) {
        for (col = 0; col < width / 2; ++col) {
            for (c = 0; c < channels; ++c) {
                int index1 = (row * width + col) * channels + c;
                int index2 = (row * width + (width - col - 1)) * channels + c;
                unsigned char temp = image[index1];
                image[index1] = image[index2];
                image[index2] = temp;
            }
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(unsigned char *image, int width, int height, int channels, int brightness) {
    int row, col, c;

    for (row = 0; row < height; ++row) {
        for (col = 0; col < width; ++col) {
            for (c = 0; c < channels; ++c) {
                int index = (row * width + col) * channels + c;
                int pixelValue = image[index] + brightness;
                if (pixelValue < 0) {
                    pixelValue = 0;
                } else if (pixelValue > 255) {
                    pixelValue = 255;
                }
                image[index] = pixelValue;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(unsigned char *image, int width, int height, int channels, int contrast) {
    int row, col, c;
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (row = 0; row < height; ++row) {
        for (col = 0; col < width; ++col) {
            for (c = 0; c < channels; ++c) {
                int index = (row * width + col) * channels + c;
                int pixelValue = factor * (image[index] - 128) + 128;
                if (pixelValue < 0) {
                    pixelValue = 0;
                } else if (pixelValue > 255) {
                    pixelValue = 255;
                }
                image[index] = pixelValue;
            }
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the filename (including extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    int width, height, channels;
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    channels = *(int*)&header[28];

    printf("Image dimensions: %d x %d\n", width, height);

    int imageSize = channels * width * height;
    unsigned char *image = (unsigned char*)malloc(imageSize);
    fread(image, sizeof(unsigned char), imageSize, file);

    fclose(file);

    // Flip the image horizontally
    printf("Flipping the image horizontally...\n");
    flipHorizontal(image, width, height, channels);

    // Adjust the brightness of the image
    printf("Adjusting the brightness of the image...\n");
    adjustBrightness(image, width, height, channels, 50);

    // Adjust the contrast of the image
    printf("Adjusting the contrast of the image...\n");
    adjustContrast(image, width, height, channels, 50);

    // Save the modified image to a new file
    char newFilename[100];
    printf("Enter the name of the new file (including extension): ");
    scanf("%s", newFilename);

    FILE *newFile = fopen(newFilename, "wb");
    if (!newFile) {
        printf("Error: Could not create file %s\n", newFilename);
        return 1;
    }

    fwrite(header, sizeof(unsigned char), 54, newFile);
    fwrite(image, sizeof(unsigned char), imageSize, newFile);

    fclose(newFile);

    printf("Done!\n");
    return 0;
}