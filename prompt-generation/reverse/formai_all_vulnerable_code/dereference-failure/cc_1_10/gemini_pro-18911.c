//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, unsigned char value) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = value;
}

unsigned char get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, unsigned char value) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        set_pixel(image, x0, y0, value);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_circle(Image *image, int x0, int y0, int radius, unsigned char value) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, value);
        set_pixel(image, x0 - x, y0 + y, value);
        set_pixel(image, x0 + x, y0 - y, value);
        set_pixel(image, x0 - x, y0 - y, value);
        set_pixel(image, x0 + y, y0 + x, value);
        set_pixel(image, x0 - y, y0 + x, value);
        set_pixel(image, x0 + y, y0 - x, value);
        set_pixel(image, x0 - y, y0 - x, value);

        y++;
        err += 1 + 2 * y;
        if (2 * (err - x) + 1 > 0) {
            x--;
            err -= 1 + 2 * x;
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int width, int height, unsigned char value) {
    for (int y = y0; y < y0 + height; y++) {
        for (int x = x0; x < x0 + width; x++) {
            set_pixel(image, x, y, value);
        }
    }
}

void write_ppm(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");
    fwrite(image->pixels, 1, image->width * image->height * sizeof(unsigned char), file);
    fclose(file);
}

int main() {
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);

    draw_line(image, 0, 0, MAX_WIDTH, MAX_HEIGHT, 255);
    draw_circle(image, MAX_WIDTH / 2, MAX_HEIGHT / 2, 100, 255);
    draw_rectangle(image, 100, 100, 200, 200, 255);

    write_ppm(image, "output.ppm");
    free_image(image);
    return 0;
}