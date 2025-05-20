//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

typedef struct {
    uint32_t size;
    uint8_t *data;
} Watermark;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);
    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    return image;
}

void free_image(Image *image) {
    if (image == NULL) {
        return;
    }

    free(image->data);
    free(image);
}

Watermark *load_watermark(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Watermark *watermark = malloc(sizeof(Watermark));
    if (watermark == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&watermark->size, sizeof(uint32_t), 1, fp);
    watermark->data = malloc(watermark->size);
    if (watermark->data == NULL) {
        perror("malloc");
        free(watermark);
        fclose(fp);
        return NULL;
    }

    fread(watermark->data, watermark->size, 1, fp);
    fclose(fp);

    return watermark;
}

void free_watermark(Watermark *watermark) {
    if (watermark == NULL) {
        return;
    }

    free(watermark->data);
    free(watermark);
}

void embed_watermark(Image *image, Watermark *watermark) {
    uint32_t i;

    for (i = 0; i < watermark->size; i++) {
        image->data[i] = (image->data[i] & 0xF0) | (watermark->data[i] & 0x0F);
    }
}

void extract_watermark(Image *image, Watermark *watermark) {
    uint32_t i;

    for (i = 0; i < watermark->size; i++) {
        watermark->data[i] = image->data[i] & 0x0F;
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image.bmp> <watermark.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    Watermark *watermark = load_watermark(argv[2]);
    if (watermark == NULL) {
        fprintf(stderr, "Error loading watermark: %s\n", argv[2]);
        return 1;
    }

    embed_watermark(image, watermark);

    FILE *fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);
    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);

    free_image(image);
    free_watermark(watermark);

    return 0;
}