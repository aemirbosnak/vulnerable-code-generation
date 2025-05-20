//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x, y;
    int width, height;
    unsigned char *pixels;
} Image;

Image *load_image(const char *file_name) {
    Image *image = malloc(sizeof(Image));
    int i, j;

    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;

    image->pixels = malloc(WIDTH * HEIGHT * 3);

    FILE *file = fopen(file_name, "rb");
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fread(&image->pixels[i * 3], 1, 3, file);
    }
    fclose(file);

    return image;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int i, j;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->pixels[i * HEIGHT * 3 + j * 3] = 255;
        }
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    draw_line(image, x, y, x + width, y + height);
    draw_line(image, x, y + height, x + width, y);
    draw_line(image, x + width, y, x, y + height);
    draw_line(image, x + width, y + height, x, y);
}

void draw_ellipse(Image *image, int x, int y, int width, int height) {
    int dx = width / 2;
    int dy = height / 2;
    int x_end = x + width;
    int y_end = y + height;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (((x - dx) * (x - dx) + (y - dy) * (y - dy)) <= (dx * dx) + (dy * dy)) {
                image->pixels[i * HEIGHT * 3 + j * 3] = 255;
            }
        }
        x++;
    }
}

void draw_arc(Image *image, int x, int y, int width, int height, int start, int end) {
    int dx = width / 2;
    int dy = height / 2;
    int x_end = x + width;
    int y_end = y + height;

    for (int i = start; i <= end; i++) {
        int angle = i * (2 * M_PI / (end - start));
        int x1 = x + dx * cos(angle);
        int y1 = y + dy * sin(angle);
        if (x1 >= x && x1 <= x_end && y1 >= y && y1 <= y_end) {
            image->pixels[i * HEIGHT * 3 + (y - y1) * WIDTH + (x - x1)] = 255;
        }
    }
}

void save_image(Image *image, const char *file_name) {
    FILE *file = fopen(file_name, "wb");
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(&image->pixels[i * 3], 1, 3, file);
    }
    fclose(file);
}

int main() {
    Image *image = load_image("image.bmp");

    draw_rectangle(image, 100, 100, 200, 100);
    draw_ellipse(image, 250, 250, 100, 50);
    draw_arc(image, 350, 350, 100, 100, 0, 360);

    save_image(image, "output.bmp");

    return 0;
}