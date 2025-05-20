//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *new_image(int width, int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);
    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void load_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void invert_image(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void grayscale_image(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void blur_image(image *img) {
    image *tmp = new_image(img->width, img->height);
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < img->width && j + l >= 0 && j + l < img->height) {
                        sum_r += img->data[(i + k) * img->width + (j + l)].r;
                        sum_g += img->data[(i + k) * img->width + (j + l)].g;
                        sum_b += img->data[(i + k) * img->width + (j + l)].b;
                        count++;
                    }
                }
            }
            tmp->data[i * img->width + j].r = sum_r / count;
            tmp->data[i * img->width + j].g = sum_g / count;
            tmp->data[i * img->width + j].b = sum_b / count;
        }
    }
    free_image(img);
    img = tmp;
}

void sharpen_image(image *img) {
    image *tmp = new_image(img->width, img->height);
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < img->width && j + l >= 0 && j + l < img->height) {
                        sum_r += img->data[(i + k) * img->width + (j + l)].r;
                        sum_g += img->data[(i + k) * img->width + (j + l)].g;
                        sum_b += img->data[(i + k) * img->width + (j + l)].b;
                    }
                }
            }
            tmp->data[i * img->width + j].r = sum_r / 9;
            tmp->data[i * img->width + j].g = sum_g / 9;
            tmp->data[i * img->width + j].b = sum_b / 9;
        }
    }
    free_image(img);
    img = tmp;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }
    image *img = new_image(0, 0);
    load_image(img, argv[1]);
    // Apply image processing operations here
    invert_image(img);
    grayscale_image(img);
    blur_image(img);
    sharpen_image(img);
    save_image(img, argv[2]);
    free_image(img);
    return 0;
}