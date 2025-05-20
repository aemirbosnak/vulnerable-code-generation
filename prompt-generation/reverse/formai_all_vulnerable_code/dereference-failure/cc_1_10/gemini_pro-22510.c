//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width, height;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = calloc(width * height, sizeof(char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) return;
    image->data[y * image->width + x] = c;
}

char get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) return ' ';
    return image->data[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, char c) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;

    while (1) {
        set_pixel(image, x1, y1, c);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err;

        if (e2 > -dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

void draw_circle(Image *image, int x, int y, int radius, char c) {
    int x1 = 0, y1 = radius;
    int ddF_x = 0, ddF_y = -2 * radius;
    int F = -radius;

    while (x1 < y1) {
        set_pixel(image, x + x1, y + y1, c);
        set_pixel(image, x - x1, y + y1, c);
        set_pixel(image, x + x1, y - y1, c);
        set_pixel(image, x - x1, y - y1, c);

        F += ddF_x; ddF_x += 2;
        if (F > 0) { y1--; ddF_y += 2; F += ddF_y; }
        x1++;
    }
}

void save_ppm(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    Image *image = new_image(width, height);

    draw_line(image, 0, 0, width - 1, height - 1, '*');
    draw_line(image, 0, height - 1, width - 1, 0, '*');
    draw_circle(image, width / 2, height / 2, width / 4, '*');

    save_ppm(image, argv[1]);
    free_image(image);

    return 0;
}