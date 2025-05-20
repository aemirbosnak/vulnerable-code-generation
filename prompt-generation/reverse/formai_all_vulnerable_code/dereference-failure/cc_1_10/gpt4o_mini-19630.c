//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the BMP header information
#pragma pack(push, 1)
typedef struct {
    unsigned short type;      // BMP file type
    unsigned int size;       // BMP file size
    unsigned short reserved1; // Reserved
    unsigned short reserved2; // Reserved
    unsigned int offset;      // Offset to pixel data
} BMPHeader;

typedef struct {
    unsigned int size;          // Size of the info header
    int width;                  // Width of the image
    int height;                 // Height of the image
    unsigned short planes;       // Number of color planes
    unsigned short bitCount;     // Bits per pixel
    unsigned int compression;    // Compression type
    unsigned int sizeImage;      // Image size in bytes
    int xPelsPerMeter;           // Horizontal resolution
    int yPelsPerMeter;           // Vertical resolution
    unsigned int clrUsed;        // Number of colors used
    unsigned int clrImportant;   // Important colors
} BMPInfoHeader;
#pragma pack(pop)

// Function to hide a message within a BMP file
void hideMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *fp = fopen(inputFile, "rb");
    if (!fp) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, fp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, fp);

    if (bmpHeader.type != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(fp);
        return;
    }

    size_t messageLength = strlen(message);
    size_t pixelDataSize = bmpInfoHeader.width * bmpInfoHeader.height * (bmpInfoHeader.bitCount / 8);
    
    if (pixelDataSize < messageLength + 1) {
        printf("Message is too large to hide in this image.\n");
        fclose(fp);
        return;
    }

    fseek(fp, bmpHeader.offset, SEEK_SET);
    unsigned char *pixelData = (unsigned char *)malloc(pixelDataSize);
    fread(pixelData, 1, pixelDataSize, fp);
    fclose(fp);
    
    // Hide the message in the least significant bits
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            pixelData[i * 8 + j] = (pixelData[i * 8 + j] & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }
    // Terminate the string in the pixel data
    pixelData[messageLength * 8] = (pixelData[messageLength * 8] & 0xFE) | 0;

    // Write the new image with the hidden message
    fp = fopen(outputFile, "wb");
    if (!fp) {
        perror("Error opening output file");
        free(pixelData);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, fp);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, fp);
    fwrite(pixelData, 1, pixelDataSize, fp);

    fclose(fp);
    free(pixelData);
    printf("Message hidden in %s successfully.\n", outputFile);
}

// Function to retrieve the hidden message from a BMP file
void retrieveMessage(const char *inputFile) {
    FILE *fp = fopen(inputFile, "rb");
    if (!fp) {
        perror("Error opening input file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, fp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, fp);

    if (bmpHeader.type != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(fp);
        return;
    }

    fseek(fp, bmpHeader.offset, SEEK_SET);
    size_t pixelDataSize = bmpInfoHeader.width * bmpInfoHeader.height * (bmpInfoHeader.bitCount / 8);
    unsigned char *pixelData = (unsigned char *)malloc(pixelDataSize);
    fread(pixelData, 1, pixelDataSize, fp);
    fclose(fp);

    // Retrieve the message from the least significant bits
    char retrievedMessage[256] = {0};
    size_t index = 0;

    while (index < 255) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= ((pixelData[index * 8 + j] & 0x01) << (7 - j));
        }
        if (byte == 0) break; // End of message
        retrievedMessage[index++] = byte;
    }
    retrievedMessage[index] = '\0';

    printf("Retrieved message: %s\n", retrievedMessage);
    free(pixelData);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [hide/retrieve] [input_file] [output_file/message]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "retrieve") == 0) {
        retrieveMessage(argv[2]);
    } else {
        printf("Invalid option. Use 'hide' or 'retrieve'.\n");
    }

    return EXIT_SUCCESS;
}