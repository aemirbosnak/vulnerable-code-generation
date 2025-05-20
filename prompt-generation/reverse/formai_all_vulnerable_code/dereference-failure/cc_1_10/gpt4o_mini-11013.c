//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: puzzling
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

void encodeMessageInImage(const char *message, const char *inputFile, const char *outputFile) {
    FILE *imageFile = fopen(inputFile, "rb");
    if (!imageFile) {
        printf("Could not open input image file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);
    
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);
    
    long imageSize = bih.biWidth * bih.biHeight * (bih.biBitCount / 8);
    unsigned char *imageData = (unsigned char *)malloc(imageSize);

    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    size_t messageLen = strlen(message);
    if (messageLen > imageSize) {
        printf("Message is too long for this image.\n");
        free(imageData);
        return;
    }

    // Set message length in the first byte of the image
    imageData[0] = (unsigned char)messageLen;

    for (size_t i = 0; i < messageLen; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> (7 - j)) & 1; // Get each bit of the message
            imageData[i * 8 + j + 1] = (imageData[i * 8 + j + 1] & 0xFE) | bit; // Set least significant bit
        }
    }

    FILE *outputImageFile = fopen(outputFile, "wb");
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputImageFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputImageFile);
    fwrite(imageData, 1, imageSize, outputImageFile);

    fclose(outputImageFile);
    free(imageData);
    printf("Message encoded in image successfully!\n");
}

void decodeMessageFromImage(const char *inputFile) {
    FILE *imageFile = fopen(inputFile, "rb");
    if (!imageFile) {
        printf("Could not open input image file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);
    
    long imageSize = bih.biWidth * bih.biHeight * (bih.biBitCount / 8);
    unsigned char *imageData = (unsigned char *)malloc(imageSize);

    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    size_t messageLen = imageData[0];
    char *decodedMessage = (char *)malloc(messageLen + 1);
    decodedMessage[messageLen] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < messageLen; i++) {
        decodedMessage[i] = 0;
        for (int j = 0; j < 8; j++) {
            decodedMessage[i] <<= 1; // Shift left to make room for the next bit
            decodedMessage[i] |= (imageData[i * 8 + j + 1] & 1); // Extract the LSB
        }
    }
    
    printf("Decoded Message: %s\n", decodedMessage);

    free(decodedMessage);
    free(imageData);
}

int main() {
    const char *inputImage = "input.bmp";
    const char *outputImage = "output.bmp";
    const char *secretMessage = "Hidden Treasure";

    encodeMessageInImage(secretMessage, inputImage, outputImage);
    decodeMessageFromImage(outputImage);

    return 0;
}