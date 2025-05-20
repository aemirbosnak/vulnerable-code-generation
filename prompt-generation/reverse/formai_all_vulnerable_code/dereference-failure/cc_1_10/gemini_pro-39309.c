//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The secret watermark
char *watermark = "Hidden Treasure";

// Embed the watermark into the image data
char *embedWatermark(char *imageData, int imageSize) {
    int watermarkSize = strlen(watermark);
    for (int i = 0; i < watermarkSize; i++) {
        imageData[i % imageSize] ^= watermark[i];
    }
    return imageData;
}

// Extract the watermark from the image data
char *extractWatermark(char *imageData, int imageSize) {
    int watermarkSize = strlen(watermark);
    char *extractedWatermark = malloc(watermarkSize + 1);
    for (int i = 0; i < watermarkSize; i++) {
        extractedWatermark[i] = imageData[i % imageSize] ^ watermark[i];
    }
    extractedWatermark[watermarkSize] = '\0';
    return extractedWatermark;
}

// Print a message in a puzzle-like way
void printPuzzleMessage(char *message) {
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength; i++) {
        printf("%c%c", message[i], (i % 2) ? ' ' : '-');
    }
    printf("\n");
}

int main() {
    // Load the image data
    char *imageData = malloc(100);
    FILE *imageFile = fopen("image.jpg", "rb");
    fread(imageData, 1, 100, imageFile);
    fclose(imageFile);

    // Embed the watermark
    imageData = embedWatermark(imageData, 100);

    // Save the watermarked image
    FILE *watermarkedImageFile = fopen("watermarked.jpg", "wb");
    fwrite(imageData, 1, 100, watermarkedImageFile);
    fclose(watermarkedImageFile);

    // Extract the watermark
    char *extractedWatermark = extractWatermark(imageData, 100);

    // Print the watermark in a puzzle-like way
    printPuzzleMessage(extractedWatermark);
    free(extractedWatermark);
    free(imageData);
    return 0;
}