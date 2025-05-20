//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)  // Ensure the structure is packed
typedef struct {
    unsigned short type;        // BMP file type
    unsigned int size;         // Size of the BMP file
    unsigned short reserved1;   // Reserved; must be zero
    unsigned short reserved2;   // Reserved; must be zero
    unsigned int offset;        // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int size;          // Size of this header
    int width;                  // Width of the bitmap in pixels
    int height;                 // Height of the bitmap in pixels
    unsigned short planes;      // Number of color planes; must be 1
    unsigned short bitCount;    // Bits per pixel
    unsigned int compression;    // Compression type
    unsigned int sizeImage;     // Size of the raw bitmap data
    int xPixelsPerMeter;        // Horizontal resolution in pixels per meter
    int yPixelsPerMeter;        // Vertical resolution in pixels per meter
    unsigned int clrUsed;       // Number of colors in the palette
    unsigned int clrImportant;  // Number of important colors
} BMPInfoHeader;

#pragma pack(pop)

void embedMessageRecursive(unsigned char *imageData, const char *message, int length, int index);
int calculateMessageLength(const char *message);
void writeBMP(const char *filename, BMPHeader bmpHeader, BMPInfoHeader bmpInfoHeader, unsigned char *imageData);
void readBMP(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, unsigned char **imageData);

int main() {
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    unsigned char *imageData = NULL;

    const char *inputFile = "input.bmp"; // Input BMP file
    const char *outputFile = "output.bmp"; // Output BMP file
    const char *message = "Hidden Message!"; // Message to hide

    readBMP(inputFile, &bmpHeader, &bmpInfoHeader, &imageData);

    int messageLength = calculateMessageLength(message);
    if (messageLength == 0) {
        printf("No message to embed.\n");
        free(imageData);
        return 1;
    }

    printf("Message Length: %d\n", messageLength);
    
    embedMessageRecursive(imageData, message, messageLength, 0);
    
    writeBMP(outputFile, bmpHeader, bmpInfoHeader, imageData);
    free(imageData);

    printf("Message embedded successfully in %s\n", outputFile);
    return 0;
}

void embedMessageRecursive(unsigned char *imageData, const char *message, int length, int index) {
    if (index >= length) return;  // Base case: when the message has been completely embedded

    // Calculate position in imageData; bytes needed to embed the message are bytes containing RGB triplet
    int pixelIndex = index * 3; // Every character in the message will alter one pixel

    // Embed character into the LSB of the pixel's R channel
    imageData[pixelIndex] = (imageData[pixelIndex] & 0xFE) | ((message[index] >> 7) & 0x01);
    imageData[pixelIndex + 1] = (imageData[pixelIndex + 1] & 0xFE) | ((message[index] >> 6) & 0x01);
    imageData[pixelIndex + 2] = (imageData[pixelIndex + 2] & 0xFE) | ((message[index] >> 5) & 0x01);
    
    // Continue recursively for the next character
    embedMessageRecursive(imageData, message, length, index + 1);
}

int calculateMessageLength(const char *message) {
    return strlen(message); // Calculates the length of the message to embed
}

void writeBMP(const char *filename, BMPHeader bmpHeader, BMPInfoHeader bmpInfoHeader, unsigned char *imageData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open output BMP file for writing.\n");
        exit(1);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    fwrite(imageData, 1, bmpInfoHeader.sizeImage, file);
    
    fclose(file);
}

void readBMP(const char *filename, BMPHeader *bmpHeader, BMPInfoHeader *bmpInfoHeader, unsigned char **imageData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open input BMP file for reading.\n");
        exit(1);
    }

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    // Allocate memory for image data
    *imageData = malloc(bmpInfoHeader->sizeImage);
    fseek(file, bmpHeader->offset, SEEK_SET);
    fread(*imageData, 1, bmpInfoHeader->sizeImage, file);
    
    fclose(file);
}