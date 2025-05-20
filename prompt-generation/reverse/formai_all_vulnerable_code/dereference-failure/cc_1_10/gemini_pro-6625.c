//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t pixel_t;

struct image {
    int width;
    int height;
    pixel_t *data;
};

struct image *new_image(int width, int height) {
    struct image *img = malloc(sizeof(struct image));
    if (!img) {
        perror("malloc");
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel_t));
    if (!img->data) {
        perror("malloc");
        free(img);
        return NULL;
    }

    return img;
}

void free_image(struct image *img) {
    free(img->data);
    free(img);
}

int read_image(struct image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    fread(img->data, sizeof(pixel_t), img->width * img->height, fp);

    fclose(fp);

    return 0;
}

int write_image(struct image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel_t), img->width * img->height, fp);

    fclose(fp);

    return 0;
}

void flip_image(struct image *img) {
    for (int i = 0; i < img->width / 2; i++) {
        for (int j = 0; j < img->height; j++) {
            pixel_t temp = img->data[i + j * img->width];
            img->data[i + j * img->width] = img->data[img->width - i - 1 + j * img->width];
            img->data[img->width - i - 1 + j * img->width] = temp;
        }
    }
}

void adjust_brightness_contrast(struct image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        int new_value = (int)(img->data[i] * contrast + brightness);
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        img->data[i] = (pixel_t)new_value;
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <brightness> <contrast>\n", argv[0]);
        return -1;
    }

    struct image *img = new_image(0, 0);
    if (!img) {
        return -1;
    }

    if (read_image(img, argv[1]) != 0) {
        free_image(img);
        return -1;
    }

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    adjust_brightness_contrast(img, brightness, contrast);

    flip_image(img);

    if (write_image(img, argv[2]) != 0) {
        free_image(img);
        return -1;
    }

    free_image(img);

    return 0;
}