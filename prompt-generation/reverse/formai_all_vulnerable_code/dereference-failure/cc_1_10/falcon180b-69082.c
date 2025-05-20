//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void Image_init(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = malloc(width * height);
}

void Image_destroy(Image *img) {
    free(img->data);
}

void Image_set_pixel(Image *img, int x, int y, char color) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->data[y * img->width + x] = color;
    }
}

void Image_draw_rect(Image *img, int x, int y, int width, int height, char color) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            Image_set_pixel(img, x + i, y + j, color);
        }
    }
}

void Image_to_ascii(Image *img, FILE *fp) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            char color = img->data[y * img->width + x];
            fprintf(fp, "%c", color);
        }
        fprintf(fp, "\n");
    }
}

int main() {
    Image img;
    Image_init(&img, 10, 10);
    Image_draw_rect(&img, 0, 0, 5, 5, 'X');
    Image_draw_rect(&img, 5, 5, 5, 5, 'O');
    FILE *fp = fopen("image.txt", "w");
    Image_to_ascii(&img, fp);
    fclose(fp);
    Image_destroy(&img);
    return 0;
}