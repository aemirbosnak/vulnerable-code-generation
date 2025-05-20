//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
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

unsigned char* loadBMP(const char* filename, BMPHeader* bmpHeader, DIBHeader* dibHeader) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(dibHeader, sizeof(DIBHeader), 1, file);

    if (bmpHeader->bfType != 0x4D42) {
        fclose(file);
        return NULL; 
    }

    unsigned char* pixelData = (unsigned char*)malloc(dibHeader->biSizeImage);
    fseek(file, bmpHeader->bfOffBits, SEEK_SET);
    fread(pixelData, dibHeader->biSizeImage, 1, file);
    fclose(file);
    return pixelData;
}

void saveBMP(const char* filename, BMPHeader bmpHeader, DIBHeader dibHeader, unsigned char* pixelData) {
    FILE* file = fopen(filename, "wb");
    if (!file) return;

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fwrite(pixelData, dibHeader.biSizeImage, 1, file);
    fclose(file);
}

void embedWatermark(unsigned char* image, const char* watermark, int imageSize) {
    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength && i < imageSize; i++) {
        image[i] = (image[i] & ~1) | (watermark[i] & 1);
    }
}

void extractWatermark(unsigned char* image, char* watermark, int watermarkSize) {
    for (int i = 0; i < watermarkSize; i++) {
        watermark[i] = (image[i] & 1);
    }
    watermark[watermarkSize] = '\0';
}

int main() {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    // Load the original image
    unsigned char* pixelData = loadBMP("input.bmp", &bmpHeader, &dibHeader);
    if (!pixelData) {
        printf("Error loading BMP file.\n");
        return 1;
    }

    // Define a watermark
    const char* watermark = "HELLO";
    embedWatermark(pixelData, watermark, dibHeader.biSizeImage);
    
    // Save the watermarked image
    saveBMP("output.bmp", bmpHeader, dibHeader, pixelData);
    
    // Show success message
    printf("Watermark embedded successfully!\n");

    // Cleanup and exit
    free(pixelData);
    return 0;
}