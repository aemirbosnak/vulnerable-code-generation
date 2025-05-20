//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define MAX_GREY 255

typedef struct {
    int width;
    int height;
    uint8_t *data;
} Image;

Image *new_image(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = calloc(width * height, sizeof(uint8_t));
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void write_pgm(char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, MAX_GREY);
    fwrite(img->data, 1, img->width * img->height, fp);
    fclose(fp);
}

Image *read_pgm(char *filename) {
    char buf[256];
    FILE *fp = fopen(filename, "rb");
    fgets(buf, sizeof(buf), fp);
    if (strncmp(buf, "P5", 2) != 0) {
        fprintf(stderr, "Invalid PGM file format!\n");
        fclose(fp);
        return NULL;
    }
    int width, height, max_grey;
    fscanf(fp, "%d %d\n%d\n", &width, &height, &max_grey);
    if (max_grey != MAX_GREY) {
        fprintf(stderr, "Unsupported max grey value (%d)\n", max_grey);
        fclose(fp);
        return NULL;
    }
    Image *img = new_image(width, height);
    fread(img->data, 1, width * height, fp);
    fclose(fp);
    return img;
}

Image *flip_horizontal(Image *img) {
    Image *new_img = new_image(img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            new_img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
        }
    }
    return new_img;
}

Image *flip_vertical(Image *img) {
    Image *new_img = new_image(img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            new_img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
        }
    }
    return new_img;
}

Image *adjust_brightness(Image *img, int brightness) {
    Image *new_img = new_image(img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int val = img->data[y * img->width + x] + brightness;
            new_img->data[y * img->width + x] = (uint8_t)fmax(0, fmin(MAX_GREY, val));
        }
    }
    return new_img;
}

Image *adjust_contrast(Image *img, float contrast) {
    Image *new_img = new_image(img->width, img->height);
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    float offset = 128.0f * (1.0f - factor / 255.0f);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int val = (int)(factor * (img->data[y * img->width + x] - offset));
            new_img->data[y * img->width + x] = (uint8_t)fmax(0, fmin(MAX_GREY, val));
        }
    }
    return new_img;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_pgm> <output_pgm>\n", argv[0]);
        return 1;
    }
    Image *img = read_pgm(argv[1]);
    if (!img) {
        return 1;
    }
    Image *flipped_h = flip_horizontal(img);
    write_pgm("flipped_h.pgm", flipped_h);
    free_image(flipped_h);
    Image *flipped_v = flip_vertical(img);
    write_pgm("flipped_v.pgm", flipped_v);
    free_image(flipped_v);
    Image *brightened = adjust_brightness(img, 50);
    write_pgm("brightened.pgm", brightened);
    free_image(brightened);
    Image *contrasted = adjust_contrast(img, 50.0f);
    write_pgm("contrasted.pgm", contrasted);
    free_image(contrasted);
    free_image(img);
    return 0;
}