//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read the header
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fread(&image->channels, sizeof(int), 1, file);

    // Check if the image is too large
    if (image->width * image->height * image->channels > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: Image is too large\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the image data
    fread(image->data, sizeof(unsigned char), image->width * image->height * image->channels, file);

    fclose(file);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->channels, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * image->channels, file);

    fclose(file);
}

void embed_watermark(Image *image, const char *watermark) {
    int watermark_length = strlen(watermark);

    // Check if the watermark is too long
    if (watermark_length > MAX_IMAGE_SIZE / 8) {
        fprintf(stderr, "Error: Watermark is too long\n");
        return;
    }

    // Embed the watermark in the least significant bits of the image data
    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (watermark[i] >> j) & 1;
            image->data[i * 8 + j] = (image->data[i * 8 + j] & 0xfe) | bit;
        }
    }
}

char *extract_watermark(Image *image) {
    int watermark_length = 0;

    // Read the length of the watermark from the first 8 bytes of the image data
    for (int i = 0; i < 8; i++) {
        watermark_length |= (image->data[i] & 1) << i;
    }

    // Check if the watermark length is valid
    if (watermark_length > MAX_IMAGE_SIZE / 8) {
        fprintf(stderr, "Error: Watermark length is invalid\n");
        return NULL;
    }

    // Extract the watermark from the least significant bits of the image data
    char *watermark = malloc(watermark_length + 1);
    if (!watermark) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        return NULL;
    }

    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            watermark[i] |= (image->data[i * 8 + j] & 1) << j;
        }
    }

    watermark[watermark_length] = '\0';

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    embed_watermark(image, argv[2]);

    write_image(argv[3], image);

    free(image->data);
    free(image);

    return 0;
}