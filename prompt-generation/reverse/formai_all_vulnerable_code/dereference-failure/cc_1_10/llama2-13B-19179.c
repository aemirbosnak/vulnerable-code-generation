//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    char *data;
    size_t len;
} image_t;

image_t *load_image(const char *filename) {
    image_t *img = malloc(sizeof(image_t));
    img->data = malloc(WIDTH * HEIGHT * 3);
    img->len = WIDTH * HEIGHT * 3;

    FILE *file = fopen(filename, "rb");
    fread(img->data, 1, img->len, file);
    fclose(file);

    return img;
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steep = (dy > dx) ? 1 : 0;

    if (dx > 0) {
        for (int i = 0; i < dx; i++) {
            if (steep) {
                img->data[((y1 + i) * WIDTH * 3) + (x1 * 3)] = 255;
            } else {
                img->data[((x1 + i) * WIDTH * 3) + (y1 * 3)] = 255;
            }
        }
    } else {
        for (int i = 0; i < dx; i++) {
            if (steep) {
                img->data[((x1 + i) * WIDTH * 3) + (y1 * 3)] = 255;
            } else {
                img->data[((y1 + i) * WIDTH * 3) + (x1 * 3)] = 255;
            }
        }
    }
}

void draw_rectangle(image_t *img, int x, int y, int w, int h) {
    draw_line(img, x, y, x + w, y + h);
    draw_line(img, x, y + h, x + w, y);
    draw_line(img, x + w, y, x, y + h);
    draw_line(img, x + w, y + h, x, y);
}

void draw_circle(image_t *img, int x, int y, int radius) {
    int fx = x - radius;
    int fy = y - radius;
    int sx = x + radius;
    int sy = y + radius;
    int dx = fx - sx;
    int dy = fy - sy;
    int dr = dx * dx + dy * dy;

    if (dr > 100) {
        draw_line(img, fx, fy, sx, sy);
    }
}

void draw_text(image_t *img, int x, int y, const char *text) {
    for (int i = 0; text[i] != 0; i++) {
        int c = text[i];
        if (c >= 32 && c <= 126) {
            draw_line(img, x, y + i * 10, x + 1, y + i * 10);
        }
    }
}

void main() {
    image_t *img = load_image("example.jpg");

    draw_rectangle(img, 100, 100, 300, 300);
    draw_circle(img, 200, 200, 100);
    draw_text(img, 300, 300, "Hello, World!");

    munmap(img->data, img->len);
    free(img);
}