//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Ensure struct packing

typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

void applyGrayscale(unsigned char *pixelData, int width, int height) {
    int rowSize = (width * 3 + 3) & (~3); // Row size must be a multiple of 4
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * rowSize) + (x * 3);
            unsigned char b = pixelData[index];
            unsigned char g = pixelData[index + 1];
            unsigned char r = pixelData[index + 2];
            // Calculate grayscale value
            unsigned char gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
            pixelData[index] = pixelData[index + 1] = pixelData[index + 2] = gray; // Set RGB to grayscale
        }
    }
}

void loadBMP(const char *filename, unsigned char **pixelData, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open BMP file");
        exit(EXIT_FAILURE);
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *pixelData = malloc(infoHeader->biSizeImage);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixelData, infoHeader->biSizeImage, 1, file);
    fclose(file);
}

void saveBMP(const char *filename, unsigned char *pixelData, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save BMP file");
        exit(EXIT_FAILURE);
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelData, infoHeader.biSizeImage, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input BMP file> <output BMP file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char *pixelData = NULL;

    loadBMP(argv[1], &pixelData, &fileHeader, &infoHeader);
    applyGrayscale(pixelData, infoHeader.biWidth, infoHeader.biHeight);
    saveBMP(argv[2], pixelData, fileHeader, infoHeader);

    free(pixelData);
    printf("Image processed and saved successfully.\n");
    return EXIT_SUCCESS;
}