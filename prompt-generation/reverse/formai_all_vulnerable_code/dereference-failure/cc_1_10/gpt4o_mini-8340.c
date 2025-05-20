//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1) // Ensure that structure packing is 1 byte

typedef struct {
    unsigned short bfType; // BMP file type
    unsigned int bfSize; // Size of the BMP file
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits; // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize; // Size of this header
    int biWidth; // Width of the bitmap
    int biHeight; // Height of the bitmap
    unsigned short biPlanes; // Number of color planes
    unsigned short biBitCount; // Bits per pixel
    unsigned int biCompression; // Compression type
    unsigned int biSizeImage; // Size of the pixel data
    int biXPixPerMeter; // Horizontal resolution
    int biYPixPerMeter; // Vertical resolution
    unsigned int biClrUsed; // Number of colors in the palette
    unsigned int biClrImportant; // Important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

void flipImageVertically(RGB **pixels, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            // Swap pixels
            RGB temp = pixels[y][x];
            pixels[y][x] = pixels[height - y - 1][x];
            pixels[height - y - 1][x] = temp;
        }
    }
}

void adjustBrightness(RGB **pixels, int width, int height, int brightnessChange) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int newRed = pixels[y][x].red + brightnessChange;
            int newGreen = pixels[y][x].green + brightnessChange;
            int newBlue = pixels[y][x].blue + brightnessChange;

            // Clamp the values to stay within [0, 255]
            pixels[y][x].red = newRed < 0 ? 0 : (newRed > 255 ? 255 : newRed);
            pixels[y][x].green = newGreen < 0 ? 0 : (newGreen > 255 ? 255 : newGreen);
            pixels[y][x].blue = newBlue < 0 ? 0 : (newBlue > 255 ? 255 : newBlue);
        }
    }
}

RGB **loadBMP(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return NULL;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *width = infoHeader.biWidth;
    *height = abs(infoHeader.biHeight);

    // Allocate memory for pixel data
    RGB **pixels = malloc((*height) * sizeof(RGB *));
    for (int y = 0; y < *height; y++) {
        pixels[y] = malloc((*width) * sizeof(RGB));
        fread(pixels[y], sizeof(RGB), *width, file);
    }

    fclose(file);
    return pixels;
}

void saveBMP(const char *filename, RGB **pixels, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }

    BITMAPFILEHEADER fileHeader = {0x4D42, 0, 0, 0, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)};
    fileHeader.bfSize = fileHeader.bfOffBits + (width * height * sizeof(RGB));

    BITMAPINFOHEADER infoHeader = {sizeof(BITMAPINFOHEADER), width, height, 1, 24, 0, 0, 2835, 2835, 0, 0};

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    for (int y = 0; y < height; y++) {
        fwrite(pixels[y], sizeof(RGB), width, file);
        free(pixels[y]); // Free each row after writing
    }
    free(pixels); // Free the pixel data array

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness_change>\n", argv[0]);
        return 1;
    }

    int width, height;
    RGB **pixels = loadBMP(argv[1], &width, &height);
    if (!pixels) return 1;

    int brightnessChange = atoi(argv[3]);
    adjustBrightness(pixels, width, height, brightnessChange);
    flipImageVertically(pixels, width, height);

    saveBMP(argv[2], pixels, width, height);

    printf("Image processing complete. Saved to %s\n", argv[2]);
    return 0;
}