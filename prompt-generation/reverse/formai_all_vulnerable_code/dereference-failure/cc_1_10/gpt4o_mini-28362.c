//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
} BITMAPINFOHEADER;
#pragma pack(pop)

void embedMessage(BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, uint8_t *pixelData, const char *message) {
    size_t msgLen = strlen(message);
    pixelData[0] = (uint8_t)msgLen; // Store length of the message

    for (size_t i = 0; i < msgLen; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Find the pixel to modify
            int pixelIndex = 54 + (i * 8 + bit);
            pixelData[pixelIndex] = (pixelData[pixelIndex] & ~1) | ((message[i] >> (7 - bit)) & 1);
        }
    }
}

void extractMessage(BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, uint8_t *pixelData) {
    size_t msgLen = pixelData[0];
    char *message = malloc(msgLen + 1);
    message[msgLen] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < msgLen; i++) {
        char ch = 0;
        for (int bit = 0; bit < 8; bit++) {
            // Find the pixel to inspect
            int pixelIndex = 54 + (i * 8 + bit);
            ch |= ((pixelData[pixelIndex] & 1) << (7 - bit));
        }
        message[i] = ch;
    }
    
    printf("Extracted Message: %s\n", message);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image.bmp> <message> <output.bmp>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input BMP file");
        return 1;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
    if (bfh.bfType != 0x4D42) { // Check for BMP file type
        fprintf(stderr, "File is not a valid BMP file\n");
        fclose(inputFile);
        return 1;
    }

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);

    uint8_t *pixelData = malloc(bfh.bfSize - bfh.bfOffBits);
    fseek(inputFile, bfh.bfOffBits, SEEK_SET);
    fread(pixelData, bfh.bfSize - bfh.bfOffBits, 1, inputFile);
    fclose(inputFile);

    embedMessage(bfh, bih, pixelData, argv[2]);

    FILE *outputFile = fopen(argv[3], "wb");
    if (!outputFile) {
        perror("Error opening output BMP file");
        free(pixelData);
        return 1;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixelData, bfh.bfSize - bfh.bfOffBits, 1, outputFile);
    fclose(outputFile);
    
    printf("Message embedded successfully!\n");

    // Optional extraction phase
    extractMessage(bfh, bih, pixelData);

    free(pixelData);
    return 0;
}