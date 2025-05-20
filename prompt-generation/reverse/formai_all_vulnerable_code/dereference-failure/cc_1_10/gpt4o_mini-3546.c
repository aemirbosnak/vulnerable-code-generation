//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // Magic number for BMP files
    unsigned int bfSize;        // Size of the BMP file
    unsigned short bfReserved1; // Reserved; must be zero
    unsigned short bfReserved2; // Reserved; must be zero
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPHeader;

// BMP info header
typedef struct {
    unsigned int biSize;          // Size of the info header
    int biWidth;                  // Width of the image
    int biHeight;                 // Height of the image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of the image data
    int biXPelsPerMeter;            // Horizontal resolution
    int biYPelsPerMeter;            // Vertical resolution
    unsigned int biClrUsed;        // Number of colors used
    unsigned int biClrImportant;    // Important colors
} BMPInfoHeader;
#pragma pack(pop)

void embedWatermark(const char* inputFilePath, const char* outputFilePath, const char* watermark) {
    FILE* bmpFile = fopen(inputFilePath, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Could not open input file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Print information about the image
    printf("BMP File: %s\n", inputFilePath);
    printf("Width: %d, Height: %d, BitCount: %d\n", bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, bmpInfoHeader.biBitCount);

    // Seek to pixel data
    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    unsigned char* pixelData = malloc(bmpInfoHeader.biSizeImage);
    fread(pixelData, 1, bmpInfoHeader.biSizeImage, bmpFile);
    fclose(bmpFile);

    // Embed the watermark
    size_t watermarkLength = strlen(watermark);
    for (size_t i = 0; i < watermarkLength && i < bmpInfoHeader.biSizeImage; i++) {
        pixelData[i] ^= watermark[i]; // Simple XOR to embed the watermark
    }

    // Write the modified data to new BMP file
    FILE* outFile = fopen(outputFilePath, "wb");
    if (!outFile) {
        fprintf(stderr, "Could not open output file.\n");
        free(pixelData);
        exit(1);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(pixelData, 1, bmpInfoHeader.biSizeImage, outFile);
    fclose(outFile);
    free(pixelData);

    printf("Watermark embedded successfully in %s!\n", outputFilePath);
}

void extractWatermark(const char* inputFilePath, size_t watermarkLength) {
    FILE* bmpFile = fopen(inputFilePath, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Could not open input file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    fseek(bmpFile, bmpHeader.bfOffBits, SEEK_SET);
    unsigned char* pixelData = malloc(bmpInfoHeader.biSizeImage);
    fread(pixelData, 1, bmpInfoHeader.biSizeImage, bmpFile);
    fclose(bmpFile);

    // Retrieve the watermark
    char* watermark = malloc(watermarkLength + 1);
    for (size_t i = 0; i < watermarkLength; i++) {
        watermark[i] = pixelData[i]; // The original watermark used the original pixel
    }
    watermark[watermarkLength] = '\0';

    printf("Extracted Watermark: %s\n", watermark);
    
    free(pixelData);
    free(watermark);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_bmp> <output_bmp> <watermark> <extract_length>\n", argv[0]);
        return 1;
    }

    const char* inputFilePath = argv[1];
    const char* outputFilePath = argv[2];
    const char* watermark = argv[3];
    size_t extractLength = atoi(argv[4]);

    embedWatermark(inputFilePath, outputFilePath, watermark);

    const char* extractedFilePath = "extracted_watermark.txt";
    printf("Attempting to extract watermark from the original image...\n");
    extractWatermark(outputFilePath, extractLength);

    return 0;
}