//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontal(unsigned char image[], int width, int height, int channels) {
    int x, y, c;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            for (c = 0; c < channels; c++) {
                int indexA = (y * width + x) * channels + c;
                int indexB = (y * width + (width - 1 - x)) * channels + c;
                unsigned char temp = image[indexA];
                image[indexA] = image[indexB];
                image[indexB] = temp;
            }
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(unsigned char image[], int width, int height, int channels, int brightness) {
    int x, y, c;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            for (c = 0; c < channels; c++) {
                int index = (y * width + x) * channels + c;
                int value = (int)image[index] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image[index] = (unsigned char)value;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(unsigned char image[], int width, int height, int channels, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    int x, y, c;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            for (c = 0; c < channels; c++) {
                int index = (y * width + x) * channels + c;
                int value = (int)(factor * (image[index] - 128) + 128);
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image[index] = (unsigned char)value;
            }
        }
    }
}

int main() {
    // Load image from file
    const char* filename = "example.jpg";
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char* imageData = (unsigned char*)malloc(fileSize);
    if (!imageData) {
        printf("Could not allocate memory for image data\n");
        return 1;
    }
    if (fread(imageData, 1, fileSize, file) != fileSize) {
        printf("Could not read file %s\n", filename);
        return 1;
    }
    fclose(file);

    // Extract image properties
    int width = *(int*)&imageData[18];
    int height = *(int*)&imageData[22];
    int bitsPerPixel = *(short*)&imageData[28];
    int channels = bitsPerPixel / 8;
    if (channels != 3) {
        printf("Only RGB images are supported\n");
        return 1;
    }

    // Flip the image horizontally
    flipHorizontal(imageData + 54, width, height, channels);

    // Adjust the brightness of the image
    adjustBrightness(imageData + 54, width, height, channels, 50);

    // Adjust the contrast of the image
    adjustContrast(imageData + 54, width, height, channels, 50.0);

    // Save the image to file
    const char* outputFilename = "output.jpg";
    FILE* outputFile = fopen(outputFilename, "wb");
    if (!outputFile) {
        printf("Could not create file %s\n", outputFilename);
        return 1;
    }
    fwrite(imageData, 1, fileSize, outputFile);
    fclose(outputFile);

    // Free memory
    free(imageData);

    return 0;
}