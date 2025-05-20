//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while (x0 != x1 || y0 != y1) {
        image->data[y0 * image->width + x0] = c;
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

void draw_circle(Image *image, int x0, int y0, int radius, char c) {
    int x = radius;
    int y = 0;
    int err = 0;
    while (x >= y) {
        image->data[(y0 + y) * image->width + (x0 + x)] = c;
        image->data[(y0 + y) * image->width + (x0 - x)] = c;
        image->data[(y0 - y) * image->width + (x0 + x)] = c;
        image->data[(y0 - y) * image->width + (x0 - x)] = c;
        image->data[(y0 + x) * image->width + (x0 + y)] = c;
        image->data[(y0 + x) * image->width + (x0 - y)] = c;
        image->data[(y0 - x) * image->width + (x0 + y)] = c;
        image->data[(y0 - x) * image->width + (x0 - y)] = c;
        y++;
        err += 1 + 2 * y;
        if (2 * (err - x) + 1 > 0) {
            x--;
            err -= 1 + 2 * x;
        }
    }
}

void draw_smiley(Image *image, int x, int y, int radius) {
    draw_circle(image, x, y, radius, '*');
    draw_circle(image, x - radius / 2, y - radius / 4, radius / 10, '*');
    draw_circle(image, x + radius / 2, y - radius / 4, radius / 10, '*');
    draw_line(image, x - radius / 2, y + radius / 4, x + radius / 2, y + radius / 4, '*');
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P1\n%d %d\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%c", image->data[y * image->width + x]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image *image = create_image(200, 100);
    draw_smiley(image, 100, 50, 25);
    save_image(image, "smiley.pbm");
    free_image(image);
    return 0;
}