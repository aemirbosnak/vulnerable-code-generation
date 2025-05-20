//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PIXEL_SIZE 3
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

typedef struct {
    pixel *pixels;
    int width;
    int height;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    img->pixels = malloc(IMAGE_WIDTH * IMAGE_HEIGHT * PIXEL_SIZE);
    img->width = IMAGE_WIDTH;
    img->height = IMAGE_HEIGHT;

    if (fread(img->pixels, PIXEL_SIZE, IMAGE_WIDTH * IMAGE_HEIGHT, fp) != IMAGE_WIDTH * IMAGE_HEIGHT * PIXEL_SIZE) {
        fprintf(stderr, "Error: unable to read image data from file %s\n", filename);
        free(img);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return img;
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        return;
    }

    if (fwrite(img->pixels, PIXEL_SIZE, IMAGE_WIDTH * IMAGE_HEIGHT, fp) != IMAGE_WIDTH * IMAGE_HEIGHT * PIXEL_SIZE) {
        fprintf(stderr, "Error: unable to write image data to file %s\n", filename);
    }

    fclose(fp);
}

void hide_message(image *img, const char *message) {
    int message_length = strlen(message);
    int pixel_index = 0;

    for (int i = 0; i < message_length; i++) {
        uint8_t byte = (uint8_t)message[i];

        for (int j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;

            pixel *pixel = &img->pixels[pixel_index];
            pixel->blue = (pixel->blue & 0xFE) | bit;

            pixel_index++;
        }
    }
}

char *extract_message(image *img) {
    char *message = malloc(IMAGE_WIDTH * IMAGE_HEIGHT / 8 + 1);
    int message_length = 0;

    int pixel_index = 0;

    while (pixel_index < IMAGE_WIDTH * IMAGE_HEIGHT) {
        uint8_t byte = 0;

        for (int j = 0; j < 8; j++) {
            byte = (byte << 1) | (img->pixels[pixel_index].blue & 1);
            pixel_index++;
        }

        message[message_length++] = (char)byte;
    }

    message[message_length] = '\0';
    return message;
}

int main() {
    image *img = load_image("image.bmp");

    hide_message(img, "Hello, world!");

    save_image("stego_image.bmp", img);

    char *message = extract_message(img);

    printf("Extracted message: %s\n", message);

    free(img->pixels);
    free(img);
    free(message);

    return 0;
}