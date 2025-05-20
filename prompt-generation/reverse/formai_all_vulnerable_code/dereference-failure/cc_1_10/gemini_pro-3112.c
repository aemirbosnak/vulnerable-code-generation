//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
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
    image->data = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2;
    while (1) {
        image->data[y0 * image->width + x0] = c;
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int r, char c) {
    int f = 1 - r;
    int ddF_x = 1;
    int ddF_y = -2 * r;
    int x1 = 0;
    int y1 = r;
    image->data[y * image->width + x] = c;
    while(x1 < y1) {
        if (f >= 0) {
            y1--;
            ddF_y += 2;
            f += ddF_y;
        }
        x1++;
        ddF_x += 2;
        f += ddF_x;
        image->data[(y + y1) * image->width + (x + x1)] = c;
        image->data[(y - y1) * image->width + (x + x1)] = c;
        image->data[(y + y1) * image->width + (x - x1)] = c;
        image->data[(y - y1) * image->width + (x - x1)] = c;
        image->data[(y + x1) * image->width + (x + y1)] = c;
        image->data[(y - x1) * image->width + (x + y1)] = c;
        image->data[(y + x1) * image->width + (x - y1)] = c;
        image->data[(y - x1) * image->width + (x - y1)] = c;
    }
}

void draw_rectangle(Image *image, int x, int y, int w, int h, char c) {
    for (int i = x; i < x + w; i++) {
        image->data[y * image->width + i] = c;
        image->data[(y + h - 1) * image->width + i] = c;
    }
    for (int i = y; i < y + h; i++) {
        image->data[i * image->width + x] = c;
        image->data[i * image->width + (x + w - 1)] = c;
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, char c) {
    draw_line(image, x0, y0, x1, y1, c);
    draw_line(image, x1, y1, x2, y2, c);
    draw_line(image, x2, y2, x0, y0, c);
}

void draw_star(Image *image, int x, int y, int r, char c) {
    draw_line(image, x, y - r, x, y + r, c);
    draw_line(image, x - r, y, x + r, y, c);
    draw_line(image, x - r * 0.707, y - r * 0.707, x + r * 0.707, y + r * 0.707, c);
    draw_line(image, x - r * 0.707, y + r * 0.707, x + r * 0.707, y - r * 0.707, c);
}

void draw_image(Image *image, FILE *file) {
    fprintf(file, "P1\n%d %d\n", image->width, image->height);
    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%c", image->data[i] == ' ' ? '0' : '1');
    }
}

int main() {
    Image *image = create_image(256, 256);

    draw_rectangle(image, 20, 20, 216, 216, ' ');
    draw_line(image, 20, 20, 236, 236, 'v');
    draw_line(image, 20, 236, 236, 20, 'v');
    draw_line(image, 20, 128, 236, 128, 'h');
    draw_line(image, 128, 20, 128, 236, 'h');
    draw_circle(image, 128, 128, 64, 'o');
    draw_circle(image, 128, 128, 32, 'o');
    draw_triangle(image, 128, 64, 96, 128, 160, 128, 'c');
    draw_triangle(image, 128, 192, 96, 128, 160, 128, 'c');
    draw_star(image, 128, 128, 32, '*');

    draw_image(image, stdout);

    destroy_image(image);

    return 0;
}