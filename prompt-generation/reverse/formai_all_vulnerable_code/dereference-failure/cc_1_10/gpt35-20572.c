//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
    int w, h;
    unsigned char *data;
} Image;

void flip(Image *img) {
    unsigned char *temp = malloc(img->w * img->h * sizeof(unsigned char));
    memcpy(temp, img->data, img->w * img->h);
    for (int y = 0; y < img->h; y++) {
        for (int x = 0; x < img->w; x++) {
            int idx = y * img->w + x;
            int idx_flipped = y * img->w + (img->w - 1 - x);
            img->data[idx] = temp[idx_flipped];
        }
    }
    free(temp);
}

void adjust_brightness(Image *img, int delta) {
    for (int i = 0; i < img->w * img->h; i++) {
        int val = img->data[i] + delta;
        if (val > 255) val = 255;
        if (val < 0) val = 0;
        img->data[i] = val;
    }
}

void adjust_contrast(Image *img, float alpha) {
    float avg = 0;
    for (int i = 0; i < img->w * img->h; i++) {
        avg += img->data[i];
    }
    avg /= img->w * img->h;
    for (int i = 0; i < img->w * img->h; i++) {
        int val = alpha * (img->data[i] - avg) + avg;
        if (val > 255) val = 255;
        if (val < 0) val = 0;
        img->data[i] = val;
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <flip|brightness|contrast> <value>\n", argv[0]);
        return 1;
    }
    Image img;
    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        return 1;
    }
    char magic[3];
    if (fscanf(f, "%2s", magic) != 1 || strncmp("P5", magic, 2) != 0) {
        fprintf(stderr, "Unsupported image format\n");
        return 1;
    }
    int w, h, maxval;
    if (fscanf(f, "%d %d %d\n", &w, &h, &maxval) != 3 || maxval != 255) {
        fprintf(stderr, "Invalid image header\n");
        return 1;
    }
    img.w = w;
    img.h = h;
    img.data = malloc(w * h * sizeof(unsigned char));
    if (fread(img.data, sizeof(unsigned char), w * h, f) != w * h) {
        fprintf(stderr, "Failed to read image data\n");
        return 1;
    }
    fclose(f);
    if (strcmp(argv[2], "flip") == 0) {
        flip(&img);
    } else if (strcmp(argv[2], "brightness") == 0) {
        adjust_brightness(&img, atoi(argv[3]));
    } else if (strcmp(argv[2], "contrast") == 0) {
        adjust_contrast(&img, atof(argv[3]));
    } else {
        fprintf(stderr, "Unknown command %s\n", argv[2]);
        return 1;
    }
    char *out_filename = malloc(strlen(argv[1]) + 10);
    sprintf(out_filename, "%s_%s_%s.pgm", argv[1], argv[2], argv[3]);
    f = fopen(out_filename, "wb");
    if (!f) {
        fprintf(stderr, "Failed to open %s for writing\n", out_filename);
        free(out_filename);
        return 1;
    }
    fprintf(f, "P5\n%d %d\n255\n", img.w, img.h);
    fwrite(img.data, sizeof(unsigned char), img.w * img.h, f);
    fclose(f);
    free(out_filename);
    free(img.data);
    return 0;
}