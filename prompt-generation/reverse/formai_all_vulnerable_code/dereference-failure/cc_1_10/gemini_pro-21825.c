//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 512
#define IMG_HEIGHT 512

// Watermark data
unsigned char watermark[32] = {0xDE, 0xAD, 0xBE, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Embeds the watermark into the image data
void embedWatermark(unsigned char *imgData, unsigned char *watermark, int imgWidth, int imgHeight) {
    // Calculate the number of bits to embed per pixel
    int bitsPerPixel = (int) ceil(log2(strlen(watermark) * 8) / (imgWidth * imgHeight));

    // Embed the watermark
    int watermarkIndex = 0;
    for (int i = 0; i < imgWidth * imgHeight; i++) {
        // Get the current pixel value
        unsigned char pixel = imgData[i];

        // Extract the least significant bit of the pixel
        unsigned char lsb = pixel & 1;

        // Replace the lsb with the watermark bit
        if (watermarkIndex < strlen(watermark) * 8) {
            unsigned char watermarkBit = (watermark[watermarkIndex / 8] >> (watermarkIndex % 8)) & 1;
            pixel = (pixel & 0xFE) | watermarkBit;
            watermarkIndex++;
        }

        // Update the image data
        imgData[i] = pixel;
    }
}

// Extracts the watermark from the image data
void extractWatermark(unsigned char *imgData, unsigned char *watermark, int imgWidth, int imgHeight) {
    // Calculate the number of bits to extract per pixel
    int bitsPerPixel = (int) ceil(log2(strlen(watermark) * 8) / (imgWidth * imgHeight));

    // Extract the watermark
    int watermarkIndex = 0;
    for (int i = 0; i < imgWidth * imgHeight; i++) {
        // Get the current pixel value
        unsigned char pixel = imgData[i];

        // Extract the least significant bit of the pixel
        unsigned char lsb = pixel & 1;

        // Add the lsb to the watermark
        if (watermarkIndex < strlen(watermark) * 8) {
            watermark[watermarkIndex / 8] |= (lsb << (watermarkIndex % 8));
            watermarkIndex++;
        }
    }
}

// Main function
int main() {
    // Load the image data
    unsigned char imgData[IMG_WIDTH * IMG_HEIGHT];
    FILE *imgFile = fopen("image.bmp", "rb");
    fread(imgData, sizeof(unsigned char), IMG_WIDTH * IMG_HEIGHT, imgFile);
    fclose(imgFile);

    // Embed the watermark
    embedWatermark(imgData, watermark, IMG_WIDTH, IMG_HEIGHT);

    // Save the watermarked image
    imgFile = fopen("watermarked_image.bmp", "wb");
    fwrite(imgData, sizeof(unsigned char), IMG_WIDTH * IMG_HEIGHT, imgFile);
    fclose(imgFile);

    // Extract the watermark
    unsigned char extractedWatermark[32];
    memset(extractedWatermark, 0, 32);
    extractWatermark(imgData, extractedWatermark, IMG_WIDTH, IMG_HEIGHT);

    // Compare the original and extracted watermarks
    int matches = 0;
    for (int i = 0; i < 32; i++) {
        if (watermark[i] == extractedWatermark[i]) {
            matches++;
        }
    }

    // Print the results
    printf("Watermark matches: %d/%d\n", matches, 32);

    return 0;
}