//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char *pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, char color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

char get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1) {
            break;
        }
        int e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius, char color) {
    int x0 = x, y0 = y + radius;
    int dx = 1, dy = -1;
    int err = dx - (radius << 1);
    while (x0 <= y0) {
        set_pixel(image, x0, y0, color);
        set_pixel(image, x0, y, color);
        set_pixel(image, -x0, y0, color);
        set_pixel(image, -x0, y, color);
        set_pixel(image, y0, x0, color);
        set_pixel(image, y0, -x0, color);
        set_pixel(image, -y0, x0, color);
        set_pixel(image, -y0, -x0, color);
        int e2 = 2 * err;
        if (e2 <= dy) {
            y0--;
            err += dy;
            dy += 2;
        }
        if (e2 >= dx) {
            x0++;
            err += dx;
            dx += 2;
        }
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height, char color) {
    for (int i = 0; i < width; i++) {
        set_pixel(image, x + i, y, color);
        set_pixel(image, x + i, y + height - 1, color);
    }
    for (int i = 0; i < height; i++) {
        set_pixel(image, x, y + i, color);
        set_pixel(image, x + width - 1, y + i, color);
    }
}

void draw_triangle(Image *image, int x0, int y0, int x1, int y1, int x2, int y2, char color) {
    draw_line(image, x0, y0, x1, y1, color);
    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y2, x0, y0, color);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }
    fprintf(file, "P1\n%d %d\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%d ", get_pixel(image, x, y));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image *image = create_image(500, 500);

    draw_line(image, 10, 10, 490, 10, 255);
    draw_line(image, 10, 10, 10, 490, 255);
    draw_line(image, 490, 10, 490, 490, 255);
    draw_line(image, 10, 490, 490, 490, 255);

    draw_circle(image, 250, 250, 100, 255);

    draw_rectangle(image, 100, 100, 200, 200, 255);

    draw_triangle(image, 100, 400, 250, 100, 400, 100, 255);

    save_image(image, "image.pbm");

    destroy_image(image);

    return 0;
}