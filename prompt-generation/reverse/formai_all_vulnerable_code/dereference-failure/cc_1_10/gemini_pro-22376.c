//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Embed the watermark in the image
unsigned char* embedWatermark(unsigned char* image, int imageSize, unsigned char* watermark, int watermarkSize) {
    // Check if the image is large enough to hold the watermark
    if (imageSize < watermarkSize) {
        printf("Error: The image is not large enough to hold the watermark.\n");
        return NULL;
    }

    // Embed the watermark in the image using the LSB technique
    for (int i = 0; i < watermarkSize; i++) {
        image[i] = (image[i] & 0xFE) | (watermark[i] & 0x01);
    }

    return image;
}

// Extract the watermark from the image
unsigned char* extractWatermark(unsigned char* image, int imageSize, int watermarkSize) {
    // Extract the watermark from the image using the LSB technique
    unsigned char* watermark = malloc(watermarkSize);
    for (int i = 0; i < watermarkSize; i++) {
        watermark[i] = image[i] & 0x01;
    }

    return watermark;
}

int main() {
    // Load the image
    FILE* imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open the image file.\n");
        return 1;
    }

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    unsigned char* image = malloc(imageSize);
    fread(image, 1, imageSize, imageFile);
    fclose(imageFile);

    // Load the watermark
    FILE* watermarkFile = fopen("watermark.bmp", "rb");
    if (watermarkFile == NULL) {
        printf("Error: Could not open the watermark file.\n");
        return 1;
    }

    fseek(watermarkFile, 0, SEEK_END);
    long watermarkSize = ftell(watermarkFile);
    rewind(watermarkFile);

    unsigned char* watermark = malloc(watermarkSize);
    fread(watermark, 1, watermarkSize, watermarkFile);
    fclose(watermarkFile);

    // Embed the watermark in the image
    unsigned char* watermarkedImage = embedWatermark(image, imageSize, watermark, watermarkSize);

    // Save the watermarked image
    FILE* watermarkedImageFile = fopen("watermarkedImage.bmp", "wb");
    if (watermarkedImageFile == NULL) {
        printf("Error: Could not open the watermarked image file.\n");
        return 1;
    }

    fwrite(watermarkedImage, 1, imageSize, watermarkedImageFile);
    fclose(watermarkedImageFile);

    // Extract the watermark from the watermarked image
    unsigned char* extractedWatermark = extractWatermark(watermarkedImage, imageSize, watermarkSize);

    // Compare the extracted watermark to the original watermark
    int areEqual = 1;
    for (int i = 0; i < watermarkSize; i++) {
        if (extractedWatermark[i] != watermark[i]) {
            areEqual = 0;
            break;
        }
    }

    if (areEqual) {
        printf("Success: The watermark was successfully extracted from the image.\n");
    } else {
        printf("Error: The extracted watermark does not match the original watermark.\n");
    }

    // Free the memory
    free(image);
    free(watermark);
    free(watermarkedImage);
    free(extractedWatermark);

    return 0;
}