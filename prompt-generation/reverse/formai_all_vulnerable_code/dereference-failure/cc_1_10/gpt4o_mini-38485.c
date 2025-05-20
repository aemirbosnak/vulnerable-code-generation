//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];      // Bitmap identifier
    unsigned int bfSize;          // Size of the BMP file
    unsigned short bfReserved1;   // Reserved
    unsigned short bfReserved2;   // Reserved
    unsigned int bfOffBits;       // Offset to start of Pixel Data
} BMPHeader;

typedef struct {
    unsigned int biSize;          // Size of the DIB header
    int biWidth;                  // Width of the image
    int biHeight;                 // Height of the image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Number of bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of the image data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the color table
    unsigned int biClrImportant;   // Important colors
} DIBHeader;

#pragma pack(pop)

void hideMessage(const char *inputImage, const char *outputImage, const char *message) {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    FILE *inputFile = fopen(inputImage, "rb");
    FILE *outputFile = fopen(outputImage, "wb");
    
    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        exit(1);
    }

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, inputFile);
    
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, outputFile);
    
    int pixelArraySize = dibHeader.biWidth * dibHeader.biHeight * (dibHeader.biBitCount / 8);
    unsigned char *pixelArray = (unsigned char *)malloc(pixelArraySize);
    
    fread(pixelArray, sizeof(unsigned char), pixelArraySize, inputFile);
    
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength && i < pixelArraySize; ++i) {
        pixelArray[i] = (pixelArray[i] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixelArray[i + 1] = (pixelArray[i + 1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixelArray[i + 2] = (pixelArray[i + 2] & 0xFE) | ((message[i] >> 5) & 0x01);
        pixelArray[i + 3] = (pixelArray[i + 3] & 0xFE) | ((message[i] >> 4) & 0x01);
    }

    fwrite(pixelArray, sizeof(unsigned char), pixelArraySize, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    free(pixelArray);
    
    printf("Message hidden successfully in %s\n", outputImage);
}

void extractMessage(const char *inputImage) {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    FILE *inputFile = fopen(inputImage, "rb");

    if (!inputFile) {
        printf("Error opening file.\n");
        exit(1);
    }

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&dibHeader, sizeof(DIBHeader), 1, inputFile);
    
    int pixelArraySize = dibHeader.biWidth * dibHeader.biHeight * (dibHeader.biBitCount / 8);
    unsigned char *pixelArray = (unsigned char *)malloc(pixelArraySize);
    
    fread(pixelArray, sizeof(unsigned char), pixelArraySize, inputFile);
    fclose(inputFile);
    
    char extractedMessage[256];
    int messageIndex = 0;

    for (int i = 0; i < pixelArraySize && messageIndex < 255; i += 8) {
        if ((pixelArray[i] & 0x01) != 0) {
            extractedMessage[messageIndex++] = 1;
        } else {
            extractedMessage[messageIndex++] = 0;
        }
    }

    extractedMessage[messageIndex] = '\0';
    printf("Extracted Message: %s\n", extractedMessage);
    
    free(pixelArray);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hide/extract> <input_image> <output_image/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Unknown command!\n");
    }

    return 0;
}