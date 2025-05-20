//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;      // The file type; must be "BM"
    unsigned int bfSize;       // The size of the file in bytes
    unsigned short bfReserved1; // Reserved; must be zero
    unsigned short bfReserved2; // Reserved; must be zero
    unsigned int bfOffBits;     // The offset of the pixel array
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;          // The size of this header in bytes
    int biWidth;                  // The width of the bitmap in pixels
    int biHeight;                 // The height of the bitmap in pixels
    unsigned short biPlanes;      // The number of color planes
    unsigned short biBitCount;    // The number of bits per pixel
    unsigned int biCompression;    // The type of compression
    unsigned int biSizeImage;      // The size of the pixel data
    int biXPelsPerMeter;          // The horizontal resolution of the image
    int biYPelsPerMeter;          // The vertical resolution of the image
    unsigned int biClrUsed;       // The number of colors in the color palette
    unsigned int biClrImportant;  // The number of important colors
} BITMAPINFOHEADER;

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *imgFile = fopen(inputImage, "rb");
    if (!imgFile) {
        perror("Failed to open image file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(bmpFileHeader), 1, imgFile);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, imgFile);

    long dataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char *imageData = (unsigned char *)malloc(dataSize);
    fseek(imgFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, dataSize, imgFile);
    fclose(imgFile);

    int messageLength = strlen(message);
    if (messageLength > dataSize / 8) {
        fprintf(stderr, "Message is too long to be hidden in the image\n");
        free(imageData);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < messageLength; i++) {
        for (int b = 0; b < 8; b++) {
            int pos = i * 8 + b;
            unsigned char bit = (message[i] >> (7 - b)) & 1;
            imageData[pos] = (imageData[pos] & 0xFE) | bit; // clear LSB and set it to the bit
        }
    }
    
    FILE *outImgFile = fopen(outputImage, "wb");
    fwrite(&bmpFileHeader, sizeof(bmpFileHeader), 1, outImgFile);
    fwrite(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, outImgFile);
    fwrite(imageData, 1, dataSize, outImgFile);
    fclose(outImgFile);
    free(imageData);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char *inputImage) {
    FILE *imgFile = fopen(inputImage, "rb");
    if (!imgFile) {
        perror("Failed to open image file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpFileHeader, sizeof(bmpFileHeader), 1, imgFile);
    fread(&bmpInfoHeader, sizeof(bmpInfoHeader), 1, imgFile);

    long dataSize = bmpFileHeader.bfSize - bmpFileHeader.bfOffBits;
    unsigned char *imageData = (unsigned char *)malloc(dataSize);
    fseek(imgFile, bmpFileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 1, dataSize, imgFile);
    fclose(imgFile);

    char message[256] = {0}; 
    int messageLength = 0;

    for (int i = 0; i < 256; i++) {
        char character = 0;
        for (int b = 0; b < 8; b++) {
            int pos = i * 8 + b;
            if (pos >= dataSize) break; 
            character |= ((imageData[pos] & 1) << (7 - b));
        }
        if (character == '\0') break; 
        message[i] = character;
        messageLength++;
    }

    printf("Extracted Message: %s\n", message);

    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <image file> <output file/message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
    }

    return 0;
}