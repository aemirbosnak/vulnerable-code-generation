//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;

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
} DIBHeader;

void embedWatermark(const char *inputImage, const char *outputImage, const char *watermark) {
    FILE *inFile = fopen(inputImage, "rb");
    FILE *outFile = fopen(outputImage, "wb");

    if (!inFile || !outFile) {
        printf("Could not open files!\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(bmpHeader), 1, inFile);
    fread(&dibHeader, sizeof(dibHeader), 1, inFile);
    
    // Shocked by the size, we must allocate space for image
    int width = dibHeader.biWidth;
    int height = dibHeader.biHeight;
    RGB *pixelArray = (RGB *)malloc(width * height * sizeof(RGB));

    fread(pixelArray, sizeof(RGB), width * height, inFile);
    
    printf("Embedding watermark: %s\n", watermark);
    for (int i = 0; i < strlen(watermark); i++) {
        if (i < width * height) {
            pixelArray[i].red = (pixelArray[i].red & ~1) | ((watermark[i] >> 0) & 1);
            pixelArray[i].green = (pixelArray[i].green & ~1) | ((watermark[i] >> 1) & 1);
            pixelArray[i].blue = (pixelArray[i].blue & ~1) | ((watermark[i] >> 2) & 1);
        }
    }

    fwrite(&bmpHeader, sizeof(bmpHeader), 1, outFile);
    fwrite(&dibHeader, sizeof(dibHeader), 1, outFile);
    fwrite(pixelArray, sizeof(RGB), width * height, outFile);

    fclose(inFile);
    fclose(outFile);
    free(pixelArray);
    printf("Watermark embedded successfully! You can see it in: %s\n", outputImage);
}

void extractWatermark(const char *inputImage, char *outputWatermark, int watermarkLength) {
    FILE *inFile = fopen(inputImage, "rb");
    if (!inFile) {
        printf("Could not open file to extract watermark!\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    fread(&bmpHeader, sizeof(bmpHeader), 1, inFile);
    fread(&dibHeader, sizeof(dibHeader), 1, inFile);

    int width = dibHeader.biWidth;
    int height = dibHeader.biHeight;
    RGB *pixelArray = (RGB *)malloc(width * height * sizeof(RGB));

    fread(pixelArray, sizeof(RGB), width * height, inFile);
    
    printf("Extracting watermark...\n");
    for (int i = 0; i < watermarkLength; i++) {
        if (i < width * height) {
            outputWatermark[i] = 0;
            outputWatermark[i] |= (pixelArray[i].red & 1) << 0;
            outputWatermark[i] |= (pixelArray[i].green & 1) << 1;
            outputWatermark[i] |= (pixelArray[i].blue & 1) << 2;
        } else {
            break;
        }
    }
    outputWatermark[watermarkLength] = '\0';

    fclose(inFile);
    free(pixelArray);
    printf("Watermark extracted successfully! It is: %s\n", outputWatermark);
}

int main() {
    const char *inputImage = "input.bmp";
    const char *outputImage = "output.bmp";
    const char *watermark = "WOW! WATERMARK! WOW!";
    
    // Shockingly embedding the watermark
    embedWatermark(inputImage, outputImage, watermark);
    
    // Preparing to extract watermark
    char extractedWatermark[256];
    extractWatermark(outputImage, extractedWatermark, strlen(watermark));

    return 0;
}