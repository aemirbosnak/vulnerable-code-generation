//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_VAL 255

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel** image;

void init_image() {
    image = malloc(HEIGHT * sizeof(pixel*));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = malloc(WIDTH * sizeof(pixel));
        for (int j = 0; j < WIDTH; j++) {
            image[i][j].r = 0;
            image[i][j].g = 0;
            image[i][j].b = 0;
        }
    }
}

void free_image() {
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);
}

void save_image(const char* filename) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_VAL);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fputc(image[i][j].r, file);
            fputc(image[i][j].g, file);
            fputc(image[i][j].b, file);
        }
    }
    fclose(file);
}

void draw_line(int x1, int y1, int x2, int y2, pixel color) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    while (1) {
        image[y1][x1] = color;
        if (x1 == x2 && y1 == y2) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

void draw_circle(int x0, int y0, int radius, pixel color) {
    int x = radius, y = 0;
    int err = 0;

    while (x >= y) {
        image[y0 + y][x0 + x] = color;
        image[y0 + y][x0 - x] = color;
        image[y0 - y][x0 + x] = color;
        image[y0 - y][x0 - x] = color;
        image[y0 + x][x0 + y] = color;
        image[y0 + x][x0 - y] = color;
        image[y0 - x][x0 + y] = color;
        image[y0 - x][x0 - y] = color;

        y += 1;
        err += 1 + 2*y;
        if (2*(err - x) + 1 > 0) {
            x -= 1;
            err -= 1 + 2*x;
        }
    }
}

void draw_rectangle(int x1, int y1, int x2, int y2, pixel color) {
    for (int i = x1; i <= x2; i++) {
        image[y1][i] = color;
        image[y2][i] = color;
    }
    for (int i = y1; i <= y2; i++) {
        image[i][x1] = color;
        image[i][x2] = color;
    }
}

int main() {
    srand(time(NULL));

    init_image();

    // Draw a red line
    draw_line(100, 100, 200, 200, (pixel){255, 0, 0});

    // Draw a green circle
    draw_circle(300, 300, 50, (pixel){0, 255, 0});

    // Draw a blue rectangle
    draw_rectangle(400, 400, 600, 600, (pixel){0, 0, 255});

    // Save the image
    save_image("image.ppm");

    free_image();

    return 0;
}