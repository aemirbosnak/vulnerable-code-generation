//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGB;

typedef struct {
    uint32_t width;
    uint32_t height;
    RGB *data;
} Image;

Image *read_image(const char *filename) {
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

    image->data = malloc(image->width * image->height * sizeof(RGB));
    if (image->data == NULL) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, sizeof(RGB), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);

    fwrite(image->data, sizeof(RGB), image->width * image->height, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        printf("Error reading input image\n");
        return 1;
    }

    char *message = argv[3];
    uint32_t message_length = strlen(message);

    if (message_length > image->width * image->height) {
        printf("Message too long for image\n");
        return 1;
    }

    for (uint32_t i = 0; i < message_length; i++) {
        char c = message[i];
        for (uint32_t j = 0; j < 8; j++) {
            uint32_t bit = (c >> j) & 1;
            uint32_t x = i % image->width;
            uint32_t y = i / image->width;
            RGB *pixel = &image->data[y * image->width + x];
            pixel->red = (pixel->red & ~1) | bit;
        }
    }

    write_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}