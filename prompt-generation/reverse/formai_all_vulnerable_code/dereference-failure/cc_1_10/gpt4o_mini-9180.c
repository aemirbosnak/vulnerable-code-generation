//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure structure packing for BMP header
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_pix_per_meter;
    int32_t y_pix_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} DIBHeader;

#pragma pack(pop)

void apply_grayscale(uint8_t *pixel_data, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_offset = (y * width + x) * 3; // 3 bytes per pixel (RGB)
            uint8_t b = pixel_data[pixel_offset + 0];
            uint8_t g = pixel_data[pixel_offset + 1];
            uint8_t r = pixel_data[pixel_offset + 2];

            // Calculate grayscale value
            uint8_t gray = (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);

            // Assign grayscale value
            pixel_data[pixel_offset + 0] = gray; // Blue
            pixel_data[pixel_offset + 1] = gray; // Green
            pixel_data[pixel_offset + 2] = gray; // Red
        }
    }
}

void load_bmp(const char *filename, BMPHeader *bmp_header, DIBHeader *dib_header, uint8_t **pixel_data) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(bmp_header, sizeof(BMPHeader), 1, file);
    fread(dib_header, sizeof(DIBHeader), 1, file);

    *pixel_data = malloc(dib_header->width * dib_header->height * 3);
    fseek(file, bmp_header->offset_data, SEEK_SET);
    fread(*pixel_data, dib_header->size_image, 1, file);

    fclose(file);
}

void save_bmp(const char *filename, BMPHeader bmp_header, DIBHeader dib_header, uint8_t *pixel_data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving file");
        exit(EXIT_FAILURE);
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, file);
    fwrite(&dib_header, sizeof(DIBHeader), 1, file);
    fwrite(pixel_data, dib_header.size_image, 1, file);

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPHeader bmp_header;
    DIBHeader dib_header;
    uint8_t *pixel_data = NULL;

    load_bmp(argv[1], &bmp_header, &dib_header, &pixel_data);

    if (dib_header.bit_count != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        free(pixel_data);
        return EXIT_FAILURE;
    }

    apply_grayscale(pixel_data, dib_header.width, dib_header.height);
    
    strcpy(bmp_header.type, "BM");
    dib_header.size_image = dib_header.width * dib_header.height * 3;
    bmp_header.size = sizeof(BMPHeader) + sizeof(DIBHeader) + dib_header.size_image;

    save_bmp(argv[2], bmp_header, dib_header, pixel_data);

    free(pixel_data);
    printf("Grayscale conversion completed.\n");
    return EXIT_SUCCESS;
}