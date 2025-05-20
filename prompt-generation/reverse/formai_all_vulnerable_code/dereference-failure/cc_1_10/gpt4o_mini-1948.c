//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the color palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;   // Blue color component
    uint8_t green;  // Green color component
    uint8_t red;    // Red color component
} RGBTRIPLE;
#pragma pack(pop)

void loadImage(const char *filename, BITMAPFILEHEADER *bmh, BITMAPINFOHEADER *ih, RGBTRIPLE **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fread(bmh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(ih, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = malloc(ih->biWidth * ih->biHeight * sizeof(RGBTRIPLE));
    fseek(file, bmh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGBTRIPLE), ih->biWidth * ih->biHeight, file);

    fclose(file);
}

void saveImage(const char *filename, BITMAPFILEHEADER *bmh, BITMAPINFOHEADER *ih, RGBTRIPLE *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(bmh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(ih, sizeof(BITMAPINFOHEADER), 1, file);

    fseek(file, bmh->bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(RGBTRIPLE), ih->biWidth * ih->biHeight, file);
    
    fclose(file);
}

void applyGrayscale(BITMAPINFOHEADER *ih, RGBTRIPLE *pixels) {
    for (int i = 0; i < ih->biHeight; i++) {
        for (int j = 0; j < ih->biWidth; j++) {
            RGBTRIPLE *pixel = &pixels[i * ih->biWidth + j];
            uint8_t gray = (pixel->red + pixel->green + pixel->blue) / 3;
            pixel->red = gray;
            pixel->green = gray;
            pixel->blue = gray;
        }
    }
}

void printUsage() {
    printf("Usage: image_editor <input.bmp> <output.bmp>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER bmh;
    BITMAPINFOHEADER ih;
    RGBTRIPLE *pixels;

    loadImage(argv[1], &bmh, &ih, &pixels);
    applyGrayscale(&ih, pixels);
    saveImage(argv[2], &bmh, &ih, pixels);

    free(pixels);
    printf("Image processing complete!\n");
    return EXIT_SUCCESS;
}