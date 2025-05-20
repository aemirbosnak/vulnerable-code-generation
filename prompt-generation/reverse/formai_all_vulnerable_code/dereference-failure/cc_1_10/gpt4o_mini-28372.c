//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;       // Magic identifier
    uint32_t bfSize;       // File size in bytes
    uint16_t bfReserved1;  // Not used
    uint16_t bfReserved2;  // Not used
    uint32_t bfOffBits;    // Offset to data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Image size in bytes
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Number of colors
    uint32_t biClrImportant;    // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;   // Blue component
    uint8_t green;  // Green component
    uint8_t red;    // Red component
} RGB;
#pragma pack(pop)

void loadBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB ***imageData, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    *width = infoHeader->biWidth;
    *height = abs(infoHeader->biHeight);
    
    *imageData = (RGB **)malloc(*height * sizeof(RGB *));
    for (int i = 0; i < *height; i++) {
        (*imageData)[i] = (RGB *)malloc(*width * sizeof(RGB));
        fread((*imageData)[i], sizeof(RGB), *width, file);
        fseek(file, (4 - (*width * sizeof(RGB)) % 4) % 4, SEEK_CUR);
    }

    fclose(file);
}

void saveBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, RGB **imageData, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);

    for (int i = 0; i < height; i++) {
        fwrite(imageData[i], sizeof(RGB), width, file);
        uint8_t padding[3] = {0, 0, 0};
        fwrite(padding, (4 - (width * sizeof(RGB)) % 4) % 4, 1, file);
    }

    fclose(file);
}

void applyGrayscale(RGB **imageData, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t gray = (imageData[i][j].red + imageData[i][j].green + imageData[i][j].blue) / 3;
            imageData[i][j].red = gray;
            imageData[i][j].green = gray;
            imageData[i][j].blue = gray;
        }
    }
}

void applyInversion(RGB **imageData, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            imageData[i][j].red = 255 - imageData[i][j].red;
            imageData[i][j].green = 255 - imageData[i][j].green;
            imageData[i][j].blue = 255 - imageData[i][j].blue;
        }
    }
}

void freeImageData(RGB **imageData, int height) {
    for (int i = 0; i < height; i++) {
        free(imageData[i]);
    }
    free(imageData);
}

int main() {
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    RGB **imageData;
    int width, height;

    loadBMP("input.bmp", &fileHeader, &infoHeader, &imageData, &width, &height);
    
    applyGrayscale(imageData, width, height);
    
    saveBMP("output_gray.bmp", &fileHeader, &infoHeader, imageData, width, height);

    applyInversion(imageData, width, height);
    
    saveBMP("output_inverted.bmp", &fileHeader, &infoHeader, imageData, width, height);
    
    freeImageData(imageData, height);
    
    printf("Image transformations completed successfully.\n");
    return 0;
}