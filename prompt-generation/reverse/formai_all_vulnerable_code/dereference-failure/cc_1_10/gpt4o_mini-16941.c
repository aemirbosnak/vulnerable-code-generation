//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // The file type; must be 'BM' which is 0x4D42
    unsigned int bfSize;       // The size of the BMP file in bytes
    unsigned short bfReserved1; // Reserved; must be 0
    unsigned short bfReserved2; // Reserved; must be 0
    unsigned int bfOffBits;     // The offset of the pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;         // The size of this header
    int biWidth;                 // The width of the bitmap in pixels
    int biHeight;                // The height of the bitmap in pixels
    unsigned short biPlanes;     // The number of color planes; must be 1
    unsigned short biBitCount;   // The number of bits per pixel
    unsigned int biCompression;   // The compression method
    unsigned int biSizeImage;    // The size of the image data
    int biXPelsPerMeter;         // The horizontal resolution, pixels per meter
    int biYPelsPerMeter;         // The vertical resolution, pixels per meter
    unsigned int biClrUsed;      // The number of colors in the color palette
    unsigned int biClrImportant;  // The number of important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;          // Blue
    unsigned char green;         // Green
    unsigned char red;           // Red
} RGB;
#pragma pack(pop)

void applyGrayscale(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

void readBitmap(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *pixels = (RGB *)malloc(infoHeader->biWidth * infoHeader->biHeight * sizeof(RGB));
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
}

void writeBitmap(const char *filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, file);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB *pixels = NULL;

    readBitmap(argv[1], &fileHeader, &infoHeader, &pixels);
    applyGrayscale(pixels, infoHeader.biWidth, infoHeader.biHeight);
    writeBitmap(argv[2], fileHeader, infoHeader, pixels);

    free(pixels);
    printf("Successfully converted %s to grayscale and saved as %s\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}