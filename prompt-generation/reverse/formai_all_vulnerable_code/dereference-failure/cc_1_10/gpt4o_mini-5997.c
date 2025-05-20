//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t fileType;      // File Type
    uint32_t fileSize;      // File Size in bytes
    uint16_t reserved1;     // Reserved
    uint16_t reserved2;     // Reserved
    uint32_t offsetData;    // Offset to image data
} BMPHeader;

typedef struct {
    uint32_t size;          // Size of this header (40 bytes)
    int32_t width;          // Width of the bitmap in pixels
    int32_t height;         // Height of the bitmap in pixels
    uint16_t planes;        // Number of color planes
    uint16_t bitCount;      // Number of bits per pixel
    uint32_t compression;    // Compression type
    uint32_t sizeImage;     // Image size
    int32_t xPixelsPerMeter; // Horizontal resolution
    int32_t yPixelsPerMeter; // Vertical resolution
    uint32_t colorsUsed;     // Number of colors in image
    uint32_t colorsImportant; // Important colors
} BMPInfoHeader;

#pragma pack(pop)

void encodeMessage(const char *inputImagePath, const char *outputImagePath, const char *message) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    FILE *outputFile = fopen(outputImagePath, "wb");
    
    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error opening files!\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    size_t messageLength = strlen(message);
    size_t messageBitLength = messageLength * 8;

    // Calculate the size of the image data
    fseek(inputFile, bmpHeader.offsetData, SEEK_SET);
    
    uint8_t *imageData = (uint8_t *)malloc(bmpInfoHeader.sizeImage);
    fread(imageData, 1, bmpInfoHeader.sizeImage, inputFile);
    
    // Embed the length of the message first
    for (int i = 0; i < sizeof(size_t) * 8; i++) {
        if ((messageLength >> i) & 1) { // Check if the ith bit is set
            imageData[i] |= 1; // Set the LSB to 1
        } else {
            imageData[i] &= ~1; // Clear the LSB
        }
    }
    
    // Embed the message
    for (size_t i = 0; i < messageBitLength; i++) {
        if (message[i / 8] & (1 << (i % 8))) {
            imageData[sizeof(size_t) * 8 + i] |= 1; // Set the LSB to 1
        } else {
            imageData[sizeof(size_t) * 8 + i] &= ~1; // Clear the LSB
        }
    }

    // Write the modified image data to output file
    fwrite(imageData, 1, bmpInfoHeader.sizeImage, outputFile);

    free(imageData);
    fclose(inputFile);
    fclose(outputFile);
}

void decodeMessage(const char *inputImagePath) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    
    if (!inputFile) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    fseek(inputFile, bmpHeader.offsetData, SEEK_SET);
    
    uint8_t *imageData = (uint8_t *)malloc(bmpInfoHeader.sizeImage);
    fread(imageData, 1, bmpInfoHeader.sizeImage, inputFile);

    size_t messageLength = 0;
    
    // Read the length of the message
    for (int i = 0; i < sizeof(size_t) * 8; i++) {
        messageLength |= ((imageData[i] & 1) << i);
    }

    char *message = (char *)malloc(messageLength + 1);
    message[messageLength] = '\0'; // Null-terminate the message

    // Read the message
    for (size_t i = 0; i < messageLength * 8; i++) {
        if (imageData[sizeof(size_t) * 8 + i] & 1) {
            message[i / 8] |= (1 << (i % 8));
        } else {
            message[i / 8] &= ~(1 << (i % 8));
        }
    }

    printf("Decoded Message: %s\n", message);

    free(imageData);
    free(message);
    fclose(inputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s encode|decode <input> <output|nothing> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'encode' or 'decode'.\n");
    }

    return 0;
}