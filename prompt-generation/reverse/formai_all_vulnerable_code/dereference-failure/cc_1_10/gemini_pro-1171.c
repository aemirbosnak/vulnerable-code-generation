//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            image->pixels[i][j] = ' ';
        }
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->pixels[y][x] = c;
    }
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (true) {
        set_pixel(image, x0, y0, c);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius, char c) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    while (y >= x) {
        set_pixel(image, x0 + x, y0 + y, c);
        set_pixel(image, x0 + x, y0 - y, c);
        set_pixel(image, x0 - x, y0 + y, c);
        set_pixel(image, x0 - x, y0 - y, c);
        set_pixel(image, x0 + y, y0 + x, c);
        set_pixel(image, x0 + y, y0 - x, c);
        set_pixel(image, x0 - y, y0 + x, c);
        set_pixel(image, x0 - y, y0 - x, c);
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void draw_rectangle(Image *image, int x0, int y0, int width, int height, char c) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x0 + i, y0, c);
        set_pixel(image, x0 + i, y0 + height - 1, c);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x0, y0 + i, c);
        set_pixel(image, x0 + width - 1, y0 + i, c);
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, char c) {
    draw_line(image, x0, y0, x1, y1, c);
    draw_line(image, x1, y1, x2, y2, c);
    draw_line(image, x2, y2, x0, y0, c);
}

void draw_star(Image *image, int x0, int y0, int radius, char c) {
    draw_line(image, x0, y0 - radius, x0, y0 + radius, c);
    draw_line(image, x0 - radius, y0, x0 + radius, y0, c);
    draw_line(image, x0 - radius * cos(M_PI / 4), y0 - radius * sin(M_PI / 4), x0 + radius * cos(M_PI / 4), y0 + radius * sin(M_PI / 4), c);
    draw_line(image, x0 - radius * cos(M_PI / 4), y0 + radius * sin(M_PI / 4), x0 + radius * cos(M_PI / 4), y0 - radius * sin(M_PI / 4), c);
}

void draw_heart(Image *image, int x0, int y0, int radius, char c) {
    draw_circle(image, x0, y0, radius, c);
    draw_circle(image, x0, y0 + radius * 2, radius, c);
    draw_line(image, x0 - radius, y0 + radius, x0 + radius, y0 + radius, c);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P2\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image *image = create_image(500, 500);

    draw_rectangle(image, 50, 50, 400, 400, '#');
    draw_line(image, 50, 50, 450, 450, '#');
    draw_line(image, 450, 50, 50, 450, '#');
    draw_circle(image, 250, 250, 100, '#');
    draw_star(image, 250, 250, 50, '#');
    draw_heart(image, 250, 250, 50, '#');
    draw_triangle(image, 250, 250, 350, 350, 150, 350, '#');

    save_image(image, "pixel_art.pgm");
    free_image(image);
    return 0;
}