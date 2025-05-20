//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color data[WIDTH][HEIGHT];
} Image;

Image *create_image() {
    Image *image = malloc(sizeof(Image));
    memset(image->data, 0, sizeof(image->data));
    return image;
}

void destroy_image(Image *image) {
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    image->data[x][y] = color;
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return (Color){0, 0, 0};
    }
    return image->data[x][y];
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

void draw_circle(Image *image, int x0, int y0, int radius, Color color) {
    int x = radius, y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, color);
        set_pixel(image, x0 - x, y0 + y, color);
        set_pixel(image, x0 + x, y0 - y, color);
        set_pixel(image, x0 - x, y0 - y, color);
        set_pixel(image, x0 + y, y0 + x, color);
        set_pixel(image, x0 - y, y0 + x, color);
        set_pixel(image, x0 + y, y0 - x, color);
        set_pixel(image, x0 - y, y0 - x, color);

        y++;
        err += 1 + 2*y;
        if (2*(err-x) + 1 > 0) {
            x--;
            err -= 1 + 2*x;
        }
    }
}

void draw_rectangle(Image *image, int x0, int y0, int width, int height, Color color) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x0 + i, y0, color);
        set_pixel(image, x0 + i, y0 + height - 1, color);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x0, y0 + i, color);
        set_pixel(image, x0 + width - 1, y0 + i, color);
    }
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    fprintf(file, "255\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    Image *image = create_image();

    Color white = {255, 255, 255};
    Color black = {0, 0, 0};
    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color blue = {0, 0, 255};

    draw_rectangle(image, 0, 0, WIDTH, HEIGHT, white);
    draw_line(image, 0, 0, WIDTH - 1, HEIGHT - 1, black);
    draw_line(image, 0, HEIGHT - 1, WIDTH - 1, 0, black);
    draw_circle(image, WIDTH / 2, HEIGHT / 2, WIDTH / 4, red);
    draw_rectangle(image, WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2, green);
    draw_circle(image, WIDTH / 4, HEIGHT / 4, WIDTH / 8, blue);

    save_image(image, "image.ppm");
    destroy_image(image);

    return 0;
}