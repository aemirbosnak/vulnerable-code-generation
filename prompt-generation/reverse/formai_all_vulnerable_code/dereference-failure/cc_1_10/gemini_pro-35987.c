//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
    if (image->pixels == NULL) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

void hide_message(image_t *image, const char *message) {
    int message_len = strlen(message);
    for (int i = 0; i < message_len; i++) {
        int bit_idx = i % 8;
        int byte_idx = i / 8;
        int pixel_idx = byte_idx / 3;
        if (pixel_idx >= image->width * image->height) {
            break;
        }

        uint8_t bitmask = 1 << bit_idx;
        pixel_t *pixel = &image->pixels[pixel_idx];
        if (message[i] == '0') {
            pixel->r &= ~bitmask;
        } else {
            pixel->r |= bitmask;
        }
    }
}

char *extract_message(image_t *image) {
    int message_len = image->width * image->height * 8 / 3;
    char *message = malloc(message_len + 1);
    if (message == NULL) {
        perror("malloc");
        return NULL;
    }

    for (int i = 0; i < message_len; i++) {
        int bit_idx = i % 8;
        int byte_idx = i / 8;
        int pixel_idx = byte_idx / 3;
        if (pixel_idx >= image->width * image->height) {
            break;
        }

        uint8_t bitmask = 1 << bit_idx;
        pixel_t *pixel = &image->pixels[pixel_idx];
        message[i] = (pixel->r & bitmask) ? '1' : '0';
    }

    message[message_len] = '\0';
    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <message> <output image>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    hide_message(image, argv[2]);

    save_image(argv[3], image);

    free(image->pixels);
    free(image);

    return 0;
}