//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure structure is packed
typedef struct {
    unsigned char magic[2];
    unsigned int fileSize;
    unsigned int reserved1;
    unsigned int reserved2;
    unsigned int offsetData;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;

#pragma pack(pop)

void embedMessage(const char *inputBPM, const char *outputBPM, const char *message) {
    FILE *inputFile = fopen(inputBPM, "rb");
    if (!inputFile) {
        perror("Failed to open input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    int pixelDataSize = bmpInfoHeader.width * bmpInfoHeader.height * (bmpInfoHeader.bitsPerPixel / 8);
    unsigned char *pixels = (unsigned char *)malloc(pixelDataSize);
    fread(pixels, sizeof(unsigned char), pixelDataSize, inputFile);
    fclose(inputFile);

    // Prepare message for embedding
    char *messageWithEnd = (char *)malloc(strlen(message) + 1);
    strcpy(messageWithEnd, message);
    messageWithEnd[strlen(message)] = '\0'; // Null-terminate the message

    // Loop over pixel data and embed the message
    int messageIndex = 0;
    int messageLength = strlen(messageWithEnd);
    for (int i = 0; i < pixelDataSize && messageIndex < messageLength; i++) {
        // Embed one bit of the message into the least significant bit of the pixel
        pixels[i] = (pixels[i] & 0xFE) | ((messageWithEnd[messageIndex / 8] >> (messageIndex % 8)) & 1);
        messageIndex++;
    }

    // If the message was successfully embedded, write the new BMP file.
    FILE *outputFile = fopen(outputBPM, "wb");
    if (!outputFile) {
        perror("Failed to open output BMP file");
        return;
    }
    
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixels, sizeof(unsigned char), pixelDataSize, outputFile);
    
    fclose(outputFile);
    free(pixels);
    free(messageWithEnd);
    printf("Message embedded successfully in %s\n", outputBPM);
}

void extractMessage(const char *inputBPM) {
    FILE *inputFile = fopen(inputBPM, "rb");
    if (!inputFile) {
        perror("Failed to open BMP file");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    int pixelDataSize = bmpInfoHeader.width * bmpInfoHeader.height * (bmpInfoHeader.bitsPerPixel / 8);
    unsigned char *pixels = (unsigned char *)malloc(pixelDataSize);
    fread(pixels, sizeof(unsigned char), pixelDataSize, inputFile);
    fclose(inputFile);

    // Extract the hidden message
    char *message = (char *)malloc((pixelDataSize / 8) + 1);
    int messageIndex = 0;
    for (int i = 0; i < pixelDataSize && messageIndex < (pixelDataSize / 8); i++) {
        // Read the least significant bit
        message[messageIndex / 8] |= (pixels[i] & 1) << (messageIndex % 8);
        messageIndex++;
    }
    
    message[messageIndex / 8] = '\0'; // Null-terminate the message
    printf("Extracted Message: %s\n", message);

    free(pixels);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s embed <input.bmp> <output.bmp> <message>\n", argv[0]);
        fprintf(stderr, "   or: %s extract <input.bmp>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}