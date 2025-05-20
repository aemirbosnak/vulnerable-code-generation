//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int x = x0, y = y0;

    while (1) {
        image->data[y * image->width + x] = '*';
        if (x == x1 && y == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x += sx; }
        if (e2 < dy) { err += dx; y += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int x0 = 0, y0 = radius;
    int err = 0;

    while (x0 <= y0) {
        image->data[(y - y0) * image->width + (x + x0)] = '*';
        image->data[(y - y0) * image->width + (x - x0)] = '*';
        image->data[(y + y0) * image->width + (x + x0)] = '*';
        image->data[(y + y0) * image->width + (x - x0)] = '*';
        image->data[(y - x0) * image->width + (x + y0)] = '*';
        image->data[(y - x0) * image->width + (x - y0)] = '*';
        image->data[(y + x0) * image->width + (x + y0)] = '*';
        image->data[(y + x0) * image->width + (x - y0)] = '*';

        err += 1 + 2 * x0;
        if (err > 0) {
            y0--;
            err -= 2 * y0 + 1;
        }
        x0++;
    }
}

void draw_text(Image *image, char *text, int x, int y) {
    int i, j, k, l;
    char *font[] = {
        "  ***   ***  *******  ***   *   ***   *  ***    *     *  ",
        " *    *  *   * *     * *   * *   *    *  *        *     * ",
        " *    *  *   * *     * *   * *   *    *  *        *     * ",
        "  ***   *   * *******  *   * *   ***   *  ***    *     *  ",
        "        *   * *        *   * *   *       *        *     * ",
        "        *   * *        *   * *   *       *        *     * ",
        "  ***   ******* *******  ***   *******  *  ***    *******  ",
        " *    * *       *     * *   * *       *  *        *     * ",
        " *    * *       *     * *   * *       *  *        *     * ",
        "  ***   *       *******  ***   *******  *  ***    *     *  ",
        "        *       *     * *   * *       *  *        *     * ",
        "        *       *     * *   * *       *  *        *     * ",
        "  ***    ******* *******  ***   *******  *  ***    *******  ",
        " *    *  *   * *     * *   * *   *    *  *        *     * ",
        " *    *  *   * *     * *   * *   *    *  *        *     * ",
        "  ***   *   * *******  *   * *   ***   *  ***    *     *  ",
        " *    * *   * *        *   * *   *       *        *     * ",
        " *    * *   * *        *   * *   *       *        *     * ",
        "  ***    ***  *******  ***   *   ***   *  ***    *******  ",
        " *    * *   * *        *   * *   *    *  *        *     * ",
        " *    * *   * *        *   * *   *    *  *        *     * ",
        "  ***   *   * *******  *   * *   ***   *  ***    *     *  ",
        "        *   * *     * *   * *   *       *        *     * ",
        "        *   * *     * *   * *   *       *        *     * ",
        "  ***   ******* *******  ***   *******  *  ***    *******  ",
        " *    * *       *     * *   * *       *  *        *     * ",
        " *    * *       *     * *   * *       *  *        *     * ",
    };

    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < 25; j++) {
            for (k = 0; k < 7; k++) {
                for (l = 0; l < 8; l++) {
                    if (font[j][k * 8 + l] == '*') {
                        image->data[(y + j) * image->width + (x + i * 8 + l)] = '*';
                    }
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);

    draw_line(image, 10, 10, 70, 10);
    draw_line(image, 10, 10, 10, 70);
    draw_line(image, 70, 10, 70, 70);
    draw_line(image, 10, 70, 70, 70);

    draw_circle(image, 40, 40, 20);

    draw_text(image, "Hello, world!", 20, 20);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            putchar(image->data[y * image->width + x]);
        }
        putchar('\n');
    }

    free_image(image);
    return 0;
}