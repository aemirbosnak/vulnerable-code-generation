//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold RGB pixel values
typedef struct {
    unsigned char r, g, b;
} RGB;

// Function to change the least significant bit (LSB)
void setBit(unsigned char *byte, unsigned char bit) {
    *byte = (*byte & 0xFE) | (bit & 0x01);
}

// Function to embed a watermark into the bitmap
void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Error opening input file");
        return;
    }
    
    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return;
    }

    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, in);
    
    // Extract the width and height from the header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Total number of pixels
    int pixelCount = width * height;
    RGB *pixels = (RGB *)malloc(pixelCount * sizeof(RGB));
    fread(pixels, sizeof(RGB), pixelCount, in);
    
    // Embed the watermark into the pixel’s LSBs
    int watermarkLength = strlen(watermark);
    int totalBits = watermarkLength * 8; // Total bits to encode
    for (int i = 0; i < totalBits; i++) {
        int bit = (watermark[i / 8] >> (7 - (i % 8))) & 0x01;
        RGB *pixel = &pixels[i]; // Assuming enough pixels
        if (i % 3 == 0) setBit(&pixel->r, bit);
        else if (i % 3 == 1) setBit(&pixel->g, bit);
        else setBit(&pixel->b, bit);
    }

    // Write modified pixels to the output file
    fwrite(header, sizeof(unsigned char), 54, out);
    fwrite(pixels, sizeof(RGB), pixelCount, out);
    
    free(pixels);
    fclose(in);
    fclose(out);
}

// Function to extract the watermark from the bitmap
void extractWatermark(const char *inputFile, char *watermark, int watermarkLength) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Error opening input file");
        return;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, in);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int pixelCount = width * height;
    RGB *pixels = (RGB *)malloc(pixelCount * sizeof(RGB));
    fread(pixels, sizeof(RGB), pixelCount, in);

    // Extract the watermark from the pixel’s LSBs
    memset(watermark, 0, watermarkLength + 1);
    for (int i = 0; i < watermarkLength * 8; i++) {
        RGB *pixel = &pixels[i]; // Assuming enough pixels
        unsigned char bit;
        if (i % 3 == 0) bit = pixel->r & 0x01;
        else if (i % 3 == 1) bit = pixel->g & 0x01;
        else bit = pixel->b & 0x01;

        watermark[i / 8] |= (bit << (7 - (i % 8)));
    }

    free(pixels);
    fclose(in);
}

int main() {
    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";
    const char *watermark = "Shocking Watermark!";

    printf("Embedding watermark...\n");
    embedWatermark(inputFile, outputFile, watermark);
    printf("Watermark embedded successfully!\n");

    char extracted[50];
    extractWatermark(outputFile, extracted, sizeof(extracted));
    printf("Extracted Watermark: %s\n", extracted);

    return 0;
}