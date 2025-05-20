//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void destroyImage(Image *image) {
    free(image->data);
    free(image);
}

void setPixel(Image *image, int x, int y, char c) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->data[y * image->width + x] = c;
    }
}

char getPixel(Image *image, int x, int y) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        return image->data[y * image->width + x];
    }
    return 0;
}

void drawLine(Image *image, int x1, int y1, int x2, int y2, char c) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        setPixel(image, x1, y1, c);
        int e2 = err * 2;
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

void drawCircle(Image *image, int x, int y, int radius, char c) {
    int x0 = 0;
    int y0 = radius;
    int err = 0;

    while (x0 <= y0) {
        setPixel(image, x + x0, y + y0, c);
        setPixel(image, x + y0, y + x0, c);
        setPixel(image, x - y0, y + x0, c);
        setPixel(image, x - x0, y + y0, c);
        setPixel(image, x + x0, y - y0, c);
        setPixel(image, x + y0, y - x0, c);
        setPixel(image, x - y0, y - x0, c);
        setPixel(image, x - x0, y - y0, c);

        x0++;
        err += 1 + 2 * x0;
        if (2 * (err - y0) + 1 > 0) {
            y0--;
            err += 1 - 2 * y0;
        }
    }
}

void drawFilledCircle(Image *image, int x, int y, int radius, char c) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {
                setPixel(image, x + i, y + j, c);
            }
        }
    }
}

void drawRectangle(Image *image, int x1, int y1, int x2, int y2, char c) {
    for (int i = x1; i <= x2; i++) {
        setPixel(image, i, y1, c);
        setPixel(image, i, y2, c);
    }
    for (int i = y1; i <= y2; i++) {
        setPixel(image, x1, i, c);
        setPixel(image, x2, i, c);
    }
}

void drawFilledRectangle(Image *image, int x1, int y1, int x2, int y2, char c) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            setPixel(image, i, j, c);
        }
    }
}

void saveImage(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P1\n%d %d\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d ", getPixel(image, j, i));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image *image = createImage(256, 256);

    // Draw a line from (0, 0) to (255, 255)
    drawLine(image, 0, 0, 255, 255, '*');

    // Draw a circle at (128, 128) with radius 64
    drawCircle(image, 128, 128, 64, '*');

    // Draw a filled circle at (128, 128) with radius 32
    drawFilledCircle(image, 128, 128, 32, '*');

    // Draw a rectangle from (64, 64) to (192, 192)
    drawRectangle(image, 64, 64, 192, 192, '*');

    // Draw a filled rectangle from (96, 96) to (160, 160)
    drawFilledRectangle(image, 96, 96, 160, 160, '*');

    // Save the image to a file
    saveImage(image, "pixel_art.pbm");

    destroyImage(image);
    return 0;
}