//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

#pragma pack(push, 1) // Ensure structure packing
typedef struct {
    uint16_t bfType;      // Bitmap identifier
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap
    int32_t  biHeight;        // Height of the bitmap
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Image size
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Colors used
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
} RGB;

void flipImage(BITMAPINFOHEADER *infoHeader, RGB *pixels) {
    for (int y = 0; y < HEIGHT / 2; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Swap pixel values
            RGB temp = pixels[y * WIDTH + x];
            pixels[y * WIDTH + x] = pixels[(HEIGHT - 1 - y) * WIDTH + x];
            pixels[(HEIGHT - 1 - y) * WIDTH + x] = temp;
        }
    }
}

void changeBrightnessContrast(RGB *pixels, int brightness, float contrast) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int newRed = (int)(pixels[i].Red * contrast) + brightness;
        int newGreen = (int)(pixels[i].Green * contrast) + brightness;
        int newBlue = (int)(pixels[i].Blue * contrast) + brightness;

        // Clamping
        pixels[i].Red = newRed < 0 ? 0 : (newRed > 255 ? 255 : newRed);
        pixels[i].Green = newGreen < 0 ? 0 : (newGreen > 255 ? 255 : newGreen);
        pixels[i].Blue = newBlue < 0 ? 0 : (newBlue > 255 ? 255 : newBlue);
    }
}

int loadBitmap(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = malloc(WIDTH * HEIGHT * sizeof(RGB));
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), WIDTH * HEIGHT, file);

    fclose(file);
    return 1;
}

int saveBitmap(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return 0;
    }

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(RGB), WIDTH * HEIGHT, file);

    fclose(file);
    return 1;
}

int main() {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB *pixels = NULL;

    // Load BMP file
    if (!loadBitmap("input.bmp", &fileHeader, &infoHeader, &pixels)) {
        return EXIT_FAILURE;
    }

    // Flip the image
    flipImage(&infoHeader, pixels);

    // Change brightness and contrast
    int brightness = 30; // Example brightness
    float contrast = 1.2f; // Example contrast
    changeBrightnessContrast(pixels, brightness, contrast);

    // Save modified image
    if (!saveBitmap("output.bmp", &fileHeader, &infoHeader, pixels)) {
        free(pixels);
        return EXIT_FAILURE;
    }

    // Cleanup
    free(pixels);
    printf("Image processing complete: output.bmp has been created.\n");
    return EXIT_SUCCESS;
}