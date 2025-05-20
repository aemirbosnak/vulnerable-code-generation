//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    fprintf(file, "P5\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");
    fwrite(image->data, image->width * image->height, 1, file);
    fclose(file);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) {
        image->data[y0 * image->width + x0] = 255;
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(Image *image, int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        image->data[(yc + y) * image->width + (xc + x)] = 255;
        image->data[(yc + y) * image->width + (xc - x)] = 255;
        image->data[(yc - y) * image->width + (xc + x)] = 255;
        image->data[(yc - y) * image->width + (xc - x)] = 255;
        image->data[(yc + x) * image->width + (xc + y)] = 255;
        image->data[(yc + x) * image->width + (xc - y)] = 255;
        image->data[(yc - x) * image->width + (xc + y)] = 255;
        image->data[(yc - x) * image->width + (xc - y)] = 255;

        if (d < 0) d += 4 * x + 6;
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void draw_rectangle(Image *image, int x0, int y0, int x1, int y1) {
    for (int y = y0; y <= y1; y++) {
        for (int x = x0; x <= x1; x++) {
            image->data[y * image->width + x] = 255;
        }
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2) {
    draw_line(image, x0, y0, x1, y1);
    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x2, y2, x0, y0);
}

int main() {
    Image *image = create_image(512, 512);

    draw_line(image, 0, 0, 511, 511);
    draw_line(image, 0, 511, 511, 0);
    draw_circle(image, 256, 256, 128);
    draw_rectangle(image, 100, 100, 400, 400);
    draw_triangle(image, 100, 100, 400, 100, 256, 400);

    save_image(image, "image.pgm");
    destroy_image(image);

    return 0;
}