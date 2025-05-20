//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

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

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, fp);

    fclose(fp);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->data, image->width * image->height, 1, fp);

    fclose(fp);
}

void watermark_image(Image *image, const char *message) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> j) & 1;
            int x = i * 8 + j;
            int y = image->height - 1;
            image->data[y * image->width + x] = (image->data[y * image->width + x] & ~1) | bit;
        }
    }
}

void extract_watermark(const Image *image, char *message) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            int x = i * 8 + j;
            int y = image->height - 1;
            byte |= (image->data[y * image->width + x] & 1) << j;
        }
        message[i] = byte;
    }
    message[message_length] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    watermark_image(image, argv[3]);

    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}