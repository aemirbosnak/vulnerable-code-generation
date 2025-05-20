//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 320
#define HEIGHT 240

typedef struct {
    int x;
    int y;
    char color;
} Pixel;

char *pixels;

void setPixel(int x, int y, char color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    pixels[y * WIDTH + x] = color;
}

void line(int x0, int y0, int x1, int y1, char color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        setPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void circle(int x, int y, int radius, char color) {
    int x0 = radius, y0 = 0, err = 1 - x0;
    while (x0 >= y0) {
        setPixel(x + x0, y + y0, color);
        setPixel(x + y0, y + x0, color);
        setPixel(x - y0, y + x0, color);
        setPixel(x - x0, y + y0, color);
        setPixel(x - x0, y - y0, color);
        setPixel(x - y0, y - x0, color);
        setPixel(x + y0, y - x0, color);
        setPixel(x + x0, y - y0, color);
        if (err <= 0) {
            y0++;
            err += 2 * y0 + 1;
        }
        if (err > 0) {
            x0--;
            err -= 2 * x0 + 1;
        }
    }
}

void rectangle(int x0, int y0, int x1, int y1, char color) {
    for (int y = y0; y <= y1; y++) {
        for (int x = x0; x <= x1; x++) {
            setPixel(x, y, color);
        }
    }
}

void triangle(int x0, int y0, int x1, int y1, int x2, int y2, char color) {
    line(x0, y0, x1, y1, color);
    line(x1, y1, x2, y2, color);
    line(x2, y2, x0, y0, color);
}

void polygon(int *x, int *y, int n, char color) {
    for (int i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1], color);
    }
    line(x[n - 1], y[n - 1], x[0], y[0], color);
}

void ellipse(int x, int y, int rx, int ry, char color) {
    int x0 = rx, y0 = 0, err = 1 - x0;
    while (x0 >= y0) {
        setPixel(x + x0, y + y0, color);
        setPixel(x + y0, y + x0, color);
        setPixel(x - y0, y + x0, color);
        setPixel(x - x0, y + y0, color);
        setPixel(x - x0, y - y0, color);
        setPixel(x - y0, y - x0, color);
        setPixel(x + y0, y - x0, color);
        setPixel(x + x0, y - y0, color);
        if (err <= 0) {
            y0++;
            err += 2 * y0 + 1;
        }
        if (err > 0) {
            x0--;
            err -= 2 * x0 + 1;
        }
    }
    int a2 = rx * rx, b2 = ry * ry, f = 1 - a2 / b2;
    while (y0 < ry) {
        setPixel(x + x0, y + y0, color);
        setPixel(x + y0, y + x0, color);
        setPixel(x - y0, y + x0, color);
        setPixel(x - x0, y + y0, color);
        if (f < 0) {
            y0++;
            err += 2 * y0 + 1;
        }
        if (f > 0) {
            x0--;
            err -= 2 * x0 + 1;
        }
        a2 = (x0 + 1) * (x0 + 1);
        b2 = (y0 + 1) * (y0 + 1);
        f = b2 - a2 * b2 / a2;
    }
}

int main() {
    pixels = malloc(WIDTH * HEIGHT);
    memset(pixels, 0, WIDTH * HEIGHT);

    // Draw a black background
    rectangle(0, 0, WIDTH - 1, HEIGHT - 1, 0);

    // Draw a white circle
    circle(WIDTH / 2, HEIGHT / 2, 100, 255);

    // Draw a green rectangle
    rectangle(10, 10, 100, 100, 128);

    // Draw a blue triangle
    int x[] = {100, 200, 150};
    int y[] = {100, 100, 200};
    polygon(x, y, 3, 64);

    // Draw a yellow ellipse
    ellipse(200, 200, 100, 50, 255);

    // Write the pixels to a PPM file
    FILE *fp = fopen("image.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d %d %d\n", pixels[y * WIDTH + x], pixels[y * WIDTH + x], pixels[y * WIDTH + x]);
        }
    }
    fclose(fp);

    free(pixels);
    return 0;
}