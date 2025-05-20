//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    short int bfReserved1;
    short int bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned short int bfType;
    unsigned int bfSize;
    unsigned short int bfReserved1;
    unsigned short int bfReserved2;
    unsigned int bfOffDIB;
} DIBHEADERTAG;

typedef struct {
    unsigned int dibHeaderSize;
    unsigned int width;
    unsigned int height;
    unsigned short int colorPlanes;
    unsigned short int bpp;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *imageFile = fopen(argv[1], "rb");
    if (!imageFile) {
        perror("Error opening file");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    DIBHEADERTAG diBHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, imageFile);
    if (fileHeader.bfType[0] != 'B' || fileHeader.bfType[1] != 'M') {
        fprintf(stderr, "Invalid BMP file\n");
        return 1;
    }

    fread(&diBHeader, sizeof(DIBHEADERTAG), 1, imageFile);
    if (diBHeader.bfType != 0x4D42) {
        fprintf(stderr, "Invalid DIB header\n");
        return 1;
    }

    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, imageFile);

    printf("Image metadata:\n");
    printf("Width: %d\n", infoHeader.width);
    printf("Height: %d\n", infoHeader.height);
    printf("Color depth: %d bits per pixel\n", infoHeader.bpp);

    fclose(imageFile);
    return 0;
}