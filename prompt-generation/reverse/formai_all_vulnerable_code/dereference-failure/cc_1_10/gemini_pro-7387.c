//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

int write_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return -1;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return 0;
}

void watermark_image(image *img, char *watermark) {
    int i, j, k;
    int watermark_len = strlen(watermark);
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < watermark_len; k++) {
                int bit = (watermark[k] >> (7 - k)) & 1;
                img->data[i * img->width + j].r += bit;
            }
        }
    }
}

void dewatermark_image(image *img, char *watermark) {
    int i, j, k;
    int watermark_len = strlen(watermark);
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < watermark_len; k++) {
                int bit = (img->data[i * img->width + j].r & (1 << (7 - k))) >> (7 - k);
                watermark[k] |= bit << (7 - k);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <watermark>\n", argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    watermark_image(img, argv[3]);

    int ret = write_image(img, argv[2]);
    if (ret != 0) {
        fprintf(stderr, "Error: could not write image to file %s\n", argv[2]);
        return 1;
    }

    return 0;
}