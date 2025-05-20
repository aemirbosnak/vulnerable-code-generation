//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);
}

void watermark_image(Image *image, char *watermark) {
    int watermark_length = strlen(watermark);
    int watermark_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (watermark_index < watermark_length) {
            image->data[i] = (image->data[i] & 0xF0) | (watermark[watermark_index] & 0x0F);
            watermark_index++;
        }
    }
}

char *extract_watermark(Image *image) {
    int watermark_length = 0;
    int watermark_index = 0;
    char *watermark = malloc(MAX_SIZE);

    for (int i = 0; i < image->width * image->height; i++) {
        if (watermark_index < MAX_SIZE) {
            watermark[watermark_index] = (image->data[i] & 0x0F) + '0';
            watermark_index++;
        }
    }

    watermark[watermark_index] = '\0';

    return watermark;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <watermark>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    watermark_image(image, argv[2]);

    save_image(image, "watermarked.bmp");

    free(image->data);
    free(image);

    image = load_image("watermarked.bmp");
    if (image == NULL) {
        return 1;
    }

    char *watermark = extract_watermark(image);

    printf("Extracted watermark: %s\n", watermark);

    free(image->data);
    free(image);
    free(watermark);

    return 0;
}