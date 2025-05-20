//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int maxval;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P5\n%d %d\n%d\n", &image->width, &image->height, &image->maxval);

    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, 1, image->width * image->height, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fprintf(fp, "P5\n%d %d\n%d\n", image->width, image->height, image->maxval);
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const unsigned char *watermark, int watermark_size) {
    if (watermark_size > image->width * image->height) {
        fprintf(stderr, "Watermark size is too large\n");
        return;
    }

    for (int i = 0; i < watermark_size; i++) {
        image->data[i] = (image->data[i] & 0x0f) | ((watermark[i] & 0xf0) << 4);
    }
}

void extract_watermark(const Image *image, unsigned char *watermark, int watermark_size) {
    for (int i = 0; i < watermark_size; i++) {
        watermark[i] = (image->data[i] >> 4) & 0xf0;
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image file> <watermark file> <output file>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[2]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int watermark_size = ftell(fp);
    rewind(fp);

    unsigned char *watermark = malloc(watermark_size);
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        return 1;
    }

    fread(watermark, 1, watermark_size, fp);
    fclose(fp);

    embed_watermark(image, watermark, watermark_size);
    write_image(image, argv[3]);

    free(image->data);
    free(image);
    free(watermark);

    return 0;
}