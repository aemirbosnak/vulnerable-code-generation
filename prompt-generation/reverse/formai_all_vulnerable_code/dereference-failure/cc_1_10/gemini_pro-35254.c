//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Color;

typedef struct {
    int width, height;
    Color *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Color) * width * height);
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Color){0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, Color color) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x1, y1, color);
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x1 += sx;
        }
        if (e2 <  dy) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius, Color color) {
    int x1 = x - radius, y1 = y - radius, x2 = x + radius, y2 = y + radius;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                set_pixel(image, i, j, color);
            }
        }
    }
}

void draw_triangle(Image *image, int x1, int y1, int x2, int y2, int x3, int y3, Color color) {
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x3, y3, color);
    draw_line(image, x3, y3, x1, y1, color);
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, Color color) {
    draw_line(image, x1, y1, x2, y1, color);
    draw_line(image, x2, y1, x2, y2, color);
    draw_line(image, x2, y2, x1, y2, color);
    draw_line(image, x1, y2, x1, y1, color);
}

void draw_image(Image *image, FILE *fp) {
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(fp, "\n");
    }
}

int main() {
    Image *image = create_image(500, 500);

    Color white = {255, 255, 255};
    Color black = {0, 0, 0};
    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color blue = {0, 0, 255};

    // Draw a background
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            if (x < image->width / 2) {
                set_pixel(image, x, y, white);
            } else {
                set_pixel(image, x, y, black);
            }
        }
    }

    // Draw a circle
    draw_circle(image, 250, 250, 100, red);

    // Draw a triangle
    draw_triangle(image, 100, 100, 250, 100, 175, 200, green);

    // Draw a rectangle
    draw_rectangle(image, 300, 100, 400, 200, blue);

    // Save the image to a file
    FILE *fp = fopen("image.ppm", "w");
    draw_image(image, fp);
    fclose(fp);

    free_image(image);

    return 0;
}