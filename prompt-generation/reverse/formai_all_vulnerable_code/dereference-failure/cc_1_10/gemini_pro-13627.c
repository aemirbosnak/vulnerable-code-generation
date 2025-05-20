//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


typedef struct {
    uint8_t *data;
    size_t size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    image->data = malloc(size);
    if (image->data == NULL) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, 1, size, fp);
    fclose(fp);

    image->size = size;
    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(image->data, 1, image->size, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    size_t i, j;
    for (i = 0; i < image->size; i++) {
        for (j = 0; j < 8; j++) {
            uint8_t bit = (watermark[i / 8] >> j) & 1;
            image->data[i] ^= (-bit ^ image->data[i]) & (1 << j);
        }
    }
}

char *extract_watermark(Image *image) {
    size_t i, j;
    char *watermark = malloc(image->size / 8 + 1);
    if (watermark == NULL) {
        perror("malloc");
        return NULL;
    }

    for (i = 0; i < image->size / 8; i++) {
        for (j = 0; j < 8; j++) {
            watermark[i] |= ((image->data[i * 8 + j] >> j) & 1) << j;
        }
    }

    watermark[image->size / 8] = '\0';
    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <watermark> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    embed_watermark(image, argv[2]);
    write_image(argv[3], image);
    free(image);

    image = read_image(argv[3]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    char *watermark = extract_watermark(image);
    if (watermark == NULL) {
        free(image);
        return EXIT_FAILURE;
    }

    printf("Detected watermark: %s\n", watermark);
    free(image);
    free(watermark);

    return EXIT_SUCCESS;
}