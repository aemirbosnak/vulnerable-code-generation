//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    memset(image->data, ' ', width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char c) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = c;
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    while (1) {
        set_pixel(image, x0, y0, c);
        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_text(Image *image, int x, int y, const char *text, char c) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        set_pixel(image, x + i, y, text[i]);
    }
}

void print_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%c", image->data[i * image->width + j]);
        }
        printf("\n");
    }
}

int main(void) {
    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);
    draw_text(image, 10, 10, "Hello, world!", '*');
    draw_line(image, 0, 0, MAX_WIDTH - 1, MAX_HEIGHT - 1, '-');
    draw_line(image, MAX_WIDTH - 1, 0, 0, MAX_HEIGHT - 1, '-');
    print_image(image);
    destroy_image(image);
    return 0;
}