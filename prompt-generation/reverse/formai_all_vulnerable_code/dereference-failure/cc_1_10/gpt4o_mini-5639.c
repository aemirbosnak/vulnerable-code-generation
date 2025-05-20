//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} DIBHeader;

#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, inFile);

    if (bmpHeader.bfType != 0x4D42) { // Check for BMP file signature
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    unsigned char *pixels = (unsigned char *)malloc(dibHeader.biWidth * dibHeader.biHeight * 3);
    if (pixels == NULL) {
        perror("Unable to allocate memory for pixel data");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    fseek(inFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixels, dibHeader.biWidth * dibHeader.biHeight * 3, 1, inFile);
    fclose(inFile);

    // Embed watermark into the pixel array
    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; i++) {
        for (int j = 0; j < 8; j++) {
            int pixelIndex = (i * 8 + j) * 3; // 3 bytes per pixel (BGR)
            if (pixelIndex < dibHeader.biWidth * dibHeader.biHeight * 3) {
                // Modify the LSB of the blue channel
                pixels[pixelIndex] = (pixels[pixelIndex] & 0xFE) | ((watermark[i] >> (7 - j)) & 0x01);
            }
        }
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, outFile);
    fseek(outFile, bmpHeader.bfOffBits, SEEK_SET);
    fwrite(pixels, dibHeader.biWidth * dibHeader.biHeight * 3, 1, outFile);
    
    free(pixels);
    fclose(outFile);
}

void extractWatermark(const char *inputFile, int watermarkLength) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, inFile);

    unsigned char *pixels = (unsigned char *)malloc(dibHeader.biWidth * dibHeader.biHeight * 3);
    if (pixels == NULL) {
        perror("Unable to allocate memory for pixel data");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    fseek(inFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixels, dibHeader.biWidth * dibHeader.biHeight * 3, 1, inFile);
    fclose(inFile);

    char extractedWatermark[watermarkLength + 1];
    extractedWatermark[watermarkLength] = '\0';

    for (int i = 0; i < watermarkLength; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            int pixelIndex = (i * 8 + j) * 3; // 3 bytes per pixel (BGR)
            if (pixelIndex < dibHeader.biWidth * dibHeader.biHeight * 3) {
                byte |= (pixels[pixelIndex] & 0x01) << (7 - j);
            }
        }
        extractedWatermark[i] = byte;
    }

    printf("Extracted Watermark: %s\n", extractedWatermark);
    
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    embedWatermark(inputFile, outputFile, watermark);
    printf("Watermark embedded successfully.\n");

    extractWatermark(outputFile, strlen(watermark));

    return EXIT_SUCCESS;
}