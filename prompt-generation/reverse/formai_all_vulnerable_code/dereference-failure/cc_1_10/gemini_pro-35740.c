//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct {
    int width, height;
    byte *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, byte color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = color;
}

byte get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->data[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, byte color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    for (;;) {
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius, byte color) {
    int x = radius, y = 0, err = 0;
    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, color);
        set_pixel(image, x0 + y, y0 + x, color);
        set_pixel(image, x0 - y, y0 + x, color);
        set_pixel(image, x0 - x, y0 + y, color);
        set_pixel(image, x0 - x, y0 - y, color);
        set_pixel(image, x0 - y, y0 - x, color);
        set_pixel(image, x0 + y, y0 - x, color);
        set_pixel(image, x0 + x, y0 - y, color);
        if (err <= 0) {
            y++;
            err += 2*y + 1;
        }
        if (err > 0) {
            x--;
            err -= 2*x + 1;
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int width, int height, byte color) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x0 + i, y0, color);
        set_pixel(image, x0 + i, y0 + height - 1, color);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x0, y0 + i, color);
        set_pixel(image, x0 + width - 1, y0 + i, color);
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, byte color) {
    draw_line(image, x0, y0, x1, y1, color);
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x0, y0, color);
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

int main() {
    Image *image = create_image(512, 512);
    draw_circle(image, 256, 256, 100, 255);
    draw_rectangle(image, 100, 100, 200, 200, 0);
    draw_line(image, 100, 200, 300, 400, 128);
    draw_triangle(image, 100, 400, 200, 400, 150, 500, 255);
    save_image(image, "image.pgm");
    destroy_image(image);
    return 0;
}