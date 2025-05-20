//MISTRAL-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} pixel;

void read_pgm(const char *filename, pixel **image) {
    FILE *fp;
    char magic_number[3];
    int width, height, max_value;
    int i;

    fp = fopen(filename, "rb");
    fgets(magic_number, 3, fp);
    magic_number[2] = '\0';
    if (strcmp(magic_number, "P5") != 0) {
        fprintf(stderr, "Invalid PGm file\n");
        exit(1);
    }
    fscanf(fp, "%d %d %d\n", &width, &height, &max_value);
    *image = (pixel *)calloc(WIDTH * HEIGHT, sizeof(pixel));
    for (i = 0; i < WIDTH * HEIGHT; ++i) {
        fscanf(fp, "%hhu %hhu %hhu\n", &((*image)[i].r), &((*image)[i].g), &((*image)[i].b));
    }
    fclose(fp);
}

void write_pgm(const char *filename, const pixel *image) {
    FILE *fp;
    fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d %d\n255\n", WIDTH, HEIGHT, 255);
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        fprintf(fp, "%hhu %hhu %hhu\n", image[i].r, image[i].g, image[i].b);
    }
    fclose(fp);
}

void flip_image(pixel *image) {
    for (int i = 0; i < WIDTH * HEIGHT / 2; ++i) {
        pixel temp = image[i];
        image[i] = image[WIDTH * HEIGHT - i - 1];
        image[WIDTH * HEIGHT - i - 1] = temp;
    }
}

void change_brightness_contrast(pixel *image, int brightness, int contrast) {
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        int new_r = ((image[i].r + brightness > 255) ? 255 : image[i].r + brightness);
        int new_g = ((image[i].g + brightness > 255) ? 255 : image[i].g + brightness);
        int new_b = ((image[i].b + brightness > 255) ? 255 : image[i].b + brightness);

        int new_r_adjusted = round(labs(0.299 * new_r + 0.587 * new_g + 0.114 * new_b) * contrast + 0.5);
        int new_g_adjusted = round(labs(0.299 * new_r + 0.587 * new_g + 0.114 * new_b) * contrast + 0.5);
        int new_b_adjusted = round(labs(0.299 * new_r + 0.587 * new_g + 0.114 * new_b) * contrast + 0.5);

        image[i].r = new_r_adjusted > 255 ? 255 : new_r_adjusted;
        image[i].g = new_g_adjusted > 255 ? 255 : new_g_adjusted;
        image[i].b = new_b_adjusted > 255 ? 255 : new_b_adjusted;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.pgm output_brightness output_contrast\n", argv[0]);
        return 1;
    }

    pixel *image;
    read_pgm(argv[1], &image);

    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);

    change_brightness_contrast(image, brightness, contrast);
    flip_image(image);

    write_pgm("output.pgm", image);

    free(image);
    return 0;
}