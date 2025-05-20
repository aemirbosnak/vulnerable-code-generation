//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offBits;
} BMPHeader;

typedef struct {
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;
#pragma pack()

void hideMessageInBMP(const char* bmpFile, const char* message) {
    FILE *file = fopen(bmpFile, "rb+");
    if (!file) {
        fprintf(stderr, "Error opening BMP file.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    if (bmpHeader.type != 0x4D42) { 
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    // Move the file position to the beginning of the pixel data
    fseek(file, bmpHeader.offBits, SEEK_SET);

    // Calculate the number of characters that fit in the pixels
    long pixelCount = (bmpInfoHeader.width * bmpInfoHeader.height) * (bmpInfoHeader.bitCount / 8);
    size_t messageLength = strlen(message);

    if (messageLength * 8 > pixelCount) {
        fprintf(stderr, "Message is too long to hide in this image.\n");
        fclose(file);
        return;
    }

    // Append the ending character
    strcat(message, "\0");

    for (size_t i = 0; i < messageLength; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);

            // Hide the bit of the message in the least significant bit of the pixel
            pixel[0] = (pixel[0] & 0xFE) | ((c >> (7 - j)) & 0x01);

            fseek(file, -3, SEEK_CUR);  // Go back to write the modified pixel
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);
    printf("Message hidden in BMP file successfully.\n");
}

void extractMessageFromBMP(const char* bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        fprintf(stderr, "Error opening BMP file.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    if (bmpHeader.type != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    // Move the file position to the beginning of the pixel data
    fseek(file, bmpHeader.offBits, SEEK_SET);

    char message[256] = {0};
    size_t messageLength = 0;

    while (messageLength < 255) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, file);
            c = (c << 1) | (pixel[0] & 0x01);
        }
        message[messageLength++] = c;

        if (c == '\0') break; // End of message
    }

    fclose(file);
    printf("Extracted message: %s\n", message);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hide/extract> <bmp file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessageInBMP(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessageFromBMP(argv[2]);
    } else {
        printf("Invalid operation. Use 'hide' or 'extract'.\n");
    }

    return 0;
}