//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  bfType[2];
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int    biSize;
    int             biWidth;
    int             biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    int             biXPelsPerMeter;
    int             biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

void adjust_brightness(RGB* pixel, int adjustment) {
    pixel->red = (pixel->red + adjustment > 255) ? 255 : (pixel->red + adjustment < 0) ? 0 : pixel->red + adjustment;
    pixel->green = (pixel->green + adjustment > 255) ? 255 : (pixel->green + adjustment < 0) ? 0 : pixel->green + adjustment;
    pixel->blue = (pixel->blue + adjustment > 255) ? 255 : (pixel->blue + adjustment < 0) ? 0 : pixel->blue + adjustment;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness adjustment>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        fprintf(stderr, "Could not open input file.\n");
        return 1;
    }

    BITMAPFILEHEADER bmpHeader;
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    if (bmpHeader.bfType[0] != 'B' || bmpHeader.bfType[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        return 1;
    }

    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    // Move file pointer to the start of pixel data
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);

    // Allocate memory for the pixel data
    int padding = (4 - (bmpInfoHeader.biWidth * sizeof(RGB)) % 4) % 4;
    int imgSize = (sizeof(RGB) * bmpInfoHeader.biWidth + padding) * bmpInfoHeader.biHeight;
    RGB* pixels = (RGB*)malloc(imgSize);
    fread(pixels, imgSize, 1, inputFile);
    fclose(inputFile);

    int brightnessAdjustment = atoi(argv[3]);
    
    // Adjust the brightness of each pixel
    for (int i = 0; i < bmpInfoHeader.biWidth * bmpInfoHeader.biHeight; i++) {
        adjust_brightness(&pixels[i], brightnessAdjustment);
    }

    // Save the modified image
    FILE* outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        fprintf(stderr, "Could not open output file.\n");
        free(pixels);
        return 1;
    }

    fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    
    // Write pixel data to file with padding
    fseek(outputFile, bmpHeader.bfOffBits, SEEK_SET);
    for (int i = 0; i < bmpInfoHeader.biHeight; i++) {
        fwrite(&pixels[i * bmpInfoHeader.biWidth], sizeof(RGB), bmpInfoHeader.biWidth, outputFile);
        unsigned char pad[3] = {0, 0, 0}; // padding for 4-byte alignment
        fwrite(pad, padding, 1, outputFile);
    }

    fclose(outputFile);
    free(pixels);
    printf("Image processing complete!\n");
    return 0;
}