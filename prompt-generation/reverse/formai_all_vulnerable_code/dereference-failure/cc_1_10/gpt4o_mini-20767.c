//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure tight packing for structs on all platforms
typedef struct {
    unsigned char bmpSignature[2]; // BMP Signature
    unsigned int fileSize; // File size in bytes
    unsigned int reserved; // Reserved field
    unsigned int dataOffset; // Offset to pixel data
} BMPHeader;

typedef struct {
    unsigned int headerSize; // Header size
    unsigned int width; // Image width
    unsigned int height; // Image height
    unsigned short planes; // Color planes
    unsigned short bitsPerPixel; // Bits per pixel
    unsigned int compression; // Compression type
    unsigned int imageSize; // Image size
    unsigned int xPixelsPerMeter; // X pixels per meter
    unsigned int yPixelsPerMeter; // Y pixels per meter
    unsigned int colorsUsed; // Number of colors
    unsigned int importantColors; // Important colors
} DIBHeader;

#pragma pack(pop)

void encodeMessageToBMP(const char *inputImage, const char *outputImage, const char *message) {
    FILE *imageFile = fopen(inputImage, "rb");
    if (!imageFile) {
        printf("Error opening the input image file.\n");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    
    if (bmpHeader.bmpSignature[0] != 'B' || bmpHeader.bmpSignature[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(imageFile);
        return;
    }

    DIBHeader dibHeader;
    fread(&dibHeader, sizeof(DIBHeader), 1, imageFile);
    
    if (dibHeader.bitsPerPixel != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(imageFile);
        return;
    }

    unsigned char *pixelData = (unsigned char*)malloc(dibHeader.imageSize);
    fseek(imageFile, bmpHeader.dataOffset, SEEK_SET);
    fread(pixelData, dibHeader.imageSize, 1, imageFile);
    fclose(imageFile);

    // Append a delimiter at the end of the message
    char *encodedMessage = malloc(strlen(message) + 1);
    strcpy(encodedMessage, message);
    strcat(encodedMessage, "<END>");

    int messageIndex = 0;
    int messageLength = strlen(encodedMessage);
    for (int i = 0; i < dibHeader.imageSize && messageIndex < messageLength; i += 3) {
        // Modify the least significant bit of the RGB values
        if (messageIndex < messageLength) {
            pixelData[i] = (pixelData[i] & 0xFE) | ((encodedMessage[messageIndex] >> 7) & 0x01);
            messageIndex++;
        }
        if (messageIndex < messageLength) {
            pixelData[i + 1] = (pixelData[i + 1] & 0xFE) | ((encodedMessage[messageIndex] >> 7) & 0x01);
            messageIndex++;
        }
        if (messageIndex < messageLength) {
            pixelData[i + 2] = (pixelData[i + 2] & 0xFE) | ((encodedMessage[messageIndex] >> 7) & 0x01);
            messageIndex++;
        }
    }

    // Write modified pixel data to the output image
    FILE *outputFile = fopen(outputImage, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, outputFile);
    fseek(outputFile, bmpHeader.dataOffset, SEEK_SET);
    fwrite(pixelData, dibHeader.imageSize, 1, outputFile);
    fclose(outputFile);

    free(pixelData);
    free(encodedMessage);
    printf("Message encoded successfully!\n");
}

void decodeMessageFromBMP(const char *inputImage) {
    FILE *imageFile = fopen(inputImage, "rb");
    if (!imageFile) {
        printf("Error opening the BMP file.\n");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    
    if (bmpHeader.bmpSignature[0] != 'B' || bmpHeader.bmpSignature[1] != 'M') {
        printf("Not a valid BMP file.\n");
        fclose(imageFile);
        return;
    }

    DIBHeader dibHeader;
    fread(&dibHeader, sizeof(DIBHeader), 1, imageFile);
    
    if (dibHeader.bitsPerPixel != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(imageFile);
        return;
    }

    unsigned char *pixelData = (unsigned char*)malloc(dibHeader.imageSize);
    fseek(imageFile, bmpHeader.dataOffset, SEEK_SET);
    fread(pixelData, dibHeader.imageSize, 1, imageFile);
    fclose(imageFile);

    char decodedMessage[1024];
    int messageIndex = 0;
    for (int i = 0; i < dibHeader.imageSize && messageIndex < sizeof(decodedMessage) - 1; i += 3) {
        if (messageIndex < sizeof(decodedMessage) - 1) {
            decodedMessage[messageIndex] = 0;
            decodedMessage[messageIndex] |= (pixelData[i] & 0x01) << 7;
            messageIndex++;
        }
        if (messageIndex < sizeof(decodedMessage) - 1) {
            decodedMessage[messageIndex] = 0;
            decodedMessage[messageIndex] |= (pixelData[i + 1] & 0x01) << 7;
            messageIndex++;
        }
        if (messageIndex < sizeof(decodedMessage) - 1) {
            decodedMessage[messageIndex] = 0;
            decodedMessage[messageIndex] |= (pixelData[i + 2] & 0x01) << 7;
            messageIndex++;
        }
    }

    decodedMessage[messageIndex] = '\0';
    printf("Decoded message: %s\n", decodedMessage);

    free(pixelData);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <encode|decode> <input.bmp> <output.bmp> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageToBMP(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromBMP(argv[2]);
    } else {
        printf("Unknown operation: %s\n", argv[1]);
    }

    return 0;
}