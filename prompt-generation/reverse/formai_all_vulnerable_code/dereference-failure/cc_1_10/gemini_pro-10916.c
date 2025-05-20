//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b, a;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel){0, 0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, Pixel color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int radius, Pixel color) {
    int x0 = x - radius, y0 = y - radius, x1 = x + radius, y1 = y + radius;
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                set_pixel(image, i, j, color);
            }
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int x1, int y1, Pixel color) {
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            set_pixel(image, i, j, color);
        }
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, Pixel color) {
    draw_line(image, x0, y0, x1, y1, color);
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x0, y0, color);
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel color = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a white background
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            set_pixel(image, x, y, (Pixel){255, 255, 255, 255});
        }
    }

    // Draw a red circle
    draw_circle(image, WIDTH / 2, HEIGHT / 2, 100, (Pixel){255, 0, 0, 255});

    // Draw a green rectangle
    draw_rectangle(image, 100, 100, 200, 200, (Pixel){0, 255, 0, 255});

    // Draw a blue triangle
    draw_triangle(image, 300, 300, 400, 400, 500, 300, (Pixel){0, 0, 255, 255});

    // Save the image to a file
    save_image(image, "pixel-art.ppm");

    free_image(image);

    return 0;
}