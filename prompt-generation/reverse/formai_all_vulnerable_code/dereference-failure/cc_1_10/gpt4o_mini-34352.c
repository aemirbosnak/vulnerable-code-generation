//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: immersive
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
} BMPInfoHeader;
#pragma pack(pop)

void printUsage() {
    printf("Usage: ./watermark_embed <input.bmp> <watermark.bmp> <output.bmp>\n");
    printf("       ./watermark_extract <input.bmp>\n");
}

uint8_t* readBMP(const char* filename, BMPHeader* header, BMPInfoHeader* infoHeader, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    *width = infoHeader->biWidth;
    *height = infoHeader->biHeight;

    size_t rowSize = (infoHeader->biBitCount * (*width) + 31) / 32 * 4;
    size_t dataSize = rowSize * (*height);
    uint8_t* data = (uint8_t*)malloc(dataSize);
    fseek(file, header->bfOffBits, SEEK_SET);
    fread(data, 1, dataSize, file);
    fclose(file);
    return data;
}

void writeBMP(const char* filename, BMPHeader* header, BMPInfoHeader* infoHeader, uint8_t* data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);

    size_t rowSize = (infoHeader->biBitCount * width + 31) / 32 * 4;
    fwrite(data, 1, rowSize * height, file);
    fclose(file);
}

void embedWatermark(uint8_t* imageData, uint8_t* watermarkData, int width, int height, int wmWidth, int wmHeight) {
    for (int i = 0; i < wmHeight; ++i) {
        for (int j = 0; j < wmWidth; ++j) {
            int imgIndex = (i * width + j) * 3; // Assuming 24bpp BMP (3 bytes per pixel)
            int wmIndex = (i * wmWidth + j) * 3;

            // Embed watermark by XORing the watermark pixel with the image pixel, altering the least significant bit
            imageData[imgIndex] = (imageData[imgIndex] & 0xFE) | (watermarkData[wmIndex] & 0x01);
            imageData[imgIndex + 1] = (imageData[imgIndex + 1] & 0xFE) | (watermarkData[wmIndex + 1] & 0x01);
            imageData[imgIndex + 2] = (imageData[imgIndex + 2] & 0xFE) | (watermarkData[wmIndex + 2] & 0x01);
        }
    }
}

void extractWatermark(uint8_t* imageData, uint8_t* watermarkData, int width, int height, int wmWidth, int wmHeight) {
    for (int i = 0; i < wmHeight; ++i) {
        for (int j = 0; j < wmWidth; ++j) {
            int imgIndex = (i * width + j) * 3;
            int wmIndex = (i * wmWidth + j) * 3;

            // Extract watermark by reading the least significant bit of the image's pixels
            watermarkData[wmIndex] = imageData[imgIndex] & 0x01;
            watermarkData[wmIndex + 1] = imageData[imgIndex + 1] & 0x01;
            watermarkData[wmIndex + 2] = imageData[imgIndex + 2] & 0x01;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;
    int width, height;

    uint8_t* imageData = readBMP(argv[1], &header, &infoHeader, &width, &height);
    if (strcmp(argv[0], "./watermark_embed") == 0) {
        BMPHeader watermarkHeader;
        BMPInfoHeader watermarkInfoHeader;
        int wmWidth, wmHeight;

        uint8_t* watermarkData = readBMP(argv[2], &watermarkHeader, &watermarkInfoHeader, &wmWidth, &wmHeight);
        if (wmWidth > width || wmHeight > height) {
            fprintf(stderr, "Watermark is larger than the image\n");
            free(imageData);
            free(watermarkData);
            return EXIT_FAILURE;
        }

        embedWatermark(imageData, watermarkData, width, height, wmWidth, wmHeight);
        writeBMP(argv[3], &header, &infoHeader, imageData, width, height);
        free(watermarkData);
    } else if (strcmp(argv[0], "./watermark_extract") == 0) {
        int wmWidth = width; // Assume the watermark is the same size as the image for extraction
        int wmHeight = height;

        uint8_t* watermarkData = (uint8_t*)calloc(wmWidth * wmHeight * 3, sizeof(uint8_t));
        extractWatermark(imageData, watermarkData, width, height, wmWidth, wmHeight);

        // Save extracted watermark to a new BMP file
        BMPHeader extractedHeader = header;
        BMPInfoHeader extractedInfoHeader = infoHeader;
        extractedInfoHeader.biWidth = wmWidth;
        extractedInfoHeader.biHeight = wmHeight;

        writeBMP("extracted_watermark.bmp", &extractedHeader, &extractedInfoHeader, watermarkData, wmWidth, wmHeight);
        free(watermarkData);
    }

    free(imageData);
    return EXIT_SUCCESS;
}