//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure correct alignment
typedef struct {
    uint16_t bfType;      // Bitmap identifier
    uint32_t bfSize;      // File size in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to the start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression method
    uint32_t biSizeImage;     // Image size (can be 0 for uncompressed images)
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the color table
    uint32_t biClrImportant;   // Important color count
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGBTRIPLE;

#pragma pack(pop)

void invertColors(RGBTRIPLE *pixels, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE *pixel = &pixels[i * width + j];
            pixel->red = 255 - pixel->red;
            pixel->green = 255 - pixel->green;
            pixel->blue = 255 - pixel->blue;
        }
    }
}

int loadBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGBTRIPLE **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s\n", filename);
        return -1;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    if (fileHeader->bfType != 0x4D42) { // 'BM'
        fprintf(stderr, "Error: Not a valid BMP file\n");
        fclose(file);
        return -1;
    }

    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (infoHeader->biBitCount != 24) { // We only support 24-bit bitmaps
        fprintf(stderr, "Error: Only 24-bit BMP files are supported\n");
        fclose(file);
        return -1;
    }

    int width = infoHeader->biWidth;
    int height = abs(infoHeader->biHeight);
    int rowSize = (width * 3 + 3) & ~3; // Rows need to be padded to 4-byte boundary
    *pixels = (RGBTRIPLE *)malloc(rowSize * height);
    if (!*pixels) {
        fprintf(stderr, "Error: Could not allocate memory for pixel data\n");
        fclose(file);
        return -1;
    }

    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGBTRIPLE), width * height, file);
    fclose(file);

    return width;
}

int saveBMP(const char *filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGBTRIPLE *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open %s for writing\n", filename);
        return -1;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight);
    int rowSize = (width * 3 + 3) & ~3;

    // Write pixel data
    fwrite(pixels, sizeof(RGBTRIPLE), width * height, file);
    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGBTRIPLE *pixels = NULL;

    int width = loadBMP(argv[1], &fileHeader, &infoHeader, &pixels);
    if (width < 0) {
        return 1;
    }

    // Invert colors
    invertColors(pixels, width, abs(infoHeader.biHeight));

    // Save the modified BMP
    if (saveBMP(argv[2], fileHeader, infoHeader, pixels) < 0) {
        free(pixels);
        return 1;
    }

    free(pixels);
    printf("Image processed and saved to %s\n", argv[2]);
    return 0;
}