//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 128
#define HEIGHT 128
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color *pixels;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(width * height * sizeof(Color));
    image->width = width;
    image->height = height;
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

void draw_line(Image *image, int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2;

    while (1) {
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int x1, int y1, Color color) {
    draw_line(image, x0, y0, x1, y0, color);
    draw_line(image, x1, y0, x1, y1, color);
    draw_line(image, x1, y1, x0, y1, color);
    draw_line(image, x0, y1, x0, y0, color);
}

void draw_circle(Image *image, int x0, int y0, int radius, Color color) {
    int x = radius, y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, color);
        set_pixel(image, x0 + y, y0 + x, color);
        set_pixel(image, x0 - y, y0 + x, color);
        set_pixel(image, x0 - x, y0 + y, color);
        set_pixel(image, x0 - x, y0 - y, color);
        set_pixel(image, x0 - y, y0 - x, color);
        set_pixel(image, x0 + y, y0 - x, color);
        set_pixel(image, x0 + x, y0 - y, color);

        y++;
        err += 1 + 2*y;
        if (2*(err - x + 1) < 0) {
            x--;
            err += 1 - 2*x;
        }
    }
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a red background
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            set_pixel(image, x, y, (Color){255, 0, 0});
        }
    }

    // Draw a white square
    draw_rectangle(image, 32, 32, 96, 96, (Color){255, 255, 255});

    // Draw a blue circle
    draw_circle(image, 64, 64, 32, (Color){0, 0, 255});

    // Draw a green line
    draw_line(image, 0, 0, WIDTH, HEIGHT, (Color){0, 255, 0});

    // Save the image to a file
    FILE *file = fopen("output.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    free_image(image);

    return 0;
}