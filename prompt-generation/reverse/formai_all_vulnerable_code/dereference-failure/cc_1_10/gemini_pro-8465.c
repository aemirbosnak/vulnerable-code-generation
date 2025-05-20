//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b, a;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    int index = y * image->width + x;
    image->pixels[index] = color;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel){0, 0, 0, 0};
    }
    int index = y * image->width + x;
    return image->pixels[index];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, Pixel color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (x0 != x1 || y0 != y1) {
        set_pixel(image, x0, y0, color);
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int radius, Pixel color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int radius2 = radius * radius;
    for (int i = 0; i < dx; i++) {
        for (int j = 0; j < dy; j++) {
            if ((x0 + i - x)*(x0 + i - x) + (y0 + j - y)*(y0 + j - y) <= radius2) {
                set_pixel(image, x0 + i, y0 + j, color);
            }
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int x1, int y1, Pixel color) {
    for (int i = x0; i <= x1; i++) {
        set_pixel(image, i, y0, color);
        set_pixel(image, i, y1, color);
    }
    for (int i = y0; i <= y1; i++) {
        set_pixel(image, x0, i, color);
        set_pixel(image, x1, i, color);
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, Pixel color) {
    draw_line(image, x0, y0, x1, y1, color);
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x0, y0, color);
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    Image *image = create_image(WIDTH, HEIGHT);

    // Draw a red circle
    draw_circle(image, WIDTH / 2, HEIGHT / 2, 100, (Pixel){255, 0, 0, 255});

    // Draw a green rectangle
    draw_rectangle(image, 100, 100, 200, 200, (Pixel){0, 255, 0, 255});

    // Draw a blue triangle
    draw_triangle(image, 100, 100, 200, 200, 100, 300, (Pixel){0, 0, 255, 255});

    // Save the image to a file
    save_image(image, "pixel_art.ppm");

    // Destroy the image
    destroy_image(image);

    return 0;
}