//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <err.h>

#define MAX_SIZE 1024 * 1024 * 10

uint8_t *load_image(const char *filename, size_t *size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        err(1, "fopen");
    }

    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);

    uint8_t *data = malloc(*size);
    if (!data) {
        fclose(fp);
        err(1, "malloc");
    }

    fread(data, 1, *size, fp);
    fclose(fp);

    return data;
}

void save_image(const char *filename, const uint8_t *data, size_t size) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        err(1, "fopen");
    }

    fwrite(data, 1, size, fp);
    fclose(fp);
}

void hide_data(uint8_t *image, size_t size, const uint8_t *data, size_t data_size) {
    if (size < data_size) {
        errx(1, "Image size is too small to hide data");
    }

    for (size_t i = 0; i < data_size; i++) {
        image[i] = (image[i] & 0xf0) | (data[i] & 0xf);
    }
}

void reveal_data(const uint8_t *image, size_t size, uint8_t *data, size_t data_size) {
    for (size_t i = 0; i < data_size; i++) {
        data[i] = image[i] & 0xf;
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <input data> <output data>\n", argv[0]);
        return 1;
    }

    size_t image_size;
    uint8_t *image_data = load_image(argv[1], &image_size);

    size_t data_size;
    uint8_t *data = load_image(argv[3], &data_size);

    hide_data(image_data, image_size, data, data_size);
    save_image(argv[2], image_data, image_size);

    uint8_t *revealed_data = malloc(data_size);
    reveal_data(image_data, image_size, revealed_data, data_size);
    save_image(argv[4], revealed_data, data_size);

    free(image_data);
    free(data);
    free(revealed_data);

    return 0;
}