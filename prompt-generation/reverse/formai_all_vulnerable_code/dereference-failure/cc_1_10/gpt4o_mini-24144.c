//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} BMPInfoHeader;
#pragma pack(pop)

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB;

RGB **load_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    
    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    if (header->type != 0x4D42) {
        printf("Not a BMP file.\n");
        fclose(file);
        return NULL;
    }
    
    RGB **image = (RGB **)malloc(infoHeader->height * sizeof(RGB *));
    for (int i = 0; i < infoHeader->height; i++) {
        image[i] = (RGB *)malloc(infoHeader->width * sizeof(RGB));
    }
    
    fseek(file, header->offset, SEEK_SET);
    
    for (int y = infoHeader->height - 1; y >= 0; y--) {
        for (int x = 0; x < infoHeader->width; x++) {
            fread(&image[y][x], sizeof(RGB), 1, file);
        }
    }

    fclose(file);
    return image;
}

void save_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, RGB **image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }
    
    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    for (int y = infoHeader->height - 1; y >= 0; y--) {
        for (int x = 0; x < infoHeader->width; x++) {
            fwrite(&image[y][x], sizeof(RGB), 1, file);
        }
    }

    fclose(file);
}

void grayscale(RGB **image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t gray = (uint8_t)(0.3 * image[y][x].r + 0.59 * image[y][x].g + 0.11 * image[y][x].b);
            image[y][x].r = gray;
            image[y][x].g = gray;
            image[y][x].b = gray;
        }
    }
}

void invert_colors(RGB **image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x].r = 255 - image[y][x].r;
            image[y][x].g = 255 - image[y][x].g;
            image[y][x].b = 255 - image[y][x].b;
        }
    }
}

void free_image(RGB **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

void print_usage() {
    printf("Usage: bmp_editor <input_file> <output_file> <operation>\n");
    printf("Operations:\n");
    printf("  gray      - Convert to grayscale\n");
    printf("  invert    - Invert colors\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;
    RGB **image = load_bmp(argv[1], &header, &infoHeader);
    if (image == NULL) {
        return 1;
    }
    
    if (strcmp(argv[3], "gray") == 0) {
        grayscale(image, infoHeader.width, infoHeader.height);
    } else if (strcmp(argv[3], "invert") == 0) {
        invert_colors(image, infoHeader.width, infoHeader.height);
    } else {
        print_usage();
        free_image(image, infoHeader.height);
        return 1;
    }

    save_bmp(argv[2], &header, &infoHeader, image);
    
    free_image(image, infoHeader.height);
    
    return 0;
}