//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main() {
    // Open the original image file
    FILE *originalImageFile = fopen("original.png", "rb");
    if (originalImageFile == NULL) {
        printf("Error opening the original image file.\n");
        return EXIT_FAILURE;
    }

    // Get the size of the original image file
    fseek(originalImageFile, 0, SEEK_END);
    long originalImageSize = ftell(originalImageFile);
    rewind(originalImageFile);

    // Read the original image data into a buffer
    byte *originalImageData = malloc(originalImageSize);
    if (originalImageData == NULL) {
        printf("Error allocating memory for the original image data.\n");
        fclose(originalImageFile);
        return EXIT_FAILURE;
    }
    fread(originalImageData, 1, originalImageSize, originalImageFile);
    fclose(originalImageFile);

    // Open the watermark image file
    FILE *watermarkImageFile = fopen("watermark.png", "rb");
    if (watermarkImageFile == NULL) {
        printf("Error opening the watermark image file.\n");
        free(originalImageData);
        return EXIT_FAILURE;
    }

    // Get the size of the watermark image file
    fseek(watermarkImageFile, 0, SEEK_END);
    long watermarkImageSize = ftell(watermarkImageFile);
    rewind(watermarkImageFile);

    // Read the watermark image data into a buffer
    byte *watermarkImageData = malloc(watermarkImageSize);
    if (watermarkImageData == NULL) {
        printf("Error allocating memory for the watermark image data.\n");
        fclose(watermarkImageFile);
        free(originalImageData);
        return EXIT_FAILURE;
    }
    fread(watermarkImageData, 1, watermarkImageSize, watermarkImageFile);
    fclose(watermarkImageFile);

    // Embed the watermark in the original image
    int watermarkWidth = 64;
    int watermarkHeight = 64;
    for (int i = 0; i < watermarkWidth; i++) {
        for (int j = 0; j < watermarkHeight; j++) {
            int originalPixelIndex = (i + watermarkWidth * j) * 3;
            int watermarkPixelIndex = (i + watermarkWidth * j) * 4;
            originalImageData[originalPixelIndex] = (originalImageData[originalPixelIndex] & 0xF8) | (watermarkImageData[watermarkPixelIndex] >> 5);
            originalImageData[originalPixelIndex + 1] = (originalImageData[originalPixelIndex + 1] & 0xF8) | (watermarkImageData[watermarkPixelIndex + 1] >> 5);
            originalImageData[originalPixelIndex + 2] = (originalImageData[originalPixelIndex + 2] & 0xF8) | (watermarkImageData[watermarkPixelIndex + 2] >> 5);
        }
    }

    // Open the watermarked image file
    FILE *watermarkedImageFile = fopen("watermarked.png", "wb");
    if (watermarkedImageFile == NULL) {
        printf("Error opening the watermarked image file.\n");
        free(originalImageData);
        free(watermarkImageData);
        return EXIT_FAILURE;
    }

    // Write the watermarked image data to the file
    fwrite(originalImageData, 1, originalImageSize, watermarkedImageFile);
    fclose(watermarkedImageFile);

    // Free the allocated memory
    free(originalImageData);
    free(watermarkImageData);

    return EXIT_SUCCESS;
}