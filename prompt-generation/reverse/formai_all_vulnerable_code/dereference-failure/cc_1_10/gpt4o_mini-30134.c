//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure proper packing for BMP file header
typedef struct {
    uint16_t bfType;        // File type
    uint32_t bfSize;        // File size in bytes
    uint16_t bfReserved1;   // Reserved
    uint16_t bfReserved2;   // Reserved
    uint32_t bfOffBits;     // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t biWidth;          // Width in pixels
    int32_t biHeight;         // Height in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Image size
    int32_t biXPelsPerMeter;   // Pixels per meter in X
    int32_t biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors in the palette
    uint32_t biClrImportant;    // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void flipImageHorizontally(RGB **imageData, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            RGB temp = imageData[y][x];
            imageData[y][x] = imageData[y][width - x - 1];
            imageData[y][width - x - 1] = temp;
        }
    }
}

void changeBrightness(RGB **imageData, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int newRed = imageData[y][x].red + brightness;
            int newGreen = imageData[y][x].green + brightness;
            int newBlue = imageData[y][x].blue + brightness;

            imageData[y][x].red = newRed < 0 ? 0 : (newRed > 255 ? 255 : newRed);
            imageData[y][x].green = newGreen < 0 ? 0 : (newGreen > 255 ? 255 : newGreen);
            imageData[y][x].blue = newBlue < 0 ? 0 : (newBlue > 255 ? 255 : newBlue);
        }
    }
}

void freeImageData(RGB **imageData, int height) {
    for (int i = 0; i < height; i++) {
        free(imageData[i]);
    }
    free(imageData);
}

RGB **loadBMP(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    *width = infoHeader.biWidth;
    *height = infoHeader.biHeight;

    RGB **imageData = malloc(*height * sizeof(RGB *));
    for (int i = 0; i < *height; i++) {
        imageData[i] = malloc(*width * sizeof(RGB));
        fseek(file, fileHeader.bfOffBits + (*height - 1 - i) * (*width * sizeof(RGB)), SEEK_SET);
        fread(imageData[i], sizeof(RGB), *width, file);
    }

    fclose(file);
    return imageData;
}

void saveBMP(const char *filename, RGB **imageData, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    BMPFileHeader fileHeader = {0x4D42}; // "BM"
    BMPInfoHeader infoHeader = { };

    infoHeader.biSize = sizeof(BMPInfoHeader);
    infoHeader.biWidth = width;
    infoHeader.biHeight = height;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24; // 24 bits per pixel
    infoHeader.biSizeImage = width * height * sizeof(RGB);
    fileHeader.bfOffBits = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    fileHeader.bfSize = fileHeader.bfOffBits + infoHeader.biSizeImage;

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    for (int i = 0; i < height; i++) {
        fwrite(imageData[height - 1 - i], sizeof(RGB), width, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input BMP> <output BMP> <brightness>\n", argv[0]);
        return 1;
    }

    int width, height;
    RGB **imageData = loadBMP(argv[1], &width, &height);
    if (!imageData) {
        return 1;
    }

    int brightness = atoi(argv[3]);
    changeBrightness(imageData, width, height, brightness);
    flipImageHorizontally(imageData, width, height);
    
    saveBMP(argv[2], imageData, width, height);

    freeImageData(imageData, height);
    return 0;
}