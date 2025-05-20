//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b, a;
} Color;

Color palette[] = {
    {0, 0, 0, 255},
    {255, 255, 255, 255},
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {0, 255, 255, 255},
    {255, 0, 255, 255}
};

Color** pixels;

void init_pixels() {
    pixels = malloc(sizeof(Color*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = malloc(sizeof(Color) * WIDTH);
    }
}

void free_pixels() {
    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);
}

void draw_pixel(int x, int y, Color color) {
    pixels[y][x] = color;
}

void draw_line(int x0, int y0, int x1, int y1, Color color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while (x0 != x1 || y0 != y1) {
        draw_pixel(x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void draw_circle(int x0, int y0, int radius, Color color) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (y >= x) {
        draw_pixel(x0 + x, y0 + y, color);
        draw_pixel(x0 - x, y0 + y, color);
        draw_pixel(x0 + x, y0 - y, color);
        draw_pixel(x0 - x, y0 - y, color);
        draw_pixel(x0 + y, y0 + x, color);
        draw_pixel(x0 - y, y0 + x, color);
        draw_pixel(x0 + y, y0 - x, color);
        draw_pixel(x0 - y, y0 - x, color);
        if (d < 0) { d += 4 * x + 6;  }
        else {       d += 4 * (x - y) + 10; y--; }
        x++;
    }
}

void draw_rectangle(int x0, int y0, int width, int height, Color color) {
    for (int i = x0; i < x0 + width; i++) {
        draw_pixel(i, y0, color);
        draw_pixel(i, y0 + height - 1, color);
    }
    for (int i = y0; i < y0 + height; i++) {
        draw_pixel(x0, i, color);
        draw_pixel(x0 + width - 1, i, color);
    }
}

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, Color color) {
    draw_line(x0, y0, x1, y1, color);
    draw_line(x1, y1, x2, y2, color);
    draw_line(x2, y2, x0, y0, color);
}

void draw_star(int x0, int y0, int radius, int points, Color color) {
    float angle = 2 * M_PI / points;
    for (int i = 0; i < points; i++) {
        float x1 = x0 + radius * cos(i * angle);
        float y1 = y0 + radius * sin(i * angle);
        float x2 = x0 + radius * cos((i + 0.5) * angle);
        float y2 = y0 + radius * sin((i + 0.5) * angle);
        draw_line(x1, y1, x2, y2, color);
    }
}

void draw_fractal_tree(int x0, int y0, int length, float angle, Color color) {
    if (length < 1) return;
    int x1 = x0 + length * cos(angle);
    int y1 = y0 + length * sin(angle);
    draw_line(x0, y0, x1, y1, color);
    draw_fractal_tree(x1, y1, length * 0.75, angle + M_PI / 4, color);
    draw_fractal_tree(x1, y1, length * 0.75, angle - M_PI / 4, color);
}

void draw_scene() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            draw_pixel(i, j, palette[0]);
        }
    }
    draw_circle(WIDTH / 2, HEIGHT / 2, 100, palette[1]);
    draw_rectangle(100, 100, 200, 200, palette[2]);
    draw_triangle(300, 300, 400, 400, 500, 300, palette[3]);
    draw_star(600, 400, 50, 5, palette[4]);
    draw_fractal_tree(700, 500, 100, M_PI / 2, palette[5]);
}

void save_image(char* filename) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Color color = pixels[i][j];
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    init_pixels();
    draw_scene();
    save_image("surrealism.ppm");
    free_pixels();
    return 0;
}