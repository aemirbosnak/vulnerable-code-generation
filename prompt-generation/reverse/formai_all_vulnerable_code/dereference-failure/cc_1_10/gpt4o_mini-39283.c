//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;       // Magic number
    unsigned int bfSize;        // Size of the BMP file
    unsigned short bfReserved1;  // Reserved
    unsigned short bfReserved2;  // Reserved
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;         // Size of this header
    int biWidth;                 // Width of the bitmap in pixels
    int biHeight;                // Height of the bitmap in pixels
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;   // Compression type
    unsigned int biSizeImage;    // Image size
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color palette
    unsigned int biClrImportant;   // Important colors
} BMPInfoHeader;

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (bmpFile == NULL) {
        perror("Error opening input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Navigate to pixel data
    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    int pixelCount = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;   
    unsigned char *pixels = malloc(pixelCount * 3); // 3 bytes for RGB
    fread(pixels, 3, pixelCount, bmpFile);
    fclose(bmpFile);

    // Embed watermark using LSB
    int watermarkLen = strlen(watermark);
    for (int i = 0; i < watermarkLen; i++) {
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j < pixelCount) {
                pixels[i * 8 + j * 3] = (pixels[i * 8 + j * 3] & 0xFE) | ((watermark[i] >> (7 - j)) & 1);
            }
        }
    }

    // Save new BMP file
    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output BMP file");
        free(pixels);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(pixels, 3, pixelCount, outFile);
    
    free(pixels);
    fclose(outFile);
}

void extractWatermark(const char *inputFile, char *watermark, int maxLen) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (bmpFile == NULL) {
        perror("Error opening BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Navigate to pixel data
    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    int pixelCount = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;   
    unsigned char *pixels = malloc(pixelCount * 3); // 3 bytes for RGB
    fread(pixels, 3, pixelCount, bmpFile);
    fclose(bmpFile);

    int watermarkLen = 0;
    for (int i = 0; i < maxLen; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j < pixelCount) {
                c |= ((pixels[i * 8 + j * 3] & 1) << (7 - j));
            }
        }
        if (c == '\0') break; // Invalid character
        watermark[i] = c;
        watermarkLen++;
    }
    watermark[watermarkLen] = '\0';

    free(pixels);
}

int main() {
    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";
    const char *watermarkText = "Watermark!";
    
    // Embed watermark
    embedWatermark(inputFile, outputFile, watermarkText);
    printf("Watermark embedded successfully.\n");

    // Extract watermark
    char extractedWatermark[100];
    extractWatermark(outputFile, extractedWatermark, sizeof(extractedWatermark));
    printf("Extracted watermark: %s\n", extractedWatermark);

    return 0;
}