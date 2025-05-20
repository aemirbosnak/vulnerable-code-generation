//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header structure
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXpelsPerMeter;
    long biYpelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void writeMessageToBMP(const char *bmpFile, const char *message) {
    FILE *file = fopen(bmpFile, "rb+");
    if (!file) {
        perror("Could not open BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    // Read the BMP headers
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Move to the pixel data
    fseek(file, bfh.bfOffBits, SEEK_SET);
    
    // Insert the message into the pixel data
    int messageLen = strlen(message);
    if (messageLen > bih.biWidth * bih.biHeight * 3) {
        fprintf(stderr, "Message is too large for BMP\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < messageLen; i++) {
        unsigned char byte = (unsigned char)message[i];
        fread(&byte, sizeof(unsigned char), 1, file);
        fseek(file, -1, SEEK_CUR);
        fwrite(&byte, sizeof(unsigned char), 1, file);
    }

    // Write a null terminator at the end of the message
    unsigned char nullByte = 0;
    fwrite(&nullByte, sizeof(unsigned char), 1, file);
    
    fclose(file);
    printf("Message successfully written to %s\n", bmpFile);
}

void readMessageFromBMP(const char *bmpFile) {
    FILE *file = fopen(bmpFile, "rb");
    if (!file) {
        perror("Could not open BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    // Read the BMP headers
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Move to the pixel data
    fseek(file, bfh.bfOffBits, SEEK_SET);

    // Read the message from the pixel data
    unsigned char byte;
    char message[256] = {0};
    int i = 0;
    while (i < 255) {
        fread(&byte, sizeof(unsigned char), 1, file);
        if (byte == 0) {
            break;
        }
        message[i++] = byte;
    }

    fclose(file);
    printf("Extracted message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <bmp_file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    writeMessageToBMP(argv[1], argv[2]);
    readMessageFromBMP(argv[1]);

    return EXIT_SUCCESS;
}