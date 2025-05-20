//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;      // Magic number for the BMP file
    unsigned int size;       // Size of the BMP file in bytes
    unsigned short reserved1; // Reserved; must be zero
    unsigned short reserved2; // Reserved; must be zero
    unsigned int offset;      // Offset to the start of pixel data
} BMPHeader;

typedef struct {
    unsigned int size;          // Size of this header
    int width;                  // Width of the image
    int height;                 // Height of the image
    unsigned short planes;      // Number of color planes
    unsigned short bitsPerPixel; // Bits per pixel
    unsigned int compression;   // Compression type
    unsigned int imageSize;     // Image size
    int xPixelsPerMeter;        // Horizontal resolution
    int yPixelsPerMeter;        // Vertical resolution
    unsigned int colorsUsed;    // Number of colors in the color palette
    unsigned int colorsImportant; // Important color count
} BMPInfoHeader;

#pragma pack(pop)

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputFile = fopen(inputImage, "rb");
    FILE *outputFile = fopen(outputImage, "wb");
    
    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    // Move to pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    fseek(outputFile, bmpHeader.offset, SEEK_SET);

    // Embed message in the image
    unsigned char pixel;
    int messageIndex = 0;
    int messageLength = strlen(message);

    for (int i = 0; i < bmpInfoHeader.width * abs(bmpInfoHeader.height); i++) {
        fread(&pixel, sizeof(unsigned char), 1, inputFile);
        if (messageIndex < messageLength) {
            // Change the least significant bit to embed the message
            pixel = (pixel & 0xFE) | ((message[messageIndex] >> (i % 8)) & 1);
            messageIndex += (i % 8 == 7) ? 1 : 0;
        }
        fwrite(&pixel, sizeof(unsigned char), 1, outputFile);
        
        // Read next pixel's color components (for RGB, 3 bytes)
        if (i % 3 == 2) {
            pixel = 0;  // Reset for the next color component
            fwrite(&pixel, sizeof(unsigned char), 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Message embedded successfully.\n");
}

void extractMessage(const char *inputImage) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        printf("Error opening file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    // Move to pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);

    unsigned char pixel;
    char message[256] = {0};
    int messageIndex = 0;

    for (int i = 0; i < bmpInfoHeader.width * abs(bmpInfoHeader.height) && messageIndex < 255; i++) {
        fread(&pixel, sizeof(unsigned char), 1, inputFile);
        if (i % 8 == 0) {
            message[messageIndex] = 0; // Reset to construct the byte
        }
        message[messageIndex] |= (pixel & 1) << (i % 8);
        if (i % 8 == 7) {
            messageIndex++;
        }
    }

    fclose(inputFile);
    printf("Hidden message: %s\n", message);
}

int main() {
    int choice;
    char inputImage[256], outputImage[256], message[256];

    printf("1. Embed message\n");
    printf("2. Extract message\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        printf("Enter input image file (BMP): ");
        fgets(inputImage, 256, stdin);
        strtok(inputImage, "\n"); // Remove newline

        printf("Enter output image file (BMP): ");
        fgets(outputImage, 256, stdin);
        strtok(outputImage, "\n"); // Remove newline

        printf("Enter message to embed: ");
        fgets(message, 256, stdin);
        strtok(message, "\n"); // Remove newline

        embedMessage(inputImage, outputImage, message);
    } else if (choice == 2) {
        printf("Enter input image file (BMP): ");
        fgets(inputImage, 256, stdin);
        strtok(inputImage, "\n"); // Remove newline

        extractMessage(inputImage);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}