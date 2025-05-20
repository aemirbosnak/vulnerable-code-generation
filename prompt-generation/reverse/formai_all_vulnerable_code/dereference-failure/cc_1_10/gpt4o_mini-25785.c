//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];       // Bitmap identifier
    unsigned int bfSize;           // Size of the file
    unsigned short bfReserved1;    // Reserved
    unsigned short bfReserved2;    // Reserved
    unsigned int bfOffBits;        // Offset to start of Pixel Data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;           // Size of this header
    int biWidth;                   // Width of the image
    int biHeight;                  // Height of the image
    unsigned short biPlanes;       // Number of color planes
    unsigned short biBitCount;     // Bits per pixel
    unsigned int biCompression;     // Compression type
    unsigned int biSizeImage;      // Size of the image data
    int biXPixPerMeter;            // Horizontal resolution
    int biYPixPerMeter;            // Vertical resolution
    unsigned int biClrUsed;        // Number of colors used
    unsigned int biClrImportant;   // Number of important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;            // Blue
    unsigned char green;           // Green
    unsigned char red;             // Red
} PIXEL;

#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Unable to open input file");
        exit(1);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (bmpFileHeader.bfType[0] != 'B' || bmpFileHeader.bfType[1] != 'M') {
        fclose(file);
        fprintf(stderr, "Not a valid BMP file\n");
        exit(1);
    }

    // Print BMP header info
    printf("BMP Width: %d\n", bmpInfoHeader.biWidth);
    printf("BMP Height: %d\n", bmpInfoHeader.biHeight);
    printf("BMP Bit Count: %d\n", bmpInfoHeader.biBitCount);

    // Calculate size of pixel data
    fseek(file, bmpFileHeader.bfOffBits, SEEK_SET);
    long pixelDataSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * sizeof(PIXEL);
    PIXEL *pixels = (PIXEL *)malloc(pixelDataSize);
    fread(pixels, sizeof(PIXEL), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight, file);
    fclose(file);

    // Embed watermark into pixels (LSB method)
    size_t watermarkLen = strlen(watermark);
    for (size_t i = 0; i < watermarkLen && i < bmpInfoHeader.biWidth * bmpInfoHeader.biHeight; i++) {
        // embed one character of watermark as 8 bits
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (watermark[i] >> (7 - j)) & 1;
            if (bit) {
                pixels[i].red |= 1;  // Set LSB
            } else {
                pixels[i].red &= ~1; // Clear LSB
            }
            i++;
            if (i >= bmpInfoHeader.biWidth * bmpInfoHeader.biHeight) break;    
        }
        if (i >= bmpInfoHeader.biWidth * bmpInfoHeader.biHeight) break;
    }

    // Write modified pixels to a new BMP file
    file = fopen(outputFile, "wb");
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(PIXEL), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight, file);
    fclose(file);

    free(pixels);
    printf("Watermark embedded and saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input BMP file> <output BMP file> <watermark>\n", argv[0]);
        return 1;
    }

    embedWatermark(argv[1], argv[2], argv[3]);
    return 0;
}