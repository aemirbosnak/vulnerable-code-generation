//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfo;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfo, sizeof(BMPInfoHeader), 1, bmpFile);

    if (bmpHeader.type != 0x4D42) {
        printf("Not a BMP file.\n");
        fclose(bmpFile);
        return;
    }

    // Calculate the number of bytes required for the message
    size_t messageLength = strlen(message);
    // Append a null terminator
    messageLength++;
    // Ensure we have enough space in the image
    if (messageLength * 8 > bmpInfo.width * bmpInfo.height * (bmpInfo.bitsPerPixel / 8)) {
        printf("The image is too small to hold the message.\n");
        fclose(bmpFile);
        return;
    }

    // Move to the beginning of pixel data
    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    uint8_t *pixels = (uint8_t *)malloc(bmpInfo.sizeImage);
    fread(pixels, 1, bmpInfo.sizeImage, bmpFile);
    fclose(bmpFile);

    // Embed the message into the image's pixel data
    for (size_t i = 0; i < messageLength; i++) {
        uint8_t byte = message[i];
        for (int j = 0; j < 8; j++) {
            int index = (i * 8) + j;
            if (index >= bmpInfo.sizeImage) break;

            // Clear least significant bit and set it to the message bit
            pixels[index] = (pixels[index] & 0xFE) | ((byte >> (7 - j)) & 0x01);
        }
    }

    // Write to the output file
    FILE *outFile = fopen(outputFile, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfo, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(pixels, 1, bmpInfo.sizeImage, outFile);
    fclose(outFile);
    free(pixels);

    printf("Message embedded successfully!\n");
}

void retrieveMessage(const char *inputFile) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfo;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfo, sizeof(BMPInfoHeader), 1, bmpFile);

    if (bmpHeader.type != 0x4D42) {
        printf("Not a BMP file.\n");
        fclose(bmpFile);
        return;
    }

    // Move to the beginning of pixel data
    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    uint8_t *pixels = (uint8_t *)malloc(bmpInfo.sizeImage);
    fread(pixels, 1, bmpInfo.sizeImage, bmpFile);
    fclose(bmpFile);

    char message[1024];
    size_t messageIndex = 0;

    // Retrieve the message from pixels
    while (1) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            int index = (messageIndex * 8) + j;
            if (index >= bmpInfo.sizeImage) break;

            byte |= (pixels[index] & 0x01) << (7 - j);
        }

        if (byte == '\0') break; // End of message
      
        message[messageIndex++] = byte;
    }

    message[messageIndex] = '\0';
    printf("Retrieved Message: %s\n", message);
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s embed/retrieve <input.bmp> <output.bmp/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "retrieve") == 0) {
        retrieveMessage(argv[2]);
    } else {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}