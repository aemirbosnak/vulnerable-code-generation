//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
        memset(image->pixels[i], ' ', width);
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
        image->pixels[y][x] = c;
    }
}

void draw_line(Image *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        set_pixel(image, x0, y0, '*');
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

void draw_circle(Image *image, int x, int y, int radius) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;

    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                set_pixel(image, i, j, '*');
            }
        }
    }
}

void draw_text(Image *image, int x, int y, const char *text) {
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        char c = text[i];
        int width = 5;
        int height = 7;
        char *glyph = "  **   \n ** **  \n ** **  \n ****** \n **  ** \n **  ** \n  **  ";

        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
                set_pixel(image, x + i * width + j, y + k, glyph[k * width + j]);
            }
        }
    }
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        printf("%s\n", image->pixels[i]);
    }
}

int main() {
    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);

    draw_line(image, 0, 0, MAX_WIDTH - 1, MAX_HEIGHT - 1);
    draw_circle(image, MAX_WIDTH / 2, MAX_HEIGHT / 2, 10);
    draw_text(image, 10, 10, "Hello, world!");

    print_image(image);

    destroy_image(image);

    return 0;
}