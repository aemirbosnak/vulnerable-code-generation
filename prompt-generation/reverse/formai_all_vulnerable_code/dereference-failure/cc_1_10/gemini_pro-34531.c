//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} color;

typedef struct {
    color pixels[WIDTH][HEIGHT];
} image;

image *create_image() {
    image *img = malloc(sizeof(image));
    if (img == NULL) {
        return NULL;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[x][y] = (color){0, 0, 0};
        }
    }

    return img;
}

void destroy_image(image *img) {
    free(img);
}

int load_image(image *img, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return -1;
    }

    fread(img->pixels, sizeof(color), WIDTH * HEIGHT, f);

    fclose(f);

    return 0;
}

int save_image(image *img, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        return -1;
    }

    fwrite(img->pixels, sizeof(color), WIDTH * HEIGHT, f);

    fclose(f);

    return 0;
}

void draw_line(image *img, int x1, int y1, int x2, int y2, color c) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        img->pixels[x1][y1] = c;

        if (x1 == x2 && y1 == y2) {
            break;
        }

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

void draw_circle(image *img, int x, int y, int radius, color c) {
    int x0 = x;
    int y0 = y;

    int x1 = x0 + radius;
    int y1 = y0;

    int dx = x1 - x;
    int dy = y1 - y;

    int err = dx - dy;

    while (1) {
        img->pixels[x1][y1] = c;
        img->pixels[x1][-y1] = c;
        img->pixels[-x1][y1] = c;
        img->pixels[-x1][-y1] = c;

        if (x1 == x0 && y1 == y0) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 -= 1;
        }

        if (e2 < dx) {
            err += dx;
            y1 -= 1;
        }
    }
}

void draw_rectangle(image *img, int x, int y, int width, int height, color c) {
    for (int i = 0; i < width; i++) {
        img->pixels[x + i][y] = c;
        img->pixels[x + i][y + height - 1] = c;
    }

    for (int i = 0; i < height; i++) {
        img->pixels[x][y + i] = c;
        img->pixels[x + width - 1][y + i] = c;
    }
}

void draw_triangle(image *img, int x1, int y1, int x2, int y2, int x3, int y3, color c) {
    draw_line(img, x1, y1, x2, y2, c);
    draw_line(img, x2, y2, x3, y3, c);
    draw_line(img, x3, y3, x1, y1, c);
}

int main() {
    image *img = create_image();

    draw_line(img, 0, 0, WIDTH - 1, HEIGHT - 1, (color){255, 0, 0});
    draw_line(img, 0, HEIGHT - 1, WIDTH - 1, 0, (color){0, 255, 0});
    draw_circle(img, WIDTH / 2, HEIGHT / 2, WIDTH / 4, (color){0, 0, 255});
    draw_rectangle(img, WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2, (color){255, 255, 0});
    draw_triangle(img, WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2, WIDTH / 4, HEIGHT * 3 / 4, (color){0, 255, 255});

    save_image(img, "pixel_art.bmp");

    destroy_image(img);

    return 0;
}