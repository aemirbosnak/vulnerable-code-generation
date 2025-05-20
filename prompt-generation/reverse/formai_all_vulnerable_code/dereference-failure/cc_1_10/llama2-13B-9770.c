//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int width, height;
    unsigned char *data;
} Image;

Image *load_image(const char *file_name) {
    Image *image = malloc(sizeof(Image));
    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(WIDTH * HEIGHT * 3);

    FILE *file = fopen(file_name, "rb");
    fread(image->data, 1, WIDTH * HEIGHT * 3, file);
    fclose(file);

    return image;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = dy > dx;
    int x = x1;
    int y = y1;

    if (steep) {
        dy = -dy;
        x = x2;
    }

    for (int i = 0; i < dx; i++) {
        image->data[(y + dy * i) * WIDTH + x] = (steep ? x : x + dy);
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image->data[(y + j) * WIDTH + x + i] = (i + j) % 2 ? 0xFF : 0x00;
        }
    }
}

void draw_ellipse(Image *image, int x, int y, int width, int height) {
    int ax = width / 2;
    int ay = height / 2;
    int dx = width;
    int dy = height;

    for (int i = 0; i < dx; i++) {
        for (int j = 0; j < dy; j++) {
            int a = (i * (ay - j) / dx) % 2 * 360;
            image->data[(y + j) * WIDTH + x + i] = (a * 360) % 360;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int fx = x - radius;
    int fy = y - radius;
    int sx = x + radius;
    int sy = y + radius;

    for (int i = fx; i <= sx; i++) {
        for (int j = fy; j <= sy; j++) {
            int distance = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (distance <= radius) {
                image->data[(j * WIDTH + i) * 3] = (distance * 360) % 360;
            }
        }
    }
}

void save_image(Image *image, const char *file_name) {
    FILE *file = fopen(file_name, "wb");
    fwrite(image->data, 1, WIDTH * HEIGHT * 3, file);
    fclose(file);
}

int main() {
    Image *image = load_image("example.bmp");

    draw_line(image, 100, 100, 200, 200);
    draw_rectangle(image, 300, 300, 100, 50);
    draw_ellipse(image, 400, 400, 50, 30);
    draw_circle(image, 500, 500, 20);

    save_image(image, "output.bmp");

    return 0;
}