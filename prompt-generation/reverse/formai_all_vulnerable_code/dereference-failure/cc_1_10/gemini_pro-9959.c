//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Embed the watermark into the host image
void embedWatermark(unsigned char *hostImage, int hostWidth, int hostHeight, unsigned char *watermark, int watermarkWidth, int watermarkHeight) {
    // Calculate the number of bits in the watermark
    int watermarkBitCount = watermarkWidth * watermarkHeight * 8;

    // Calculate the number of bits per pixel in the host image
    int hostBitCount = hostWidth * hostHeight * 8;

    // Calculate the number of bits to embed from the watermark
    int embedBitCount = watermarkBitCount <= hostBitCount ? watermarkBitCount : hostBitCount;

    // Embed the watermark bits into the host image's least significant bits
    int hostBitIndex = 0;
    int watermarkBitIndex = 0;
    for (int i = 0; i < embedBitCount; i++) {
        int bit = watermark[watermarkBitIndex / 8] & (1 << (7 - (watermarkBitIndex % 8)));
        hostImage[hostBitIndex / 8] &= ~(1 << (7 - (hostBitIndex % 8)));
        hostImage[hostBitIndex / 8] |= bit << (7 - (hostBitIndex % 8));

        hostBitIndex++;
        watermarkBitIndex++;
    }
}

// Extract the watermark from the watermarked image
void extractWatermark(unsigned char *watermarkedImage, int watermarkedWidth, int watermarkedHeight, unsigned char *watermark, int watermarkWidth, int watermarkHeight) {
    // Calculate the number of bits in the watermark
    int watermarkBitCount = watermarkWidth * watermarkHeight * 8;

    // Calculate the number of bits per pixel in the watermarked image
    int watermarkedBitCount = watermarkedWidth * watermarkedHeight * 8;

    // Calculate the number of bits to extract from the watermarked image
    int extractBitCount = watermarkBitCount <= watermarkedBitCount ? watermarkBitCount : watermarkedBitCount;

    // Extract the watermark bits from the watermarked image's least significant bits
    int watermarkedBitIndex = 0;
    int watermarkBitIndex = 0;
    for (int i = 0; i < extractBitCount; i++) {
        int bit = watermarkedImage[watermarkedBitIndex / 8] & (1 << (7 - (watermarkedBitIndex % 8)));
        watermark[watermarkBitIndex / 8] &= ~(1 << (7 - (watermarkBitIndex % 8)));
        watermark[watermarkBitIndex / 8] |= bit << (7 - (watermarkBitIndex % 8));

        watermarkedBitIndex++;
        watermarkBitIndex++;
    }
}

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 5) {
        printf("Usage: %s hostImage watermark embeddedImage extractedWatermark\n", argv[0]);
        return 1;
    }

    // Load the host image
    FILE *hostImageFile = fopen(argv[1], "rb");
    if (hostImageFile == NULL) {
        printf("Error: Could not open the host image file\n");
        return 1;
    }
    fseek(hostImageFile, 0, SEEK_END);
    long hostImageSize = ftell(hostImageFile);
    fseek(hostImageFile, 0, SEEK_SET);
    unsigned char *hostImage = malloc(hostImageSize);
    fread(hostImage, 1, hostImageSize, hostImageFile);
    fclose(hostImageFile);

    // Load the watermark
    FILE *watermarkFile = fopen(argv[2], "rb");
    if (watermarkFile == NULL) {
        printf("Error: Could not open the watermark file\n");
        return 1;
    }
    fseek(watermarkFile, 0, SEEK_END);
    long watermarkSize = ftell(watermarkFile);
    fseek(watermarkFile, 0, SEEK_SET);
    unsigned char *watermark = malloc(watermarkSize);
    fread(watermark, 1, watermarkSize, watermarkFile);
    fclose(watermarkFile);

    // Embed the watermark into the host image
    embedWatermark(hostImage, 512, 512, watermark, 64, 64);

    // Save the watermarked image
    FILE *embeddedImageFile = fopen(argv[3], "wb");
    if (embeddedImageFile == NULL) {
        printf("Error: Could not open the embedded image file\n");
        return 1;
    }
    fwrite(hostImage, 1, hostImageSize, embeddedImageFile);
    fclose(embeddedImageFile);

    // Extract the watermark from the watermarked image
    unsigned char *extractedWatermark = malloc(watermarkSize);
    extractWatermark(hostImage, 512, 512, extractedWatermark, 64, 64);

    // Save the extracted watermark
    FILE *extractedWatermarkFile = fopen(argv[4], "wb");
    if (extractedWatermarkFile == NULL) {
        printf("Error: Could not open the extracted watermark file\n");
        return 1;
    }
    fwrite(extractedWatermark, 1, watermarkSize, extractedWatermarkFile);
    fclose(extractedWatermarkFile);

    free(hostImage);
    free(watermark);
    free(extractedWatermark);

    return 0;
}