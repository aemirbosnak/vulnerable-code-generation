//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <png.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT * BITS_PER_PIXEL / 8)

typedef struct {
    unsigned char *data;
    int width, height, bits_per_pixel;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    image->data = malloc(WIDTH * HEIGHT * BITS_PER_PIXEL / 8);
    image->width = WIDTH;
    image->height = HEIGHT;
    image->bits_per_pixel = BITS_PER_PIXEL;

    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return NULL;
    }

    fread(image->data, 1, MAX_IMAGE_SIZE, file);
    fclose(file);

    return image;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steep = dx > dy;

    if (steep) {
        int temp = x1;
        x1 = y1;
        y1 = temp;
    }

    for (int x = x1; x <= x2; x++) {
        int y = y1 + (x - x1) * dy / dx;
        image->data[((y * image->width) + x) * image->bits_per_pixel] = color;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height, int color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image->data[((y + i) * image->width + x + j) * image->bits_per_pixel] = color;
        }
    }
}

void draw_ellipse(image_t *image, int x, int y, int width, int height, int color) {
    int factor = 1;
    int x1 = x;
    int y1 = y;
    int x2 = x + width;
    int y2 = y + height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            int dist = sqrt(dx * dx + dy * dy);

            if (dist < width / 2) {
                image->data[((y1 + i) * image->width + x1 + j) * image->bits_per_pixel] = color;
            }

            if (dist > width / 2) {
                break;
            }

            x1 += factor;
            y1 += factor;
            x2 -= factor;
            y2 -= factor;
        }
    }
}

void draw_arc(image_t *image, int x, int y, int width, int height, int start_angle, int end_angle, int color) {
    int factor = 1;
    int x1 = x;
    int y1 = y;
    int x2 = x + width;
    int y2 = y + height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            int dist = sqrt(dx * dx + dy * dy);
            int angle = start_angle + (i * 360 / height) % 360;

            if (dist < width / 2) {
                image->data[((y1 + i) * image->width + x1 + j) * image->bits_per_pixel] = color;
            }

            if (dist > width / 2) {
                break;
            }

            x1 += factor;
            y1 += factor;
            x2 -= factor;
            y2 -= factor;
        }
    }
}

void save_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return;
    }

    fwrite(image->data, 1, MAX_IMAGE_SIZE, file);
    fclose(file);
}

int main() {
    image_t *image = load_image("example.png");
    if (!image) {
        fprintf(stderr, "Failed to load image\n");
        return 1;
    }

    draw_line(image, 100, 100, 200, 200, 0xFF0000);
    draw_rectangle(image, 50, 50, 100, 100, 0x00FF00);
    draw_ellipse(image, 200, 200, 100, 50, 0x0000FF);
    draw_arc(image, 300, 300, 100, 50, 0, 360, 0xFF0000);

    save_image(image, "output.png");

    free(image->data);
    free(image);

    return 0;
}