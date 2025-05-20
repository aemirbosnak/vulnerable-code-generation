//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(sizeof(pixel_t) * image->width * image->height);
    if (!image->pixels) {
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
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);
}

void hide_message(image_t *image, const char *message) {
    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char byte = message[index];
        for (int j = 0; j < 8; j++) {
            image->pixels[i].r &= ~(1 << j);
            image->pixels[i].r |= ((byte >> (7 - j)) & 1) << j;
        }
        index++;
        if (!message[index]) {
            break;
        }
    }
}

char *extract_message(image_t *image) {
    char *message = malloc(image->width * image->height);
    if (!message) {
        perror("malloc");
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= ((image->pixels[i].r >> j) & 1) << (7 - j);
        }
        message[index] = byte;
        index++;
        if (!message[index]) {
            break;
        }
    }

    return message;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    hide_message(image, argv[3]);

    save_image(argv[2], image);

    free(image->pixels);
    free(image);

    return 0;
}