//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to embed the watermark
void embedWatermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermarkWidth, int watermarkHeight) {
    int i, j, k, l;
    double factor = 0.01;

    // Loop through each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get the pixel value
            unsigned char pixelValue = image[i * width + j];

            // Get the corresponding watermark pixel value
            unsigned char watermarkValue = watermark[(i % watermarkHeight) * watermarkWidth + (j % watermarkWidth)];

            // Embed the watermark by adding it to the pixel value
            image[i * width + j] = pixelValue + (factor * watermarkValue);
        }
    }
}

// Function to extract the watermark
void extractWatermark(unsigned char *image, int width, int height, unsigned char *watermark, int watermarkWidth, int watermarkHeight) {
    int i, j, k, l;
    double factor = 0.01;

    // Loop through each pixel in the image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get the pixel value
            unsigned char pixelValue = image[i * width + j];

            // Get the corresponding watermark pixel value
            unsigned char watermarkValue = watermark[(i % watermarkHeight) * watermarkWidth + (j % watermarkWidth)];

            // Extract the watermark by subtracting the pixel value from it
            watermark[i * width + j] = (pixelValue - (factor * watermarkValue)) / factor;
        }
    }
}

// Main function
int main() {
    // Load the image
    unsigned char *image = (unsigned char *)malloc(sizeof(unsigned char) * 256 * 256);
    FILE *imageFile = fopen("image.bmp", "rb");
    fread(image, sizeof(unsigned char), 256 * 256, imageFile);
    fclose(imageFile);

    // Load the watermark
    unsigned char *watermark = (unsigned char *)malloc(sizeof(unsigned char) * 64 * 64);
    FILE *watermarkFile = fopen("watermark.bmp", "rb");
    fread(watermark, sizeof(unsigned char), 64 * 64, watermarkFile);
    fclose(watermarkFile);

    // Embed the watermark in the image
    embedWatermark(image, 256, 256, watermark, 64, 64);

    // Save the watermarked image
    FILE *watermarkedImageFile = fopen("watermarkedImage.bmp", "wb");
    fwrite(image, sizeof(unsigned char), 256 * 256, watermarkedImageFile);
    fclose(watermarkedImageFile);

    // Extract the watermark from the watermarked image
    unsigned char *extractedWatermark = (unsigned char *)malloc(sizeof(unsigned char) * 64 * 64);
    extractWatermark(image, 256, 256, extractedWatermark, 64, 64);

    // Save the extracted watermark
    FILE *extractedWatermarkFile = fopen("extractedWatermark.bmp", "wb");
    fwrite(extractedWatermark, sizeof(unsigned char), 64 * 64, extractedWatermarkFile);
    fclose(extractedWatermarkFile);

    // Free the memory
    free(image);
    free(watermark);
    free(extractedWatermark);

    return 0;
}