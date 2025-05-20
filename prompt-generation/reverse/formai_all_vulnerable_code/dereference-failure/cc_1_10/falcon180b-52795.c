//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    int width;
    int height;
    int *data;
} Image;

typedef struct {
    int x, y;
    int width, height;
    Image *src;
    Image *dst;
} Rect;

void init_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(int));
    memset(img->data, 0, width * height * sizeof(int));
}

void free_image(Image *img) {
    free(img->data);
}

void draw_rect(Image *dst, int x, int y, int width, int height, int color) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            dst->data[j * dst->width + i] = color;
        }
    }
}

void fill_rect(Image *dst, int x, int y, int width, int height, int color) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            if (dst->data[j * dst->width + i] == 0) {
                dst->data[j * dst->width + i] = color;
            }
        }
    }
}

void copy_rect(Image *src, Image *dst, int sx, int sy, int dx, int dy, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            dst->data[(dy + j) * dst->width + dx + i] = src->data[(dy + j) * src->width + sx + i];
        }
    }
}

int main() {
    Image img1, img2;
    init_image(&img1, 500, 500);
    init_image(&img2, 500, 500);

    int i, j;
    for (i = 0; i < img1.width; i++) {
        for (j = 0; j < img1.height; j++) {
            img1.data[j * img1.width + i] = rand() % MAX_COLORS;
        }
    }

    for (i = 0; i < img2.width; i++) {
        for (j = 0; j < img2.height; j++) {
            img2.data[j * img2.width + i] = 0;
        }
    }

    Rect rect = {0, 0, 100, 100};
    draw_rect(&img2, rect.x, rect.y, rect.width, rect.height, 255);

    copy_rect(&img1, &img2, 0, 0, rect.x, rect.y, rect.width, rect.height);

    free_image(&img1);
    free_image(&img2);

    return 0;
}