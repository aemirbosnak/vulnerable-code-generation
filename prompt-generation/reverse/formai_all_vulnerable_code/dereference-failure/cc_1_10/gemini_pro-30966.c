//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    uint8_t *pixels;
} Bitmap;

Bitmap *bitmap_new(int width, int height) {
    Bitmap *bitmap = malloc(sizeof(Bitmap));
    bitmap->width = width;
    bitmap->height = height;
    bitmap->pixels = malloc(width * height * sizeof(uint8_t));
    return bitmap;
}

void bitmap_free(Bitmap *bitmap) {
    free(bitmap->pixels);
    free(bitmap);
}

void bitmap_set_pixel(Bitmap *bitmap, int x, int y, uint8_t color) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height) {
        return;
    }
    bitmap->pixels[y * bitmap->width + x] = color;
}

uint8_t bitmap_get_pixel(Bitmap *bitmap, int x, int y) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height) {
        return 0;
    }
    return bitmap->pixels[y * bitmap->width + x];
}

void bitmap_draw_line(Bitmap *bitmap, int x0, int y0, int x1, int y1, uint8_t color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        bitmap_set_pixel(bitmap, x0, y0, color);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void bitmap_draw_circle(Bitmap *bitmap, int x0, int y0, int radius, uint8_t color) {
    int x = 0;
    int y = radius;
    int err = 0;

    while (x <= y) {
        bitmap_set_pixel(bitmap, x0 + x, y0 + y, color);
        bitmap_set_pixel(bitmap, x0 + y, y0 + x, color);
        bitmap_set_pixel(bitmap, x0 - x, y0 + y, color);
        bitmap_set_pixel(bitmap, x0 - y, y0 + x, color);
        bitmap_set_pixel(bitmap, x0 + x, y0 - y, color);
        bitmap_set_pixel(bitmap, x0 + y, y0 - x, color);
        bitmap_set_pixel(bitmap, x0 - x, y0 - y, color);
        bitmap_set_pixel(bitmap, x0 - y, y0 - x, color);

        x++;
        err += 1 + 2 * x;

        if (2 * (err - y) <= 2 * (x - 1)) {
            y--;
            err += 1 - 2 * y;
        }
    }
}

void bitmap_draw_triangle(Bitmap *bitmap, int x0, int y0, int x1, int y1, int x2, int y2, uint8_t color) {
    bitmap_draw_line(bitmap, x0, y0, x1, y1, color);
    bitmap_draw_line(bitmap, x1, y1, x2, y2, color);
    bitmap_draw_line(bitmap, x2, y2, x0, y0, color);
}

void bitmap_draw_rectangle(Bitmap *bitmap, int x0, int y0, int width, int height, uint8_t color) {
    bitmap_draw_line(bitmap, x0, y0, x0 + width, y0, color);
    bitmap_draw_line(bitmap, x0, y0, x0, y0 + height, color);
    bitmap_draw_line(bitmap, x0 + width, y0, x0 + width, y0 + height, color);
    bitmap_draw_line(bitmap, x0, y0 + height, x0 + width, y0 + height, color);
}

void bitmap_draw_circle_filled(Bitmap *bitmap, int x0, int y0, int radius, uint8_t color) {
    for (int y = y0 - radius; y <= y0 + radius; y++) {
        for (int x = x0 - radius; x <= x0 + radius; x++) {
            if (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) <= radius) {
                bitmap_set_pixel(bitmap, x, y, color);
            }
        }
    }
}

void bitmap_save(Bitmap *bitmap, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P5\n%d %d\n255\n", bitmap->width, bitmap->height);
    fwrite(bitmap->pixels, 1, bitmap->width * bitmap->height, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <outputfile>\n", argv[0]);
        return 1;
    }

    Bitmap *bitmap = bitmap_new(640, 480);
    bitmap_draw_rectangle(bitmap, 0, 0, bitmap->width, bitmap->height, 0);
    bitmap_draw_circle(bitmap, bitmap->width / 2, bitmap->height / 2, 100, 255);
    bitmap_draw_line(bitmap, 0, 0, bitmap->width, bitmap->height, 255);
    bitmap_draw_line(bitmap, bitmap->width, 0, 0, bitmap->height, 255);
    bitmap_draw_triangle(bitmap, bitmap->width / 2, bitmap->height / 2, bitmap->width / 2 + 100, bitmap->height / 2, bitmap->width / 2, bitmap->height / 2 + 100, 255);
    bitmap_draw_circle_filled(bitmap, 200, 200, 50, 255);

    bitmap_save(bitmap, argv[1]);
    bitmap_free(bitmap);

    return 0;
}