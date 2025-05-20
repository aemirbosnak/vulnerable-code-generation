//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure byte alignment for BMP structures
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        printf("Unable to open input file!\n");
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, f);

    if (bfHeader.bfType != 0x4D42) { // Check if it's a BMP file
        printf("Not a valid BMP file!\n");
        fclose(f);
        return;
    }

    // Prepare to read pixel data
    unsigned char *pixels = (unsigned char *)malloc(biHeader.biSizeImage);
    fseek(f, bfHeader.bfOffBits, SEEK_SET);
    fread(pixels, biHeader.biSizeImage, 1, f);
    fclose(f);

    // Embed message in the least significant bit of the pixels
    size_t messageLength = strlen(message);
    size_t messageIndex = 0;

    for (size_t i = 0; i < biHeader.biSizeImage && messageIndex < messageLength; i++) {
        pixels[i] = (pixels[i] & 0xFE) | ((message[messageIndex] >> (i % 8)) & 0x01);
        if ((i + 1) % 8 == 0) {
            messageIndex++;
        }
    }

    // If there's leftover space, let's zero-out the remainder
    for (size_t i = biHeader.biSizeImage; i < biHeader.biSizeImage + (8 - (messageLength % 8)); i++) {
        pixels[i] = (pixels[i] & 0xFE);
    }

    // Write the new BMP file
    f = fopen(outputFile, "wb");
    fwrite(&bfHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(&biHeader, sizeof(BITMAPINFOHEADER), 1, f);
    fseek(f, bfHeader.bfOffBits, SEEK_SET);
    fwrite(pixels, biHeader.biSizeImage, 1, f);
    fclose(f);
    free(pixels);

    printf("Message embedded successfully! Have fun with your BMP!\n");
}

void extractMessage(const char *inputFile) {
    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        printf("Unable to open input file!\n");
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, f);

    if (bfHeader.bfType != 0x4D42) { // Check if it's a BMP file
        printf("Not a valid BMP file!\n");
        fclose(f);
        return;
    }

    unsigned char *pixels = (unsigned char *)malloc(biHeader.biSizeImage);
    fseek(f, bfHeader.bfOffBits, SEEK_SET);
    fread(pixels, biHeader.biSizeImage, 1, f);
    fclose(f);

    char extractedMessage[100] = {0};
    for (size_t i = 0; i < 100; i++) {
        extractedMessage[i] = 0;
    }

    size_t messageIndex = 0;
    for (size_t i = 0; i < biHeader.biSizeImage; i++) {
        if (i % 8 == 0 && messageIndex < 100) {
            extractedMessage[messageIndex] = 0;
        }
        extractedMessage[messageIndex] |= ((pixels[i] & 0x01) << (i % 8));
        if ((i + 1) % 8 == 0) {
            messageIndex++;
        }
    }

    printf("Extracted Message: %s\n", extractedMessage);
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input BMP file> <output BMP file> <message to embed>\n", argv[0]);
        return 1;
    }

    embedMessage(argv[1], argv[2], argv[3]);
    extractMessage(argv[2]);

    return 0;
}