//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int index = (y * image->width + x) * 3;
    image->data[index] = r;
    image->data[index + 1] = g;
    image->data[index + 2] = b;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        set_pixel(image, x1, y1, r, g, b);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius, unsigned char r, unsigned char g, unsigned char b) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        set_pixel(image, x0 + x, y0 + y, r, g, b);
        set_pixel(image, x0 + x, y0 - y, r, g, b);
        set_pixel(image, x0 - x, y0 + y, r, g, b);
        set_pixel(image, x0 - x, y0 - y, r, g, b);
        set_pixel(image, x0 + y, y0 + x, r, g, b);
        set_pixel(image, x0 + y, y0 - x, r, g, b);
        set_pixel(image, x0 - y, y0 + x, r, g, b);
        set_pixel(image, x0 - y, y0 - x, r, g, b);

        if (d > 0) {
            d += 4 * (x - y) + 10;
            y--;
        } else {
            d += 4 * x + 6;
        }
        x++;
    }
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    for (int x = x1; x <= x2; x++) {
        set_pixel(image, x, y1, r, g, b);
        set_pixel(image, x, y2, r, g, b);
    }

    for (int y = y1; y <= y2; y++) {
        set_pixel(image, x1, y, r, g, b);
        set_pixel(image, x2, y, r, g, b);
    }
}

void draw_triangle(Image *image, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char r, unsigned char g, unsigned char b) {
    draw_line(image, x1, y1, x2, y2, r, g, b);
    draw_line(image, x2, y2, x3, y3, r, g, b);
    draw_line(image, x3, y3, x1, y1, r, g, b);
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);
}

int main() {
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);

    draw_rectangle(image, 100, 100, 200, 200, 255, 0, 0);
    draw_line(image, 100, 100, 200, 200, 0, 255, 0);
    draw_circle(image, 150, 150, 50, 0, 0, 255);
    draw_triangle(image, 100, 200, 150, 250, 200, 200, 255, 255, 0);

    save_image(image, "pixel_art.ppm");
    free_image(image);

    return 0;
}