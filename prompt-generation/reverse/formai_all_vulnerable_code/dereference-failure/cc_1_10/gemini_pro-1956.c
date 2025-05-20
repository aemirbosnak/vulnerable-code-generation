//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

image_t *image_new(int width, int height) {
    image_t *image = malloc(sizeof(image_t));
    if (!image) return NULL;

    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(pixel_t) * width * height);
    if (!image->pixels) {
        free(image);
        return NULL;
    }

    memset(image->pixels, 0, sizeof(pixel_t) * width * height);

    return image;
}

void image_free(image_t *image) {
    if (!image) return;

    if (image->pixels) free(image->pixels);
    free(image);
}

int image_load(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    image->pixels = malloc(sizeof(pixel_t) * image->width * image->height);
    if (!image->pixels) {
        fclose(file);
        return -1;
    }

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, file);

    fclose(file);

    return 0;
}

int image_save(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, file);

    fclose(file);

    return 0;
}

int image_encode(image_t *image, const char *message) {
    int i, j, k;
    int message_length = strlen(message);
    uint8_t *message_bytes = (uint8_t *)message;

    for (i = 0, k = 0; i < image->height && k < message_length; i++) {
        for (j = 0; j < image->width && k < message_length; j++) {
            image->pixels[i * image->width + j].red &= 0xfe;
            image->pixels[i * image->width + j].red |= message_bytes[k] & 0x01;
            k++;
        }
    }

    return 0;
}

int image_decode(image_t *image, char *message) {
    int i, j, k;
    int message_length = 0;
    uint8_t *message_bytes = (uint8_t *)message;

    for (i = 0, k = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            message_bytes[k] |= (image->pixels[i * image->width + j].red & 0x01);
            if (message_bytes[k] == '\0') {
                message_length = k;
                break;
            }
            k++;
        }
    }

    return message_length;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return -1;
    }

    image_t *image = image_new(0, 0);
    if (!image) {
        printf("Error: Could not allocate memory for the image.\n");
        return -1;
    }

    if (image_load(image, argv[1]) != 0) {
        printf("Error: Could not load the input image.\n");
        image_free(image);
        return -1;
    }

    image_encode(image, argv[3]);

    if (image_save(image, argv[2]) != 0) {
        printf("Error: Could not save the output image.\n");
        image_free(image);
        return -1;
    }

    printf("Message encoded successfully!\n");

    image_free(image);

    return 0;
}