//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IMAGE_WIDTH  512
#define IMAGE_HEIGHT 512
#define MAX_PIXELS   IMAGE_WIDTH * IMAGE_HEIGHT

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[MAX_PIXELS];
} Image;

void read_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Skip the BMP header (54 bytes)
    fseek(file, 54, SEEK_SET);
    fread(img->pixels, sizeof(Pixel), MAX_PIXELS, file);
    fclose(file);
}

void write_image(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write BMP header
    uint8_t bmpHeader[54] = {
        0x42, 0x4D,        // BMP signature
        0, 0, 0, 0,       // File size (we will fill this in later)
        0, 0, 0, 0,       // Reserved
        0x36, 0, 0, 0,    // Offset to pixel array
        0x28, 0, 0, 0,    // Header size
        IMAGE_WIDTH & 0xFF, (IMAGE_WIDTH >> 8) & 0xFF, (IMAGE_WIDTH >> 16) & 0xFF, (IMAGE_WIDTH >> 24) & 0xFF, // Width
        IMAGE_HEIGHT & 0xFF, (IMAGE_HEIGHT >> 8) & 0xFF, (IMAGE_HEIGHT >> 16) & 0xFF, (IMAGE_HEIGHT >> 24) & 0xFF, // Height
        0x01, 0x00,        // Planes
        0x18, 0x00,        // Bits per pixel
        0, 0, 0, 0,        // Compression
        0, 0, 0, 0,        // Image size
        0x13, 0x0B, 0, 0,  // Horizontal resolution
        0x13, 0x0B, 0, 0,  // Vertical resolution
        0, 0, 0, 0,        // Colors in color palette
        0, 0, 0, 0         // Important color count
    };

    // Calculate the file size
    uint32_t fileSize = sizeof(bmpHeader) + sizeof(Pixel) * MAX_PIXELS;
    bmpHeader[2] = (fileSize & 0xFF);
    bmpHeader[3] = ((fileSize >> 8) & 0xFF);
    bmpHeader[4] = ((fileSize >> 16) & 0xFF);
    bmpHeader[5] = ((fileSize >> 24) & 0xFF);

    fwrite(bmpHeader, sizeof(bmpHeader), 1, file);
    fwrite(img->pixels, sizeof(Pixel), MAX_PIXELS, file);
    fclose(file);
}

void embed_watermark(Image *img, const char *watermark) {
    size_t len = strlen(watermark);
    for (size_t i = 0; i < len; i++) {
        int index = (i % MAX_PIXELS);
        img->pixels[index].r = (img->pixels[index].r & 0xFE) | ((watermark[i] >> 7) & 0x01);
        img->pixels[index].g = (img->pixels[index].g & 0xFE) | ((watermark[i] >> 6) & 0x01);
        img->pixels[index].b = (img->pixels[index].b & 0xFE) | ((watermark[i] >> 5) & 0x01);
    }
}

void extract_watermark(const Image *img, char *watermark, size_t watermark_length) {
    for (size_t i = 0; i < watermark_length; i++) {
        int index = (i % MAX_PIXELS);
        watermark[i] = 0; // Initialize the character
        watermark[i] |= ((img->pixels[index].r & 0x01) << 7);
        watermark[i] |= ((img->pixels[index].g & 0x01) << 6);
        watermark[i] |= ((img->pixels[index].b & 0x01) << 5);
    }
    watermark[watermark_length] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <watermark_text> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_image = argv[1];
    const char *watermark_text = argv[2];
    const char *output_image = argv[3];

    Image img;
    read_image(input_image, &img);
    embed_watermark(&img, watermark_text);
    write_image(output_image, &img);

    char extracted[256];
    extract_watermark(&img, extracted, strlen(watermark_text));
    printf("Extracted watermark: %s\n", extracted);

    return EXIT_SUCCESS;
}