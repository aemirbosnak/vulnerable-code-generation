//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x, y;
    int width, height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(WIDTH * HEIGHT * 3);
    return image;
}

void draw_point(Image *image, int x, int y) {
    image->data[y * WIDTH * 3 + x * 3] = 255;
    image->data[y * WIDTH * 3 + x * 3 + 1] = 0;
    image->data[y * WIDTH * 3 + x * 3 + 2] = 0;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepx = x2 > x1 ? 1 : -1;
    int stepy = y2 > y1 ? 1 : -1;
    int x = x1, y = y1;

    for (int i = 0; i < dx; i++) {
        image->data[y * WIDTH * 3 + x * 3] = 255;
        image->data[y * WIDTH * 3 + x * 3 + 1] = 0;
        image->data[y * WIDTH * 3 + x * 3 + 2] = 0;

        x += stepx;
        y += stepy;
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image->data[y * WIDTH * 3 + x * 3 + i * width * 3 + j * 3] = 255;
            image->data[y * WIDTH * 3 + x * 3 + i * width * 3 + j * 3 + 1] = 0;
            image->data[y * WIDTH * 3 + x * 3 + i * width * 3 + j * 3 + 2] = 0;
        }
    }
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(image->data, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);
    fclose(file);
}

int main() {
    Image *image = load_image("example.bmp");
    draw_point(image, 100, 100);
    draw_line(image, 100, 100, 200, 200);
    draw_rectangle(image, 150, 150, 100, 50);
    save_image(image, "output.bmp");
    return 0;
}