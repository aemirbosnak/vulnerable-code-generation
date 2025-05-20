//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t channels;
    uint8_t *data;
} Image;

bool load_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return false;
    }

    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);
    fread(&image->channels, sizeof(uint32_t), 1, fp);

    image->data = malloc(image->width * image->height * image->channels);
    fread(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);
    return true;
}

void save_image(const char *filename, const Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);
    fwrite(&image->channels, sizeof(uint32_t), 1, fp);

    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);
}

void watermark_image(Image *image, const char *message) {
    uint32_t message_length = strlen(message);
    uint32_t message_index = 0;

    for (uint32_t y = 0; y < image->height; y++) {
        for (uint32_t x = 0; x < image->width; x++) {
            for (uint32_t c = 0; c < image->channels; c++) {
                uint8_t pixel = image->data[y * image->width * image->channels + x * image->channels + c];

                if (message_index < message_length) {
                    uint8_t bit = (message[message_index] >> (7 - c)) & 1;
                    pixel |= bit << c;
                    message_index++;
                }

                image->data[y * image->width * image->channels + x * image->channels + c] = pixel;
            }
        }
    }
}

int main() {
    Image image;
    if (!load_image("image.bmp", &image)) {
        return 1;
    }

    watermark_image(&image, "Hello, world!");

    save_image("watermarked_image.bmp", &image);

    return 0;
}