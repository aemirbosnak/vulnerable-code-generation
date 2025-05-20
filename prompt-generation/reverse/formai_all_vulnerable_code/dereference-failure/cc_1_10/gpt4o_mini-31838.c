//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)

// BMP file header structure
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPFileHeader;

// BMP information header structure
typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BMPInfoHeader;

#pragma pack(pop)

// Function prototypes
void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark);
void readBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, uint8_t **pixelData);
void writeBMP(const char *filename, BMPFileHeader fileHeader, BMPInfoHeader infoHeader, uint8_t *pixelData);
void modifyPixel(uint8_t *pixelData, const char *watermark, int watermarkLength);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    embedWatermark(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    uint8_t *pixelData = NULL;
    
    // Read the BMP file
    readBMP(inputFile, &fileHeader, &infoHeader, &pixelData);
    
    // Modify pixel data to embed the watermark
    modifyPixel(pixelData, watermark, strlen(watermark));
    
    // Write the modified BMP file
    writeBMP(outputFile, fileHeader, infoHeader, pixelData);
    
    free(pixelData);
    printf("Watermark embedded successfully!\n");
}

void readBMP(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader, uint8_t **pixelData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    // Allocate memory for pixel data
    *pixelData = (uint8_t *)malloc(infoHeader->biSizeImage);
    if (!*pixelData) {
        perror("Error allocating memory for pixel data");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixelData, infoHeader->biSizeImage, 1, file);
    
    fclose(file);
}

void writeBMP(const char *filename, BMPFileHeader fileHeader, BMPInfoHeader infoHeader, uint8_t *pixelData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    
    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    fwrite(pixelData, infoHeader.biSizeImage, 1, file);
    
    fclose(file);
}

void modifyPixel(uint8_t *pixelData, const char *watermark, int watermarkLength) {
    int pixelIndex = 0;
    int watermarkIndex = 0;
    
    // Embed watermark in the pixel data
    while (watermarkIndex < watermarkLength) {
        if (pixelIndex >= 3 * (1024 * 768)) // Rough limit for 1024x768 image
            break;
        
        pixelData[pixelIndex] = (pixelData[pixelIndex] & 0xFE) | (watermark[watermarkIndex] & 0x01);
        pixelIndex += 3; // Move to the next pixel (3 bytes - RGB)
        watermarkIndex++;
    }
}