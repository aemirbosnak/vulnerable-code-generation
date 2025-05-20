//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;

void embedMessageInBMP(const char *inputFile, const char *outputFile, const char *message) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, input);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, input);

    if (bmpHeader.type != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    size_t messageLength = strlen(message);
    if (messageLength > 255) {
        fprintf(stderr, "Message too long! Max 255 characters allowed.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Prepare to read pixel data
    fseek(input, bmpHeader.offset, SEEK_SET);
    unsigned char *pixelData = malloc(bmpInfoHeader.imageSize);
    fread(pixelData, 1, bmpInfoHeader.imageSize, input);
    fclose(input);

    // Embed message length at the beginning of the pixel data
    pixelData[0] = (unsigned char)messageLength;

    // Embed message into the pixel data LSB
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            // Set the least significant bit of each byte
            pixelData[(i * 8) + 1 + j] = (pixelData[(i * 8) + 1 + j] & 0xFE) | ((message[i] >> (7 - j)) & 1);
        }
    }

    // Write the new BMP file
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Unable to open output file");
        free(pixelData);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, output);
    fwrite(pixelData, 1, bmpInfoHeader.imageSize, output);

    fclose(output);
    free(pixelData);

    printf("Message embedded successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input BMP file> <output BMP file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    embedMessageInBMP(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}