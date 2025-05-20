//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
// BMP header sizes
typedef struct {
    unsigned char  signature[2];
    unsigned int   fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int   dataOffset;
} BMPHeader;

typedef struct {
    unsigned int   size;
    int            width;
    int            height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int   compression;
    unsigned int   imageSize;
    int            xPixelsPerMeter;
    int            yPixelsPerMeter;
    unsigned int   colorsUsed;
    unsigned int   importantColors;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessageInBMP(const char *inputImagePath, const char *outputImagePath, const char *message) {
    FILE *inputFile, *outputFile;
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    int messageLength = strlen(message);
    int padding = (4 - (bmpInfoHeader.width * 3) % 4) % 4; // Calculate padding
    int i, j;

    inputFile = fopen(inputImagePath, "rb");
    if (!inputFile) {
        perror("Unable to open input BMP file");
        return;
    }

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    // Check if the BMP format is supported
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    outputFile = fopen(outputImagePath, "wb");
    if (!outputFile) {
        perror("Unable to create output BMP file");
        fclose(inputFile);
        return;
    }

    // Write the header to the output file
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    // Read pixels and embed the message in the least significant bits
    unsigned char pixel[3];
    int msgIndex = 0, bitIndex = 0;

    for (i = 0; i < bmpInfoHeader.height; i++) {
        for (j = 0; j < bmpInfoHeader.width; j++) {
            fread(pixel, sizeof(unsigned char), 3, inputFile);
            if (msgIndex < messageLength) {
                // Embed the message bit by bit
                pixel[0] = (pixel[0] & 0xFE) | ((message[msgIndex] >> (7 - bitIndex)) & 0x01);
                bitIndex++;

                // Move to the next character if necessary
                if (bitIndex == 8) {
                    bitIndex = 0;
                    msgIndex++;
                }
            }
            fwrite(pixel, sizeof(unsigned char), 3, outputFile);
        }
        // Skip padding
        fseek(inputFile, padding, SEEK_CUR);
        for (int p = 0; p < padding; p++)
            fputc(0, outputFile); // Match padding in output
    }

    fclose(inputFile);
    fclose(outputFile);
}

void extractMessageFromBMP(const char *imagePath) {
    FILE *inputFile;
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    unsigned char pixel[3];
    int i, j;
    
    inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("Unable to open BMP file");
        return;
    }

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    printf("Extracted message: ");
    while (1) {
        char ch = 0;
        for (int bit = 7; bit >= 0; bit--) {
            for (i = 0; i < bmpInfoHeader.height; i++) {
                for (j = 0; j < bmpInfoHeader.width; j++) {
                    fread(pixel, sizeof(unsigned char), 3, inputFile);
                    ch |= ((pixel[0] & 0x01) << bit);
                    if (bit == 0) break;
                }
                if (bit == 0) break;
            }
            if (ch == 0) { // End of message
                printf("\n");
                fclose(inputFile);
                return;
            }
            putchar(ch);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <embed|extract> <input_file> <output_file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessageInBMP(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}