//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_DEPTH 8

typedef struct {
    int width;
    int height;
    int depth;
    char *data;
} Image;

Image *create_image(int width, int height, int depth) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->depth = depth;
    img->data = (char *)malloc(width * height * depth);
    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void set_pixel(Image *img, int x, int y, int value) {
    int offset = (y * img->width + x) * img->depth;
    memcpy(img->data + offset, &value, img->depth);
}

int get_pixel(Image *img, int x, int y) {
    int offset = (y * img->width + x) * img->depth;
    return *(int *)(img->data + offset);
}

void fill_rectangle(Image *img, int x, int y, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            set_pixel(img, x + j, y + i, value);
        }
    }
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
    fwrite(img->data, img->width * img->height * img->depth, 1, fp);
    fclose(fp);
}

int main() {
    Image *img = create_image(MAX_WIDTH, MAX_HEIGHT, MAX_DEPTH);
    fill_rectangle(img, 0, 0, MAX_WIDTH, MAX_HEIGHT, 0xffffff);
    save_image(img, "image.bin");
    destroy_image(img);
    return 0;
}