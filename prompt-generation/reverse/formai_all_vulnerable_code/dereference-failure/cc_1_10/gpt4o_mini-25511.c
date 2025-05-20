//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define a structure for the BMP file header
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
#pragma pack(pop)

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader.bfType != 0x4D42) {
        printf("Error: Not a BMP file.\n");
        fclose(file);
        return;
    }

    // Calculate the pixel array size
    size_t pixelArraySize = infoHeader.biWidth * infoHeader.biHeight * (infoHeader.biBitCount / 8);
    uint8_t *pixelData = (uint8_t*)malloc(pixelArraySize);
    fread(pixelData, pixelArraySize, 1, file);
    fclose(file);

    // Embed the watermark into the pixel data
    size_t watermarkLength = strlen(watermark);
    for (size_t i = 0; i < watermarkLength; ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            uint8_t watermarkBit = (watermark[i] >> (7 - bit)) & 1;
            size_t pixelIndex = (i * 8 + bit) * 3; // Assume 24-bit color (RGB)

            if (pixelIndex < pixelArraySize) {
                // Clear LSB and set it to watermark bit
                pixelData[pixelIndex] = (pixelData[pixelIndex] & 0xFE) | watermarkBit;
            }
        }
    }

    // Write the new BMP file with embedded watermark
    file = fopen(outputFile, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixelData, pixelArraySize, 1, file);
    fclose(file);
    
    free(pixelData);
    printf("Watermark embedded successfully into %s!\n", outputFile);
}

void extractWatermark(const char *inputFile) {
    FILE *file = fopen(inputFile, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    size_t pixelArraySize = infoHeader.biWidth * infoHeader.biHeight * (infoHeader.biBitCount / 8);
    uint8_t *pixelData = (uint8_t*)malloc(pixelArraySize);
    fread(pixelData, pixelArraySize, 1, file);
    fclose(file);

    // Extract the watermark from pixel data
    char watermark[100] = {0}; // To store the extracted watermark
    for (size_t i = 0; i < 100; ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            size_t pixelIndex = (i * 8 + bit) * 3; // 24-bit color (RGB)
            if (pixelIndex < pixelArraySize) {
                uint8_t watermarkBit = pixelData[pixelIndex] & 1;
                watermark[i] |= (watermarkBit << (7 - bit));
            } else {
                watermark[i] = '\0'; // Null terminate if no more pixels
                break;
            }
        }
    }

    printf("Extracted Watermark: %s\n", watermark);
    free(pixelData);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <embed/extract> <input.bmp> <output.bmp (only for embed)> <watermark (only for embed)>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractWatermark(argv[2]);
    } else {
        printf("Invalid operation. Use 'embed' or 'extract'.\n");
    }

    return EXIT_SUCCESS;
}