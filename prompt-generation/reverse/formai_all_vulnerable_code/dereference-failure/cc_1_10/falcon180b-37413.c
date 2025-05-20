//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    int x, y;
} Point;

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

void init_image(Image *img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    memset(img->data, 0, img->width * img->height * sizeof(Pixel));
}

void set_pixel(Image *img, int x, int y, Pixel color) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->data[y * img->width + x] = color;
    }
}

void draw_line(Image *img, int x1, int y1, int x2, int y2, Pixel color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2)? 1 : -1;
    int sy = (y1 < y2)? 1 : -1;
    int err = dx - dy;
    while (1) {
        set_pixel(img, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void save_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot save image to file '%s'.\n", filename);
        exit(1);
    }
    fwrite(img->data, img->width * img->height * sizeof(Pixel), 1, fp);
    fclose(fp);
}

int main() {
    Image img;
    init_image(&img);

    // Example image
    draw_line(&img, 0, 0, img.width - 1, img.height - 1, (Pixel){255, 0, 0});
    draw_line(&img, 0, img.height - 1, img.width - 1, 0, (Pixel){0, 255, 0});
    draw_line(&img, img.width - 1, 0, 0, img.height - 1, (Pixel){0, 0, 255});
    draw_line(&img, 0, 0, img.width / 2, img.height / 2, (Pixel){255, 255, 0});
    draw_line(&img, img.width / 2, 0, img.width / 2, img.height / 2, (Pixel){255, 0, 255});
    draw_line(&img, 0, img.height / 2, img.width / 2, img.height / 2, (Pixel){0, 255, 255});

    // Save image
    save_image("example.png", &img);

    return 0;
}