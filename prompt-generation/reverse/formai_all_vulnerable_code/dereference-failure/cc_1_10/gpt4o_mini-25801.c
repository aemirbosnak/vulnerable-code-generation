//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Align structure to 1-byte boundary
typedef struct {
    unsigned short bfType;      // Magic number for BMP files
    unsigned int bfSize;        // Size of the BMP file
    unsigned short bfReserved1; // Reserved (must be 0)
    unsigned short bfReserved2; // Reserved (must be 0)
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;        // Size of this header
    int biWidth;                // Width of the image
    int biHeight;               // Height of the image
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;  // Compression type
    unsigned int biSizeImage;    // Size of image data
    int biXPelsPerMeter;         // Horizontal resolution
    int biYPelsPerMeter;         // Vertical resolution
    unsigned int biClrUsed;      // Number of colors in the palette
    unsigned int biClrImportant;  // Important colors
} BMPInfoHeader;

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    // Calculate the size of the message
    int messageLength = strlen(message);
    // Check if the message can fit in the BMP image
    if (messageLength * 8 > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3)) {
        fprintf(stderr, "Message is too long to embed in this image.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Create a new file to write the modified image
    FILE *outFile = fopen(outputFile, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);

    // Read pixel data and embed the message
    unsigned char pixel[3]; // Buffer for pixel data
    for (int i = 0; i < bmpInfoHeader.biWidth * bmpInfoHeader.biHeight && i < messageLength * 8; ++i) {
        // Read pixel data
        fread(pixel, sizeof(unsigned char), 3, inFile);
        
        // Modify the least significant bit of the pixel to embed the message
        if (message[i / 8] & (1 << (i % 8))) {
            pixel[0] |= 1; // Set LSB to 1
        } else {
            pixel[0] &= ~1; // Set LSB to 0
        }

        // Write modified pixel data to the new file
        fwrite(pixel, sizeof(unsigned char), 3, outFile);
    }

    // Write remaining pixel data unchanged
    while (fread(pixel, sizeof(unsigned char), 3, inFile) > 0) {
        fwrite(pixel, sizeof(unsigned char), 3, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void extractMessage(const char *inputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file for message extraction");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    char message[256] = {0}; // Buffer for extracted message
    int messageLength = 0;

    // Read pixel data and extract the message
    unsigned char pixel[3];
    for (int i = 0; messageLength < 256; ++i) {
        fread(pixel, sizeof(unsigned char), 3, inFile);
        // Get the LSB of the first byte of the pixel
        if (pixel[0] & 1) {
            message[messageLength / 8] |= (1 << (messageLength % 8));
        }
        messageLength++;

        // Stop if we've reached the limit of the characters we want
        if (messageLength % 8 == 0 && message[messageLength / 8 - 1] == 0) {
            break; // Null character signifies end of message
        }
    }

    printf("Extracted Message: %s\n", message);
    fclose(inFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <input-file> <output-file/message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' to embed a message or 'extract' to extract a message.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}