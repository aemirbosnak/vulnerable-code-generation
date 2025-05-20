//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure no padding bytes are added
typedef struct {
    unsigned short bfType;      // Magic number for BMP files (must be 'BM')
    unsigned int bfSize;       // Size of the BMP file in bytes
    unsigned short bfReserved1; // Reserved; must be 0
    unsigned short bfReserved2; // Reserved; must be 0
    unsigned int bfOffBits;     // Offset to the start of the pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;          // Size of this header (40 bytes)
    int biWidth;                  // Width of the bitmap in pixels
    int biHeight;                 // Height of the bitmap in pixels
    unsigned short biPlanes;      // Number of color planes (must be 1)
    unsigned short biBitCount;    // Bits per pixel (1, 4, 8, 16, 24, or 32)
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of the pixel data
    int biXPelsPerMeter;          // Horizontal resolution (pixels per meter)
    int biYPelsPerMeter;          // Vertical resolution (pixels per meter)
    unsigned int biClrUsed;        // Number of colors in the color palette
    unsigned int biClrImportant;    // Important colors (0 means all are important)
} BITMAPINFOHEADER;

#pragma pack(pop)

void embedMessage(const char *inputBmp, const char *outputBmp, const char *message) {
    FILE *inFile = fopen(inputBmp, "rb");
    if (!inFile) {
        perror("Cannot open input BMP file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inFile);

    if (fileHeader.bfType != 0x4D42) { // Check for 'BM'
        printf("Not a valid BMP file.\n");
        fclose(inFile);
        return;
    }

    int messageLen = strlen(message);
    int totalPixels = infoHeader.biWidth * infoHeader.biHeight;
    int maxMessageSize = totalPixels / 8; // For embedding 1 bit per pixel
    if (messageLen > maxMessageSize) {
        printf("Message is too long to embed in the image.\n");
        fclose(inFile);
        return;
    }

    unsigned char *pixelData = (unsigned char *) malloc(infoHeader.biSizeImage);
    fseek(inFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, infoHeader.biSizeImage, 1, inFile);
    fclose(inFile);

    // Embed the message into the least significant bits of the pixel data
    for (int i = 0; i < messageLen; i++) {
        for (int j = 0; j < 8; j++) {
            pixelData[i * 8 + j] = (pixelData[i * 8 + j] & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

    FILE *outFile = fopen(outputBmp, "wb");
    if (!outFile) {
        perror("Cannot open output BMP file");
        free(pixelData);
        return;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outFile);
    fwrite(pixelData, infoHeader.biSizeImage, 1, outFile);
    fclose(outFile);

    free(pixelData);
    printf("Message embedded successfully.\n");
}

void extractMessage(const char *inputBmp) {
    FILE *inFile = fopen(inputBmp, "rb");
    if (!inFile) {
        perror("Cannot open BMP file");
        return;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inFile);

    if (fileHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(inFile);
        return;
    }

    unsigned char *pixelData = (unsigned char *) malloc(infoHeader.biSizeImage);
    fseek(inFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, infoHeader.biSizeImage, 1, inFile);
    fclose(inFile);

    // Extract the message from the least significant bits of the pixel data
    char message[256] = {0}; // Assume message length will not exceed 256
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 8; j++) {
            if ((pixelData[i * 8 + j] & 0x01) == 1) {
                message[i] |= (1 << (7 - j));
            }
        }
        if (message[i] == '\0') break; // Stop if null character is found
    }

    printf("Extracted message: %s\n", message);

    free(pixelData);
}

int main() {
    const char *imagePath = "input.bmp";
    const char *outputPath = "output.bmp";
    const char *secretMessage = "Hello World!";
    
    embedMessage(imagePath, outputPath, secretMessage);
    extractMessage(outputPath);

    return 0;
}