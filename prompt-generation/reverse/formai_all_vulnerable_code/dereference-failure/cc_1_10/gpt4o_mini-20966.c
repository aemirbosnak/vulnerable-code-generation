//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure that the struct is packed

typedef struct {
    uint16_t type;        // Magic number for BMP files (should be 0x4D42)
    uint32_t size;        // Size of the BMP file
    uint16_t reserved1;   // Reserved; must be zero
    uint16_t reserved2;   // Reserved; must be zero
    uint32_t offset;      // Offset to start of pixel data
} BMPHeader;

typedef struct {
    uint32_t size;        // Size of this header (40 bytes)
    int32_t width;        // Width of the bitmap in pixels
    int32_t height;       // Height of the bitmap in pixels
    uint16_t planes;      // Number of color planes (must be 1)
    uint16_t bitCount;    // Number of bits per pixel
    uint32_t compression;  // Compression type (0 for none)
    uint32_t sizeImage;   // Size of the pixel data
    int32_t xPixelsPerMeter; // Horizontal resolution (pixels/meter) - not used here
    int32_t yPixelsPerMeter; // Vertical resolution (pixels/meter) - not used here
    uint32_t colorsUsed;    // Number of colors in the palette - not used here
    uint32_t colorsImportant; // Important colors - not used here
} BMPInfoHeader;

#pragma pack(pop)

void invertColors(uint8_t *pixelData, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        pixelData[i] = 255 - pixelData[i];     // Invert Red
        pixelData[i + 1] = 255 - pixelData[i + 1]; // Invert Green
        pixelData[i + 2] = 255 - pixelData[i + 2]; // Invert Blue
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    if (bmpHeader.type != 0x4D42) {
        printf("Not a valid BMP file\n");
        fclose(inputFile);
        return 1;
    }

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpInfoHeader.bitCount != 24) {
        printf("Only 24-bit BMP images are supported\n");
        fclose(inputFile);
        return 1;
    }

    int width = bmpInfoHeader.width;
    int height = bmpInfoHeader.height;
    size_t pixelDataSize = width * height * 3;
    uint8_t *pixelData = (uint8_t *)malloc(pixelDataSize);

    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    fread(pixelData, 1, pixelDataSize, inputFile);
    fclose(inputFile);

    invertColors(pixelData, width, height);

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(pixelData);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fseek(outputFile, bmpHeader.offset, SEEK_SET);
    fwrite(pixelData, 1, pixelDataSize, outputFile);
    fclose(outputFile);

    free(pixelData);
    printf("Image inversion complete. Saved to %s\n", argv[2]);
    return 0;
}