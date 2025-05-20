//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BUF_SIZE (1 << 20)

uint8_t *load_image(const char *path, uint32_t *width, uint32_t *height, uint32_t *channels) {
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening image file: %s\n", path);
        return NULL;
    }

    uint8_t *buf = malloc(MAX_BUF_SIZE);
    if (!buf) {
        fprintf(stderr, "Error allocating memory for image buffer\n");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 10, SEEK_SET);
    fread(width, 4, 1, fp);
    fread(height, 4, 1, fp);
    fseek(fp, 28, SEEK_SET);
    fread(channels, 4, 1, fp);

    fseek(fp, 54, SEEK_SET);
    fread(buf, (*width) * (*height) * (*channels), 1, fp);

    fclose(fp);
    return buf;
}

void hide_data(uint8_t *image, uint32_t width, uint32_t height, uint32_t channels, const uint8_t *data, uint32_t data_len) {
    uint32_t i, j, k;
    for (i = 0; i < data_len; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < channels; k++) {
                image[(i * 8 + j) * width * channels + k] &= ~(1 << j);
                image[(i * 8 + j) * width * channels + k] |= ((data[i] >> (7 - j)) & 1) << j;
            }
        }
    }
}

uint8_t *extract_data(const uint8_t *image, uint32_t width, uint32_t height, uint32_t channels, uint32_t *data_len) {
    uint8_t *data = malloc(MAX_BUF_SIZE);
    if (!data) {
        fprintf(stderr, "Error allocating memory for data buffer\n");
        return NULL;
    }

    uint32_t i, j, k;
    for (i = 0; i < MAX_BUF_SIZE; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < channels; k++) {
                data[i] |= ((image[(i * 8 + j) * width * channels + k] >> j) & 1) << (7 - j);
            }
        }

        if (data[i] == 0xff) {
            *data_len = i;
            break;
        }
    }

    return data;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <data file>\n", argv[0]);
        return 1;
    }

    uint32_t width, height, channels;
    uint8_t *image = load_image(argv[1], &width, &height, &channels);
    if (!image) {
        return 1;
    }

    FILE *fp = fopen(argv[3], "rb");
    if (!fp) {
        fprintf(stderr, "Error opening data file: %s\n", argv[3]);
        free(image);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    uint32_t data_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t *data = malloc(data_len);
    if (!data) {
        fprintf(stderr, "Error allocating memory for data buffer\n");
        fclose(fp);
        free(image);
        return 1;
    }

    fread(data, data_len, 1, fp);
    fclose(fp);

    hide_data(image, width, height, channels, data, data_len);

    fp = fopen(argv[2], "wb");
    if (!fp) {
        fprintf(stderr, "Error opening output image file: %s\n", argv[2]);
        free(image);
        free(data);
        return 1;
    }

    fwrite(image, width * height * channels, 1, fp);
    fclose(fp);

    free(image);
    free(data);
    return 0;
}