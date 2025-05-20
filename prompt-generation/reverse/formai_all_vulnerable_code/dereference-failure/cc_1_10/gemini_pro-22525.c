//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char r, char g, char b) {
    int index = (y * image->width + x) * 3;
    image->data[index] = r;
    image->data[index + 1] = g;
    image->data[index + 2] = b;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, char r, char g, char b) {
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

void draw_circle(Image *image, int x, int y, int radius, char r, char g, char b) {
    int x0 = x, y0 = y;
    int x1 = x + radius, y1 = y;
    int dx = 3, dy = -2 * radius + 5;

    while (x1 >= x0) {
        draw_line(image, x0, y0, x1, y1, r, g, b);
        draw_line(image, x1, y1, x0, y0, r, g, b);
        x0++;
        x1--;
        dy += 4 * x0 + 2;
        if (dx < 0) dx += 4 * x0 + 6;
        else {
            dx += 4 * x0 + 10;
            y0++;
            y1--;
        }
    }
}

void draw_triangle(Image *image, int x1, int y1, int x2, int y2, int x3, int y3, char r, char g, char b) {
    draw_line(image, x1, y1, x2, y2, r, g, b);
    draw_line(image, x2, y2, x3, y3, r, g, b);
    draw_line(image, x3, y3, x1, y1, r, g, b);
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, char r, char g, char b) {
    draw_line(image, x1, y1, x2, y1, r, g, b);
    draw_line(image, x2, y1, x2, y2, r, g, b);
    draw_line(image, x2, y2, x1, y2, r, g, b);
    draw_line(image, x1, y2, x1, y1, r, g, b);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);
}

int main() {
    Image *image = create_image(512, 512);
    draw_circle(image, 256, 256, 100, 255, 255, 255);
    draw_triangle(image, 100, 100, 300, 100, 200, 300, 0, 255, 0);
    draw_rectangle(image, 300, 400, 400, 500, 0, 0, 255);
    save_image(image, "pixel_art.ppm");
    destroy_image(image);
    return 0;
}