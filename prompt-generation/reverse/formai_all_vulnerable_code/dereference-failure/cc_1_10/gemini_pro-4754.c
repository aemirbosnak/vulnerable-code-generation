//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

void load_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        perror("malloc");
        exit(1);
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void save_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void blend_images(image *dst, image *src, float alpha) {
    for (int y = 0; y < dst->height; y++) {
        for (int x = 0; x < dst->width; x++) {
            pixel *d = &dst->data[y * dst->width + x];
            pixel *s = &src->data[y * src->width + x];

            d->r = (1 - alpha) * d->r + alpha * s->r;
            d->g = (1 - alpha) * d->g + alpha * s->g;
            d->b = (1 - alpha) * d->b + alpha * s->b;
        }
    }
}

void create_gradient(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel *p = &img->data[y * img->width + x];

            p->r = 255 * (float)x / img->width;
            p->g = 255 * (float)y / img->height;
            p->b = 0;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image img1, img2, img3;

    load_image(&img1, argv[1]);
    load_image(&img2, argv[2]);

    img3.width = img1.width;
    img3.height = img1.height;
    img3.data = malloc(img3.width * img3.height * sizeof(pixel));
    if (!img3.data) {
        perror("malloc");
        exit(1);
    }

    blend_images(&img3, &img1, 0.5);
    create_gradient(&img2);
    blend_images(&img3, &img2, 0.5);

    save_image(&img3, "output.png");

    return 0;
}