//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;       // Magic number for BMP files
    uint32_t size;       // Size of the file in bytes
    uint16_t reserved1;  // Reserved; must be zero
    uint16_t reserved2;  // Reserved; must be zero
    uint32_t offset;     // Offset to the start of pixel data
} BMPHeader;

typedef struct {
    uint32_t size;       // Size of this header
    uint32_t width;      // Width of the bitmap in pixels
    uint32_t height;     // Height of the bitmap in pixels
    uint16_t planes;     // Number of color planes
    uint16_t bitCount;   // Bits per pixel
    uint32_t compression; // Compression type
    uint32_t sizeImage;  // Image size (in bytes)
    uint32_t xPelsPerMeter; // Horizontal resolution
    uint32_t yPelsPerMeter; // Vertical resolution
    uint32_t colorsUsed;  // Number of colors in the palette
    uint32_t colorsImportant; // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGBPixel;
#pragma pack(pop)

void flip_image(RGBPixel *pixels, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            RGBPixel temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[(height - 1 - i) * width + j];
            pixels[(height - 1 - i) * width + j] = temp;
        }
    }
}

void change_brightness(RGBPixel *pixels, int width, int height, int delta) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (pixels[i].red + delta > 255) ? 255 : pixels[i].red + delta < 0 ? 0 : pixels[i].red + delta;
        pixels[i].green = (pixels[i].green + delta > 255) ? 255 : pixels[i].green + delta < 0 ? 0 : pixels[i].green + delta;
        pixels[i].blue = (pixels[i].blue + delta > 255) ? 255 : pixels[i].blue + delta < 0 ? 0 : pixels[i].blue + delta;
    }
}

void change_contrast(RGBPixel *pixels, int width, int height, float factor) {
    for (int i = 0; i < width * height; i++) {
        int red = (pixels[i].red - 128) * factor + 128;
        int green = (pixels[i].green - 128) * factor + 128;
        int blue = (pixels[i].blue - 128) * factor + 128;

        pixels[i].red = (red > 255) ? 255 : (red < 0) ? 0 : red;
        pixels[i].green = (green > 255) ? 255 : (green < 0) ? 0 : green;
        pixels[i].blue = (blue > 255) ? 255 : (blue < 0) ? 0 : blue;
    }
}

void load_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *info_header, RGBPixel **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open BMP file");
        exit(EXIT_FAILURE);
    }
    fread(header, sizeof(BMPHeader), 1, file);
    fread(info_header, sizeof(BMPInfoHeader), 1, file);

    fseek(file, header->offset, SEEK_SET);
    *pixels = malloc(info_header->width * info_header->height * sizeof(RGBPixel));
    fread(*pixels, sizeof(RGBPixel), info_header->width * info_header->height, file);
    fclose(file);
}

void save_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *info_header, RGBPixel *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not create BMP file");
        exit(EXIT_FAILURE);
    }
    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(info_header, sizeof(BMPInfoHeader), 1, file);
    
    fseek(file, header->offset, SEEK_SET);
    fwrite(pixels, sizeof(RGBPixel), info_header->width * info_header->height, file);
    fclose(file);
}

int main() {
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    RGBPixel *pixels = NULL;

    char input_file[] = "input.bmp";
    char output_file[] = "output.bmp";

    load_bmp(input_file, &bmpHeader, &bmpInfoHeader, &pixels);
    printf("Loaded: %s, Width: %d, Height: %d\n", input_file, bmpInfoHeader.width, bmpInfoHeader.height);

    flip_image(pixels, bmpInfoHeader.width, bmpInfoHeader.height);
    printf("Flipped the image vertically!\n");

    change_brightness(pixels, bmpInfoHeader.width, bmpInfoHeader.height, 50);
    printf("Increased brightness by 50!\n");

    change_contrast(pixels, bmpInfoHeader.width, bmpInfoHeader.height, 1.5f);
    printf("Adjusted contrast by a factor of 1.5!\n");

    save_bmp(output_file, &bmpHeader, &bmpInfoHeader, pixels);
    printf("Saved processed image as: %s\n", output_file);

    free(pixels);
    return 0;
}