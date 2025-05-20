//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

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
    uint32_t biCirImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

void flip_image(RGB* pixels, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            RGB temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[(height - 1 - i) * width + j];
            pixels[(height - 1 - i) * width + j] = temp;
        }
    }
}

void adjust_brightness(RGB* pixels, int width, int height, int adjustment) {
    for (int i = 0; i < width * height; i++) {
        int new_red = (int)pixels[i].red + adjustment;
        int new_green = (int)pixels[i].green + adjustment;
        int new_blue = (int)pixels[i].blue + adjustment;

        pixels[i].red = (new_red > 255) ? 255 : (new_red < 0) ? 0 : new_red;
        pixels[i].green = (new_green > 255) ? 255 : (new_green < 0) ? 0 : new_green;
        pixels[i].blue = (new_blue > 255) ? 255 : (new_blue < 0) ? 0 : new_blue;
    }
}

void load_bmp(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGB** pixels) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Opening file");
        exit(EXIT_FAILURE);
    }

    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    *pixels = malloc(bih->biWidth * bih->biHeight * sizeof(RGB));
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), bih->biWidth * bih->biHeight, file);

    fclose(file);
}

void save_bmp(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih, RGB* pixels) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Creating file");
        exit(EXIT_FAILURE);
    }

    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(RGB), bih->biWidth * bih->biHeight, file);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness adjustment>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB* pixels;

    load_bmp(argv[1], &bfh, &bih, &pixels);
    
    printf("Loaded image with dimensions: %dx%d\n", bih.biWidth, bih.biHeight);

    // Adjust brightness
    int brightness_adjustment = atoi(argv[3]);
    adjust_brightness(pixels, bih.biWidth, bih.biHeight, brightness_adjustment);
    
    // Flip the image vertically
    flip_image(pixels, bih.biWidth, bih.biHeight);

    // Save the modified image
    save_bmp(argv[2], &bfh, &bih, pixels);
    
    free(pixels);
    printf("Image processing complete!\n");

    return 0;
}