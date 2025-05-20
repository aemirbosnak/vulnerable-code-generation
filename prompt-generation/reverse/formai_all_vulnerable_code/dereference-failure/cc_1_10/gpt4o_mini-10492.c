//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap
    int32_t  biHeight;        // Height of the bitmap
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of raw bitmap data
    int32_t  biXPelsPerMeter;  // Pixels per meter in X
    int32_t  biYPelsPerMeter;  // Pixels per meter in Y
    uint32_t biClrUsed;       // Number of colors used
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void flipImageHorizontally(RGB **pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            RGB temp = pixels[y][x];
            pixels[y][x] = pixels[y][width - 1 - x];
            pixels[y][width - 1 - x] = temp;
        }
    }
}

void flipImageVertically(RGB **pixels, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            RGB temp = pixels[y][x];
            pixels[y][x] = pixels[height - 1 - y][x];
            pixels[height - 1 - y][x] = temp;
        }
    }
}

void changeBrightness(RGB **pixels, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int newRed = pixels[y][x].red + brightness;
            int newGreen = pixels[y][x].green + brightness;
            int newBlue = pixels[y][x].blue + brightness;

            pixels[y][x].red = (newRed < 0) ? 0 : (newRed > 255) ? 255 : newRed;
            pixels[y][x].green = (newGreen < 0) ? 0 : (newGreen > 255) ? 255 : newGreen;
            pixels[y][x].blue = (newBlue < 0) ? 0 : (newBlue > 255) ? 255 : newBlue;
        }
    }
}

void saveImage(const char *filename, BITMAPFILEHEADER bfHeader, BITMAPINFOHEADER biHeader, RGB **pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fwrite(&bfHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&biHeader, sizeof(BITMAPINFOHEADER), 1, file);
    for (int y = 0; y < biHeader.biHeight; y++) {
        fwrite(pixels[y], sizeof(RGB), biHeader.biWidth, file);
    }

    fclose(file);
}

RGB **loadImage(const char *filename, BITMAPFILEHEADER *bfHeader, BITMAPINFOHEADER *biHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fread(bfHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(biHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfHeader->bfType != 0x4D42) {
        printf("Not a BMP file\n");
        fclose(file);
        return NULL;
    }

    RGB **pixels = malloc(biHeader->biHeight * sizeof(RGB *));
    for (int y = 0; y < biHeader->biHeight; y++) {
        pixels[y] = malloc(biHeader->biWidth * sizeof(RGB));
    }

    fseek(file, bfHeader->bfOffBits, SEEK_SET);
    for (int y = 0; y < biHeader->biHeight; y++) {
        fread(pixels[y], sizeof(RGB), biHeader->biWidth, file);
    }

    fclose(file);
    return pixels;
}

void freeImage(RGB **pixels, int height) {
    for (int y = 0; y < height; y++) {
        free(pixels[y]);
    }
    free(pixels);
}

int main() {
    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";
    RGB **pixels = loadImage(inputFile, &bfHeader, &biHeader);

    if (!pixels) {
        return 1;
    }

    printf("Loaded image: %dx%d\n", biHeader.biWidth, biHeader.biHeight);
    flipImageHorizontally(pixels, biHeader.biWidth, biHeader.biHeight);
    changeBrightness(pixels, biHeader.biWidth, biHeader.biHeight, 30); // Increase brightness by 30
    saveImage(outputFile, bfHeader, biHeader, pixels);
    printf("Processed and saved image to %s\n", outputFile);

    freeImage(pixels, biHeader.biHeight);
    return 0;
}