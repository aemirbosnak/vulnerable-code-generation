//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b, a;
} pixel;

typedef struct {
    uint32_t width, height;
    pixel *data;
} image;

image *image_new(uint32_t width, uint32_t height) {
    image *img = malloc(sizeof(image));
    if (!img) return NULL;

    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    if (!img->data) {
        free(img);
        return NULL;
    }

    return img;
}

void image_free(image *img) {
    if (!img) return;

    free(img->data);
    free(img);
}

int image_load(image *img, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return -1;

    fread(&img->width, sizeof(uint32_t), 1, f);
    fread(&img->height, sizeof(uint32_t), 1, f);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fclose(f);
        return -1;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, f);

    fclose(f);

    return 0;
}

int image_save(image *img, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return -1;

    fwrite(&img->width, sizeof(uint32_t), 1, f);
    fwrite(&img->height, sizeof(uint32_t), 1, f);

    fwrite(img->data, sizeof(pixel), img->width * img->height, f);

    fclose(f);

    return 0;
}

void image_flip_horizontal(image *img) {
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width / 2; x++) {
            pixel tmp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + img->width - x - 1];
            img->data[y * img->width + img->width - x - 1] = tmp;
        }
    }
}

void image_flip_vertical(image *img) {
    for (uint32_t y = 0; y < img->height / 2; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            pixel tmp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = tmp;
        }
    }
}

void image_rotate_left(image *img) {
    image *tmp = image_new(img->height, img->width);
    if (!tmp) return;

    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            tmp->data[x * img->height + y] = img->data[y * img->width + x];
        }
    }

    image_free(img);
    *img = *tmp;
    free(tmp);
}

void image_rotate_right(image *img) {
    image *tmp = image_new(img->height, img->width);
    if (!tmp) return;

    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            tmp->data[(img->width - x - 1) * img->height + y] = img->data[y * img->width + x];
        }
    }

    image_free(img);
    *img = *tmp;
    free(tmp);
}

void image_grayscale(image *img) {
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            uint8_t avg = (img->data[y * img->width + x].r + img->data[y * img->width + x].g + img->data[y * img->width + x].b) / 3;
            img->data[y * img->width + x].r = avg;
            img->data[y * img->width + x].g = avg;
            img->data[y * img->width + x].b = avg;
        }
    }
}

void image_invert_colors(image *img) {
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width; x++) {
            img->data[y * img->width + x].r = 255 - img->data[y * img->width + x].r;
            img->data[y * img->width + x].g = 255 - img->data[y * img->width + x].g;
            img->data[y * img->width + x].b = 255 - img->data[y * img->width + x].b;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image *img = image_new(0, 0);
    if (!img) {
        fprintf(stderr, "Failed to create image\n");
        return 1;
    }

    if (image_load(img, argv[1]) < 0) {
        fprintf(stderr, "Failed to load image: %s\n", argv[1]);
        image_free(img);
        return 1;
    }

    image_flip_horizontal(img);
    image_grayscale(img);
    image_invert_colors(img);

    if (image_save(img, argv[2]) < 0) {
        fprintf(stderr, "Failed to save image: %s\n", argv[2]);
        image_free(img);
        return 1;
    }

    image_free(img);

    return 0;
}