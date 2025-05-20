//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Structure to hold BMP file header
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

// Structure to hold BMP information header
typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function to read a BMP file
unsigned char *read_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader) {
    FILE *bmpFile = fopen(filename, "rb");
    if (!bmpFile) {
        perror("Could not open BMP file");
        return NULL;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    if (fileHeader->bfType != 0x4D42) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(bmpFile);
        return NULL;
    }

    int size = fileHeader->bfSize - fileHeader->bfOffBits;
    unsigned char *imgData = (unsigned char *)malloc(size);
    fseek(bmpFile, fileHeader->bfOffBits, SEEK_SET);
    fread(imgData, size, 1, bmpFile);
    fclose(bmpFile);

    return imgData;
}

// Function to write a BMP file
void write_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, unsigned char *imgData) {
    FILE *bmpFile = fopen(filename, "wb");
    if (!bmpFile) {
        perror("Could not open BMP file for writing");
        return;
    }

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);
    fwrite(imgData, (fileHeader->bfSize - fileHeader->bfOffBits), 1, bmpFile);
    fclose(bmpFile);
}

// Function to embed a secret message into the image
void embed_message(unsigned char *imgData, const char *message) {
    int imgSize = strlen((char *)imgData);
    int msgLen = strlen(message);

    if (msgLen * 8 > imgSize) {
        fprintf(stderr, "Message is too long to embed in the image.\n");
        return;
    }

    for (int i = 0; i < msgLen; ++i) {
        for (int j = 0; j < 8; ++j) {
            imgData[i * 8 + j] = (imgData[i * 8 + j] & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }

    // Embed the message length at the end
    imgData[msgLen * 8] = (unsigned char)msgLen;
}

// Function to extract a secret message from the image
void extract_message(unsigned char *imgData, char *message, int maxLen) {
    int msgLen = imgData[maxLen * 8];
    for (int i = 0; i < msgLen; ++i) {
        message[i] = 0;
        for (int j = 0; j < 8; ++j) {
            message[i] |= ((imgData[i * 8 + j] & 1) << (7 - j));
        }
    }
    message[msgLen] = '\0';
}

// Main function to demonstrate steganography
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input-bmp> <output-bmp> <message>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    // Read the BMP file
    unsigned char *imgData = read_bmp(argv[1], &fileHeader, &infoHeader);
    if (imgData == NULL) {
        return 1;
    }

    // Embed the secret message into the image
    embed_message(imgData, argv[3]);

    // Write the modified image to a new BMP file
    write_bmp(argv[2], &fileHeader, &infoHeader, imgData);
    free(imgData);

    printf("Message embedded successfully!\n");

    // Extract the message just for demonstration
    char extractedMessage[100];
    unsigned char *readImgData = read_bmp(argv[2], &fileHeader, &infoHeader);
    extract_message(readImgData, extractedMessage, 100);
    printf("Extracted Message: %s\n", extractedMessage);
    free(readImgData);

    return 0;
}