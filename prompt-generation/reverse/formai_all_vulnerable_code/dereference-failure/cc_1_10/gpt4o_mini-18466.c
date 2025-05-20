//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPFileHeader;

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

void embedWatermark(const char* bmpFile, const char* watermark) {
    FILE* file = fopen(bmpFile, "rb+");
    if (!file) {
        perror("Unable to open BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(file);
        return;
    }

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int watermarkLength = strlen(watermark);
    uint8_t* bmpData = (uint8_t*)malloc(width * height * 3);
    fread(bmpData, width * height * 3, 1, file);

    for (int i = 0; i < watermarkLength && i < width * height * 3; i++) {
        bmpData[i * 3 + 0] = (bmpData[i * 3 + 0] & 0xFE) | ((watermark[i] >> 0) & 0x1);
        bmpData[i * 3 + 1] = (bmpData[i * 3 + 1] & 0xFE) | ((watermark[i] >> 1) & 0x1);
        bmpData[i * 3 + 2] = (bmpData[i * 3 + 2] & 0xFE) | ((watermark[i] >> 2) & 0x1);
    }

    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    fwrite(bmpData, width * height * 3, 1, file);
    
    free(bmpData);
    fclose(file);
}

void extractWatermark(const char* bmpFile, int length) {
    FILE* file = fopen(bmpFile, "rb");
    if (!file) {
        perror("Unable to open BMP file");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(file);
        return;
    }

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    uint8_t* bmpData = (uint8_t*)malloc(width * height * 3);
    fread(bmpData, width * height * 3, 1, file);

    char extractedWatermark[length + 1];
    memset(extractedWatermark, 0, length + 1);

    for (int i = 0; i < length && i < width * height * 3; i++) {
        extractedWatermark[i] |= ((bmpData[i * 3 + 0] & 0x1) << 0);
        extractedWatermark[i] |= ((bmpData[i * 3 + 1] & 0x1) << 1);
        extractedWatermark[i] |= ((bmpData[i * 3 + 2] & 0x1) << 2);
    }

    printf("Extracted Watermark: %s\n", extractedWatermark);
    
    free(bmpData);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed|extract> <bmp_file> <watermark_or_length>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedWatermark(argv[2], argv[3]);
        printf("Watermark embedded successfully!\n");
    } else if (strcmp(argv[1], "extract") == 0) {
        int length = atoi(argv[3]);
        extractWatermark(argv[2], length);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
    }

    return 0;
}