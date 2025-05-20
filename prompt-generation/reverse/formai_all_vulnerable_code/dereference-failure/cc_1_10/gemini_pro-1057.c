//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
        memset(image->pixels[i], ' ', width);
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

void draw_line(Image *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        image->pixels[y0][x0] = '*';
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius) {
    int x = 0, y = radius;
    int err = -radius;
    while (x <= y) {
        image->pixels[y0 + y][x0 + x] = '*';
        image->pixels[y0 + x][x0 + y] = '*';
        image->pixels[y0 - x][x0 + y] = '*';
        image->pixels[y0 - y][x0 + x] = '*';
        image->pixels[y0 + y][x0 - x] = '*';
        image->pixels[y0 + x][x0 - y] = '*';
        image->pixels[y0 - x][x0 - y] = '*';
        image->pixels[y0 - y][x0 - x] = '*';
        err += 2*x + 1;
        x++;
        if (err >= 0) {
            y--;
            err -= 2*y + 1;
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int x1, int y1) {
    for (int i = x0; i <= x1; i++) {
        image->pixels[y0][i] = '*';
        image->pixels[y1][i] = '*';
    }
    for (int j = y0; j <= y1; j++) {
        image->pixels[j][x0] = '*';
        image->pixels[j][x1] = '*';
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2) {
    draw_line(image, x0, y0, x1, y1);
    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x2, y2, x0, y0);
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            putchar(image->pixels[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    Image *image = new_image(50, 50);

    draw_line(image, 10, 10, 40, 40);
    draw_circle(image, 25, 25, 10);
    draw_rectangle(image, 10, 20, 40, 30);
    draw_triangle(image, 10, 40, 25, 10, 40, 40);

    print_image(image);

    free_image(image);
    return 0;
}