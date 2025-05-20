//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

#pragma pack(pop)

void encodeWatermark(const char *inputImage, const char *outputImage, const char *watermark) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Error opening input image");
        return;
    }
    
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    RGB *pixels = malloc(bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * sizeof(RGB));
    fread(pixels, sizeof(RGB), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight, inputFile);
    
    size_t watermarkLength = strlen(watermark);
    size_t watermarkIndex = 0;
    
    for (int i = 0; i < bmpInfoHeader.biWidth * bmpInfoHeader.biHeight; i++) {
        if (watermarkIndex < watermarkLength) {
            // Embed watermark bit into the least significant bit of the red channel
            pixels[i].red = (pixels[i].red & ~1) | (watermark[watermarkIndex] & 1);
            watermarkIndex++;
        }
        // Loop over watermark if it runs out
        if (watermarkIndex >= watermarkLength) {
            watermarkIndex = 0; // Restart watermark embedding
        }
    }

    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) {
        perror("Error opening output image");
        free(pixels);
        return;
    }

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixels, sizeof(RGB), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight, outputFile);

    fclose(outputFile);
    fclose(inputFile);
    free(pixels);

    printf("Watermark embedded successfully!\n");
}

void decodeWatermark(const char *inputImage, size_t watermarkSize) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Error opening input image");
        return;
    }
    
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    RGB *pixels = malloc(bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * sizeof(RGB));
    fread(pixels, sizeof(RGB), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight, inputFile);
    
    char *extractedWatermark = malloc(watermarkSize + 1);
    if (!extractedWatermark) {
        perror("Unable to allocate memory for watermark");
        free(pixels);
        fclose(inputFile);
        return;
    }
    
    for (size_t i = 0; i < watermarkSize; i++) {
        extractedWatermark[i] = 0; // Initialize
        for (int j = 0; j < 8; j++) { // Read 8 bits for the character
            int pixelIndex = i * 8 + j;
            extractedWatermark[i] |= (pixels[pixelIndex].red & 1) << j; // Extract LSB
        }
    }
    extractedWatermark[watermarkSize] = '\0';

    printf("Extracted Watermark: %s\n", extractedWatermark);

    free(extractedWatermark);
    free(pixels);
    fclose(inputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <encode/decode> <input-bmp> <output-bmp> <watermark/string-to-embed>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeWatermark(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        size_t watermarkSize = strlen(argv[4]) / 8; // Assume each character is encoded
        decodeWatermark(argv[2], watermarkSize);
    } else {
        printf("Unknown command. Use 'encode' or 'decode'.\n");
    }

    return 0;
}