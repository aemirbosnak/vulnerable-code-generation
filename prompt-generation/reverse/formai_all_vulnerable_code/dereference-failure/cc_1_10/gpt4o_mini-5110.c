//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPFileHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixPerMeter;
    int32_t yPixPerMeter;
    uint32_t colorUsed;
    uint32_t colorImportant;
} BMPInfoHeader;
#pragma pack(pop)

typedef struct {
    unsigned char b, g, r;
} Pixel;

Pixel** allocate_image(int width, int height) {
    Pixel** image = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        image[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }
    return image;
}

void free_image(Pixel** image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

void read_bmp(const char* filename, Pixel*** image, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open BMP file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    
    BMPInfoHeader infoHeader;
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    *width = infoHeader.width;
    *height = infoHeader.height;

    // Allocate memory for the image
    *image = allocate_image(*width, *height);

    fseek(file, fileHeader.offset, SEEK_SET); // Move to pixel data

    // Read pixel data
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            fread(&(*image)[y][x], sizeof(Pixel), 1, file);
        }
    }

    fclose(file);
}

void save_bmp(const char* filename, Pixel** image, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to save BMP file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fileHeader.type = 0x4D42;
    fileHeader.size = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + width * height * sizeof(Pixel);
    fileHeader.reserved1 = 0;
    fileHeader.reserved2 = 0;
    fileHeader.offset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    
    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.planes = 1;
    infoHeader.bitCount = 24;
    infoHeader.compression = 0;
    infoHeader.sizeImage = width * height * sizeof(Pixel);
    infoHeader.xPixPerMeter = 0;
    infoHeader.yPixPerMeter = 0;
    infoHeader.colorUsed = 0;
    infoHeader.colorImportant = 0;

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Write pixel data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&image[y][x], sizeof(Pixel), 1, file);
        }
    }

    fclose(file);
}

void invert_colors(Pixel** image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].r = 255 - image[y][x].r;
            image[y][x].g = 255 - image[y][x].g;
            image[y][x].b = 255 - image[y][x].b;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Pixel** image;
    int width, height;

    read_bmp(argv[1], &image, &width, &height);
    invert_colors(image, width, height);
    save_bmp(argv[2], image, width, height);

    free_image(image, height);
    
    printf("Image processing completed. Check output file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}