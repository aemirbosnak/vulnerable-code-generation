//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// BMP file header
#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // BMP file type
    uint32_t bfSize;      // BMP file size in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

// BMP info header
typedef struct {
    uint32_t biSize;          // Size of the info header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Size of the raw bitmap data
    int32_t  biXPelsPerMeter;   // Pixels per meter in X direction
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y direction
    uint32_t biClrUsed;        // Number of colors in the palette
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Structures for pixel data
typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} PIXEL;

void flip_image(PIXEL **image, int width, int height);
void change_brightness(PIXEL **image, int width, int height, int value);
void change_contrast(PIXEL **image, int width, int height, float factor);
void write_bmp(const char *filename, PIXEL **image, int width, int height, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih);
PIXEL **read_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <option> [value]\n", argv[0]);
        printf("Options: flip, brightness [value], contrast [value]\n");
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    PIXEL **image = read_bmp(argv[1], &bfh, &bih);
    
    if (image == NULL) {
        return 1;
    }

    int width = bih.biWidth;
    int height = bih.biHeight;

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(image, width, height);
    } else if (strcmp(argv[3], "brightness") == 0 && argc == 5) {
        int value = atoi(argv[4]);
        change_brightness(image, width, height, value);
    } else if (strcmp(argv[3], "contrast") == 0 && argc == 5) {
        float factor = atof(argv[4]);
        change_contrast(image, width, height, factor);
    } else {
        printf("Invalid option or insufficient arguments.\n");
        return 1;
    }

    write_bmp(argv[2], image, width, height, bfh, bih);

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
    return 0;
}

void flip_image(PIXEL **image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            PIXEL temp = image[y][x];
            image[y][x] = image[y][width - 1 - x];
            image[y][width - 1 - x] = temp;
        }
    }
}

void change_brightness(PIXEL **image, int width, int height, int value) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].red = (image[y][x].red + value > 255) ? 255 : (image[y][x].red + value < 0) ? 0 : (image[y][x].red + value);
            image[y][x].green = (image[y][x].green + value > 255) ? 255 : (image[y][x].green + value < 0) ? 0 : (image[y][x].green + value);
            image[y][x].blue = (image[y][x].blue + value > 255) ? 255 : (image[y][x].blue + value < 0) ? 0 : (image[y][x].blue + value);
        }
    }
}

void change_contrast(PIXEL **image, int width, int height, float factor) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].red = (int)((image[y][x].red - 128) * factor + 128);
            image[y][x].green = (int)((image[y][x].green - 128) * factor + 128);
            image[y][x].blue = (int)((image[y][x].blue - 128) * factor + 128);
            // Clamp values
            if (image[y][x].red < 0) image[y][x].red = 0;
            if (image[y][x].green < 0) image[y][x].green = 0;
            if (image[y][x].blue < 0) image[y][x].blue = 0;
            if (image[y][x].red > 255) image[y][x].red = 255;
            if (image[y][x].green > 255) image[y][x].green = 255;
            if (image[y][x].blue > 255) image[y][x].blue = 255;
        }
    }
}

void write_bmp(const char *filename, PIXEL **image, int width, int height, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    for (int y = 0; y < height; y++) {
        fwrite(image[y], sizeof(PIXEL), width, file);
    }
    
    fclose(file);
}

PIXEL **read_bmp(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfh->bfType != 0x4D42) { // Check if file is BMP
        printf("Not a BMP file.\n");
        fclose(file);
        return NULL;
    }

    PIXEL **image = malloc(bih->biHeight * sizeof(PIXEL *));
    for (int i = 0; i < bih->biHeight; i++) {
        image[i] = malloc(bih->biWidth * sizeof(PIXEL));
        fread(image[i], sizeof(PIXEL), bih->biWidth, file);
    }

    fclose(file);
    return image;
}