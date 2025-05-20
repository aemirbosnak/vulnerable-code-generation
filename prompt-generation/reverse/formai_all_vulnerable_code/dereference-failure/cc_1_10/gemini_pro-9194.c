//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (img == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (img->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void write_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    int message_length = strlen(argv[3]);
    if (message_length > img->width * img->height * 3) {
        fprintf(stderr, "Error: message too long\n");
        free(img);
        return 1;
    }

    int index = 0;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            pixel *p = &img->data[i * img->width + j];
            if (index < message_length) {
                p->red &= 0xFE;
                p->red |= (argv[3][index] >> 7) & 0x01;
                p->green &= 0xFE;
                p->green |= (argv[3][index] >> 6) & 0x01;
                p->blue &= 0xFE;
                p->blue |= (argv[3][index] >> 5) & 0x01;
                index++;
            }
        }
    }

    write_image(argv[2], img);
    free(img);

    return 0;
}