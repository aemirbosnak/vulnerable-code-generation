//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define CHANNELS 3

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height, channels;
    pixel *data;
} image;

image *create_image(int width, int height, int channels) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = malloc(width * height * channels);
    return img;
}

void destroy_image(image *img) {
    free(img->data);
    free(img);
}

void load_image(image *img, char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    fread(&img->width, sizeof(int), 1, f);
    fread(&img->height, sizeof(int), 1, f);
    fread(&img->channels, sizeof(int), 1, f);

    int data_size = img->width * img->height * img->channels;
    img->data = malloc(data_size);
    fread(img->data, 1, data_size, f);

    fclose(f);
}

void save_image(image *img, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    fwrite(&img->width, sizeof(int), 1, f);
    fwrite(&img->height, sizeof(int), 1, f);
    fwrite(&img->channels, sizeof(int), 1, f);

    int data_size = img->width * img->height * img->channels;
    fwrite(img->data, 1, data_size, f);

    fclose(f);
}

void print_image(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel *p = &img->data[y * img->width + x];
            printf("(%d, %d, %d) ", p->r, p->g, p->b);
        }
        printf("\n");
    }
}

int main() {
    image *img = create_image(WIDTH, HEIGHT, CHANNELS);

    load_image(img, "image.bmp");

    print_image(img);

    destroy_image(img);

    return 0;
}