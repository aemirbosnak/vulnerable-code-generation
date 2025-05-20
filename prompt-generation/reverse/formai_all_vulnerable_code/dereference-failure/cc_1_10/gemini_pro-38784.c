//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char **data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            image->data[i][j] = ' ';
        }
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;
    while (1) {
        image->data[y0][x0] = c;
        if (x0 == x1 && y0 == y1) {
            break;
        }
        e2 = 2 * err;
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
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (y >= x) {
        image->data[y0 + y][x0 + x] = c;
        image->data[y0 + y][x0 - x] = c;
        image->data[y0 - y][x0 + x] = c;
        image->data[y0 - y][x0 - x] = c;
        image->data[y0 + x][x0 + y] = c;
        image->data[y0 + x][x0 - y] = c;
        image->data[y0 - x][x0 + y] = c;
        image->data[y0 - x][x0 - y] = c;
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Image *image = create_image(32, 32);

    draw_circle(image, 16, 16, 10, '0');
    draw_line(image, 10, 16, 22, 16, '1');
    draw_line(image, 16, 10, 16, 22, '2');

    print_image(image);

    destroy_image(image);

    return 0;
}