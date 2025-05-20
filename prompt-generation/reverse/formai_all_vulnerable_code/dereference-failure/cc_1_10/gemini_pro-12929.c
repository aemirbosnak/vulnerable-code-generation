//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    int width, height;
    Color *pixels;
} Image;

void createImage(Image *image, int width, int height) {
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Color) * width * height);
}

void destroyImage(Image *image) {
    free(image->pixels);
}

void setPixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Color getPixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Color){0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void drawLine(Image *image, int x1, int y1, int x2, int y2, Color color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        setPixel(image, x1, y1, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawCircle(Image *image, int x0, int y0, int radius, Color color) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        setPixel(image, x0 + x, y0 + y, color);
        setPixel(image, x0 - x, y0 + y, color);
        setPixel(image, x0 + x, y0 - y, color);
        setPixel(image, x0 - x, y0 - y, color);
        setPixel(image, x0 + y, y0 + x, color);
        setPixel(image, x0 - y, y0 + x, color);
        setPixel(image, x0 + y, y0 - x, color);
        setPixel(image, x0 - y, y0 - x, color);

        y++;
        err += 1 + 2 * y;
        if (2 * (err - x) + 1 > 0) {
            x--;
            err -= 1 + 2 * x;
        }
    }
}

void drawRectangle(Image *image, int x1, int y1, int x2, int y2, Color color) {
    for (int x = x1; x <= x2; x++) {
        setPixel(image, x, y1, color);
        setPixel(image, x, y2, color);
    }
    for (int y = y1; y <= y2; y++) {
        setPixel(image, x1, y, color);
        setPixel(image, x2, y, color);
    }
}

void saveImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return;
    }

    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Color color = getPixel(image, x, y);
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    Image image;
    createImage(&image, MAX_WIDTH, MAX_HEIGHT);

    // Draw a red circle
    drawCircle(&image, MAX_WIDTH / 2, MAX_HEIGHT / 2, 100, (Color){255, 0, 0});

    // Draw a green rectangle
    drawRectangle(&image, 100, 100, 200, 200, (Color){0, 255, 0});

    // Draw a blue line
    drawLine(&image, 0, 0, MAX_WIDTH, MAX_HEIGHT, (Color){0, 0, 255});

    saveImage(&image, "pixel_art.ppm");

    destroyImage(&image);

    return 0;
}