//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensures there is no padding in struct
typedef struct {
    unsigned short type;      // Magic number for file
    unsigned int size;       // Size of file
    unsigned short reserved1; // Reserved
    unsigned short reserved2; // Reserved
    unsigned int offset;      // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int size;            // Size of this header (in bytes)
    int width;                    // Width of bitmap in pixels
    int height;                   // Height of bitmap in pixels
    unsigned short planes;        // Number of color planes
    unsigned short bitCount;      // Number of bits per pixel
    unsigned int compression;     // Compression type
    unsigned int sizeImage;       // Image size
    int xPixelsPerMeter;          // Horizontal resolution
    int yPixelsPerMeter;          // Vertical resolution
    unsigned int colorsUsed;      // Number of colors in the color palette
    unsigned int colorsImportant;  // Colors that are important
} BMPInfoHeader;

void hideMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputImg = fopen(inputImage, "rb");
    if (!inputImg) {
        perror("Error opening input image");
        return;
    }

    FILE *outputImg = fopen(outputImage, "wb");
    if (!outputImg) {
        perror("Error opening output image");
        fclose(inputImg);
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputImg);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputImg);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputImg);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputImg);

    long pixelDataSize = bmpHeader.size - bmpHeader.offset;
    unsigned char *pixelData = (unsigned char *)malloc(pixelDataSize);
    fseek(inputImg, bmpHeader.offset, SEEK_SET);
    fread(pixelData, 1, pixelDataSize, inputImg);

    size_t messageLength = strlen(message);
    size_t totalBytes = (messageLength * 8) + 1; // 1 extra byte for null-terminator
    if(totalBytes > pixelDataSize) {
        printf("Message is too long to be embedded in the image\n");
        free(pixelData);
        fclose(inputImg);
        fclose(outputImg);
        return;
    }

    // Embed the message into the least significant bits
    for(size_t i = 0; i < totalBytes; i++) {
        for(int bit = 0; bit < 8; bit++) {
            unsigned char bitToHide = (message[i] >> (7 - bit)) & 1;
            pixelData[i * 8 + bit] = (pixelData[i * 8 + bit] & 0xFE) | bitToHide;
        }
    }

    fseek(outputImg, bmpHeader.offset, SEEK_SET);
    fwrite(pixelData, 1, pixelDataSize, outputImg);

    free(pixelData);
    fclose(inputImg);
    fclose(outputImg);
    printf("Message hidden successfully.\n");
}

void extractMessage(const char *inputImage) {
    FILE *inputImg = fopen(inputImage, "rb");
    if (!inputImg) {
        perror("Error opening input image");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputImg);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputImg);

    long pixelDataSize = bmpHeader.size - bmpHeader.offset;
    unsigned char *pixelData = (unsigned char *)malloc(pixelDataSize);
    fseek(inputImg, bmpHeader.offset, SEEK_SET);
    fread(pixelData, 1, pixelDataSize, inputImg);

    char message[256] = {0}; // Assuming the message won't exceed 255 characters
    size_t totalBytes = (sizeof(message) - 1) * 8; // Exclude null terminator
    for(size_t i = 0; i < totalBytes; i++) {
        int byteIndex = i / 8;
        int bitIndex = 7 - (i % 8);
        if (i % 8 == 0) message[byteIndex] = 0; // Reset byte when starting a new byte
        message[byteIndex] |= ((pixelData[i] & 1) << bitIndex);
        if (i > 7 && (message[byteIndex] == 0)) {
            break; // Stop reading at null character
        }
    }

    printf("Extracted message: %s\n", message);
    free(pixelData);
    fclose(inputImg);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hide|extract> <image file> <output file or message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'hide' or 'extract'.\n");
    }

    return 0;
}