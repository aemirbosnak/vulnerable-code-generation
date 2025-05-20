//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: authentic
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
#pragma pack(pop)

void embedWatermark(const char *inputBmp, const char *outputBmp, const char *watermark) {
    FILE *fpInput = fopen(inputBmp, "rb");
    FILE *fpOutput = fopen(outputBmp, "wb");
    
    if (!fpInput || !fpOutput) {
        perror("File opening failed");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpInput);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpInput);

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpOutput);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpOutput);

    fseek(fpInput, fileHeader.bfOffBits, SEEK_SET);
    fseek(fpOutput, fileHeader.bfOffBits, SEEK_SET);

    int watermarkLength = strlen(watermark);
    for (int i = 0; i < watermarkLength; ++i) {
        uint8_t watermarkByte = watermark[i];
        for (int j = 0; j < 8; ++j) {
            uint8_t pixel[3]; // RGB

            if (fread(pixel, sizeof(uint8_t), 3, fpInput) != 3) {
                break;
            }

            // Embed watermark in least significant bit of blue channel
            pixel[0] = (pixel[0] & ~1) | ((watermarkByte >> (7 - j)) & 1);
            fwrite(pixel, sizeof(uint8_t), 3, fpOutput);
        }
    }

    uint8_t pixel[3];
    while (fread(pixel, sizeof(uint8_t), 3, fpInput) == 3) {
        fwrite(pixel, sizeof(uint8_t), 3, fpOutput);
    }

    fclose(fpInput);
    fclose(fpOutput);
}

void extractWatermark(const char *inputBmp, int watermarkLength) {
    FILE *fpInput = fopen(inputBmp, "rb");
    if (!fpInput) {
        perror("File opening failed");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpInput);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpInput);

    fseek(fpInput, fileHeader.bfOffBits, SEEK_SET);

    char *extractedWatermark = malloc(watermarkLength + 1);
    if (!extractedWatermark) {
        perror("Memory allocation failed");
        fclose(fpInput);
        return;
    }
    
    memset(extractedWatermark, 0, watermarkLength + 1);

    for (int i = 0; i < watermarkLength; ++i) {
        uint8_t watermarkByte = 0;
        for (int j = 0; j < 8; ++j) {
            uint8_t pixel[3]; // RGB
            fread(pixel, sizeof(uint8_t), 3, fpInput);
            watermarkByte |= ((pixel[0] & 1) << (7 - j));
        }
        extractedWatermark[i] = watermarkByte;
    }

    printf("Extracted Watermark: %s\n", extractedWatermark);
    free(extractedWatermark);
    fclose(fpInput);
}

int main() {
    const char *inputBmp = "input.bmp";
    const char *outputBmp = "watermarked.bmp";
    const char *watermark = "WATERMARK";

    embedWatermark(inputBmp, outputBmp, watermark);
    printf("Watermark embedded successfully into %s\n", outputBmp);

    printf("Extracting watermark from the new image...\n");
    extractWatermark(outputBmp, strlen(watermark));

    return 0;
}