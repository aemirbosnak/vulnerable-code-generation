//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    char *image;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    int width, height;
    unsigned char *data;

    // Read image file
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    width = (int)ftell(file);
    height = (int)((width * 3) / 2);
    data = malloc(width * height * 3);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    // Set image properties
    image->width = width;
    image->height = height;
    image->image = data;

    return image;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    unsigned char *data = image->image;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = dy > dx;

    if (steep) {
        x1 = x1 + (y1 * dx) / dy;
        y1 = y1 + (x1 * dy) / dx;
    } else {
        x1 = x1 + (dx * y1) / dy;
        y1 = y1 + (dy * x1) / dx;
    }

    for (int i = 0; i < abs(dx); i++) {
        data[i * image->width * 3 + 0] = (x1 * 255) / dx;
        data[i * image->width * 3 + 1] = (y1 * 255) / dy;
        data[i * image->width * 3 + 2] = 255;
        x1++;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            draw_line(image, x + j, y + i, x + j, y + i + 1);
        }
    }
}

void draw_circle(image_t *image, int x, int y, int radius) {
    int f = 1 - (radius * radius) / (2 * image->width * image->height);
    int dx = 0;
    int dy = 0;
    int x1 = x;
    int y1 = y;

    if (f > 0) {
        for (int i = 0; i < image->width; i++) {
            for (int j = 0; j < image->height; j++) {
                int distance = sqrt(dx * dx + dy * dy);
                if (distance <= radius) {
                    draw_line(image, x1, y1, x1 + dx, y1 + dy);
                }
                dx += 2 * (x1 - i) * (x1 - i) / (image->width * image->width);
                dy += 2 * (y1 - j) * (y1 - j) / (image->height * image->height);
            }
        }
    }
}

void save_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(image->image, 1, image->width * image->height * 3, file);
    fclose(file);
}

int main() {
    image_t *image = load_image("image.bmp");
    draw_rectangle(image, 100, 100, 300, 200);
    draw_circle(image, 200, 200, 100);
    save_image(image, "output.bmp");
    return 0;
}