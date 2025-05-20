//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define BITDEPTH 8

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

typedef struct {
    uint32_t num_bits;
    uint8_t *data;
} Watermark;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);
    image->data = malloc(image->width * image->height * BITDEPTH / 8);
    if (image->data == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * BITDEPTH / 8, 1, fp);
    fclose(fp);

    return image;
}

void write_image(char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);
    fwrite(image->data, image->width * image->height * BITDEPTH / 8, 1, fp);
    fclose(fp);
}

Watermark *read_watermark(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Watermark *watermark = malloc(sizeof(Watermark));
    if (watermark == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&watermark->num_bits, sizeof(uint32_t), 1, fp);
    watermark->data = malloc(watermark->num_bits);
    if (watermark->data == NULL) {
        fclose(fp);
        free(watermark);
        return NULL;
    }

    fread(watermark->data, watermark->num_bits, 1, fp);
    fclose(fp);

    return watermark;
}

void write_watermark(char *filename, Watermark *watermark) {
    FILE *fp = fopen(filename, "wb");
    fwrite(&watermark->num_bits, sizeof(uint32_t), 1, fp);
    fwrite(watermark->data, watermark->num_bits, 1, fp);
    fclose(fp);
}

void embed_watermark(Image *image, Watermark *watermark) {
    uint32_t x, y, i, j;
    double r, g, b;

    for (i = 0; i < watermark->num_bits; i++) {
        x = i % image->width;
        y = i / image->width;

        r = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 0];
        g = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 1];
        b = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 2];

        if (watermark->data[i] == 0) {
            r += 1;
            g -= 1;
            b += 1;
        } else {
            r -= 1;
            g += 1;
            b -= 1;
        }

        image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 0] = r;
        image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 1] = g;
        image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 2] = b;
    }
}

Watermark *extract_watermark(Image *image, uint32_t num_bits) {
    uint32_t x, y, i, j;
    double r, g, b;
    Watermark *watermark = malloc(sizeof(Watermark));
    watermark->data = malloc(num_bits);

    for (i = 0; i < num_bits; i++) {
        x = i % image->width;
        y = i / image->width;

        r = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 0];
        g = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 1];
        b = image->data[y * image->width * BITDEPTH / 8 + x * BITDEPTH / 8 + 2];

        if (r > g && r > b) {
            watermark->data[i] = 0;
        } else {
            watermark->data[i] = 1;
        }
    }

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <input watermark> <output watermarked image> <output extracted watermark>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Could not read image\n");
        return 1;
    }

    Watermark *watermark = read_watermark(argv[2]);
    if (watermark == NULL) {
        fprintf(stderr, "Could not read watermark\n");
        return 1;
    }

    embed_watermark(image, watermark);
    write_image(argv[3], image);

    Watermark *extracted_watermark = extract_watermark(image, watermark->num_bits);
    write_watermark(argv[4], extracted_watermark);

    return 0;
}