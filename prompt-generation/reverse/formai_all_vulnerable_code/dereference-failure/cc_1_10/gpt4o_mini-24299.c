//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
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
#pragma pack()

void embedMessage(const char *inputImagePath, const char *outputImagePath, const char *message) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    FILE *outputFile = fopen(outputImagePath, "wb");

    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    
    // Calculate the number of bytes available for message
    long pixelDataOffset = fileHeader.bfOffBits;
    fseek(inputFile, pixelDataOffset, SEEK_SET);
    
    // Embed message length
    unsigned int messageLength = strlen(message);
    for (int i = 0; i < 4; i++) {
        unsigned char lengthByte = (messageLength >> (i * 8)) & 0xFF;
        fputc(lengthByte, outputFile);
    }

    // Embed message into the BMP pixel data
    int index = 0;
    while (index < messageLength) {
        unsigned char byte = message[index++];
        for (int i = 0; i < 8; i++) {
            unsigned char pixel = fgetc(inputFile);
            // Modify the least significant bit
            pixel = (pixel & 0xFE) | ((byte >> (7 - i)) & 0x01);
            fputc(pixel, outputFile);
        }
    }

    // Copy the remaining pixel data unmodified
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void extractMessage(const char *imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Read message length
    unsigned int messageLength = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char lengthByte = fgetc(inputFile);
        messageLength |= (lengthByte << (i * 8));
    }

    char *message = (char *)malloc(messageLength + 1);
    memset(message, 0, messageLength + 1);

    // Read message from the BMP pixel data
    int index = 0;
    while (index < messageLength) {
        unsigned char byte = 0;
        for (int i = 0; i < 8; i++) {
            unsigned char pixel = fgetc(inputFile);
            byte |= (pixel & 0x01) << (7 - i);
        }
        message[index++] = byte;
    }

    printf("Extracted message: %s\n", message);

    free(message);
    fclose(inputFile);
}

int main() {
    const char *inputImage = "input.bmp"; // Change as needed
    const char *outputImage = "output.bmp"; // Output image after embedding
    const char *secretMessage = "Hello, this is a secret message!";

    embedMessage(inputImage, outputImage, secretMessage);
    extractMessage(outputImage);

    return 0;
}