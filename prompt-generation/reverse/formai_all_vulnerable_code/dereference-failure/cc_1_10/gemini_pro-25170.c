//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(char) * width);
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    while (x0 != x1 || y0 != y1) {
        image->pixels[y0][x0] = c;
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

void draw_circle(Image *image, int x, int y, int radius, char c) {
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x_ = 0;
    int y_ = radius;
    image->pixels[y][x] = c;
    image->pixels[y][x + 2 * radius] = c;
    image->pixels[y + 2 * radius][x] = c;
    image->pixels[y + 2 * radius][x + 2 * radius] = c;
    while (x_ < y_) {
        if (f >= 0) {
            y_--;
            ddF_y += 2;
            f += ddF_y;
        }
        x_++;
        ddF_x += 2;
        f += ddF_x;
        image->pixels[y + y_][x + x_] = c;
        image->pixels[y + y_][x - x_] = c;
        image->pixels[y - y_][x + x_] = c;
        image->pixels[y - y_][x - x_] = c;
        image->pixels[y + x_][x + y_] = c;
        image->pixels[y + x_][x - y_] = c;
        image->pixels[y - x_][x + y_] = c;
        image->pixels[y - x_][x - y_] = c;
    }
}

void draw_text(Image *image, int x, int y, char *text, char c) {
    int i = 0;
    while (text[i] != '\0') {
        int width = 8;
        int height = 12;
        char *font[] = {
            "  ..  ",
            " | |  ",
            " | |  ",
            " | |  ",
            " | |  ",
            " | |  ",
            " | |  ",
            "  ..  ",
        };
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                image->pixels[y + j][x + i * width + k] = font[j][k];
            }
        }
        i++;
    }
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image *image = new_image(MAX_WIDTH, 50);
    draw_line(image, 0, 0, MAX_WIDTH - 1, 0, '-');
    draw_line(image, 0, 0, 0, 50 - 1, '|');
    draw_line(image, MAX_WIDTH - 1, 0, MAX_WIDTH - 1, 50 - 1, '|');
    draw_line(image, 0, 50 - 1, MAX_WIDTH - 1, 50 - 1, '-');
    draw_circle(image, MAX_WIDTH / 2, 25, 20, '@');
    draw_text(image, 10, 10, "Hello, world!", '&');
    print_image(image);
    free_image(image);
    return 0;
}