//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// BMP file header structure
#pragma pack(push, 1)
typedef struct BMPHeader {
    uint16_t fileType;      // File type (should be 'BM')
    uint32_t fileSize;      // Size of the file in bytes
    uint16_t reserved1;     // Reserved; actual value depends on the application that creates the image
    uint16_t reserved2;     // Reserved; actual value depends on the application that creates the image
    uint32_t offsetData;    // Offset to start of pixel data
} BMPHeader;

typedef struct BMPInfoHeader {
    uint32_t size;          // Size of this header (in bytes)
    int32_t width;          // Width of the bitmap in pixels
    int32_t height;         // Height of the bitmap in pixels
    uint16_t planes;        // Number of color planes (must be 1)
    uint16_t bitCount;      // Number of bits per pixel
    uint32_t compression;    // Compression type (0 = uncompressed)
    uint32_t sizeImage;     // Size of the image data in bytes
    int32_t xPixelsPerMeter; // Horizontal resolution (pixels per meter)
    int32_t yPixelsPerMeter; // Vertical resolution (pixels per meter)
    uint32_t colorsUsed;     // Number of colors in the color palette
    uint32_t colorsImportant; // Important colors; generally ignored
} BMPInfoHeader;

typedef struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

// Function to read a BMP file
int readBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, Pixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Allocate memory for pixel data
    int width = infoHeader->width;
    int height = abs(infoHeader->height);
    *pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    
    // Move file pointer to the pixel data
    fseek(file, header->offsetData, SEEK_SET);
    fread(*pixels, sizeof(Pixel), width * height, file);

    fclose(file);
    return 1;
}

// Function to write a BMP file
int writeBMP(const char *filename, BMPHeader header, BMPInfoHeader infoHeader, Pixel *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Cannot write to file %s\n", filename);
        return 0;
    }

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    fwrite(pixels, sizeof(Pixel), infoHeader.width * abs(infoHeader.height), file);

    fclose(file);
    return 1;
}

// Function to invert colors of the image
void invertColors(Pixel *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

// Main program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.bbm> <output.bbm>\n", argv[0]);
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;
    Pixel *pixels;

    if (!readBMP(argv[1], &header, &infoHeader, &pixels)) {
        return 1;
    }

    invertColors(pixels, infoHeader.width, abs(infoHeader.height));

    if (!writeBMP(argv[2], header, infoHeader, pixels)) {
        free(pixels);
        return 1;
    }

    printf("Surprisingly, your image has been inverted and saved as %s!\n", argv[2]);

    // Cleanup
    free(pixels);
    return 0;
}