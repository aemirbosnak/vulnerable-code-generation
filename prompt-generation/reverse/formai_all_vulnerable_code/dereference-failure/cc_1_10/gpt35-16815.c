//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red, green, blue;
} pixel_t;

typedef struct {
    pixel_t *pixels;
    size_t width;
    size_t height;
} bitmap_t;

void save_bitmap(const char *filename, bitmap_t *bmp) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        return;
    }

    size_t row_padding = (4 - (bmp->width * sizeof(pixel_t)) % 4) % 4;

    const size_t header_size = 14 + 40;
    unsigned char header[header_size];
    memset(header, 0, header_size);

    // File header
    header[0] = 'B';
    header[1] = 'M';
    *((unsigned int *) &header[2]) = header_size + (bmp->width * bmp->height * sizeof(pixel_t)) + (row_padding * bmp->height);
    *((unsigned int *) &header[10]) = header_size;

    // Info header
    *((unsigned int *) &header[14]) = 40;
    *((unsigned int *) &header[18]) = bmp->width;
    *((unsigned int *) &header[22]) = -bmp->height;
    header[26] = 1;
    header[28] = 24;

    fwrite(header, header_size, 1, file);

    const size_t data_size = bmp->width * bmp->height * sizeof(pixel_t);
    unsigned char *data = malloc(data_size);
    size_t i, j;
    for (i = 0; i < bmp->height; i++) {
        for (j = 0; j < bmp->width; j++) {
            data[(i * bmp->width + j) * 3 + 0] = bmp->pixels[i * bmp->width + j].blue;
            data[(i * bmp->width + j) * 3 + 1] = bmp->pixels[i * bmp->width + j].green;
            data[(i * bmp->width + j) * 3 + 2] = bmp->pixels[i * bmp->width + j].red;
        }
        fwrite(&data[i * bmp->width * 3], sizeof(pixel_t), bmp->width, file);
        fwrite("\0\0\0", 1, row_padding, file);
    }

    free(data);
    fclose(file);
}

int main() {
    bitmap_t bmp = {0};
    bmp.width = 640;
    bmp.height = 480;

    bmp.pixels = calloc(bmp.width * bmp.height, sizeof(pixel_t));
    size_t i, j;
    for (i = 0; i < bmp.height; i++) {
        for (j = 0; j < bmp.width; j++) {
            bmp.pixels[i * bmp.width + j].red = i / 2;
            bmp.pixels[i * bmp.width + j].green = j / 2;
            bmp.pixels[i * bmp.width + j].blue = 0;
        }
    }

    save_bitmap("output.bmp", &bmp);

    free(bmp.pixels);
    return 0;
}