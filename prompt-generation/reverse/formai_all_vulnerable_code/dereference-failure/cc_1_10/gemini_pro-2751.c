//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    image->data = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, char color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->data[y * image->width + x] = color;
}

char get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }
    return image->data[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 - x1) / dx;
    int sy = (y2 - y1) / dy;
    int err = dx - dy;
    while (x1 != x2 || y1 != y2) {
        set_pixel(image, x1, y1, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius, char color) {
    int x0 = x - radius;
    int y0 = y - radius;
    int x1 = x + radius;
    int y1 = y + radius;
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int err = dx - dy;
    while (x0 != x1 || y0 != y1) {
        set_pixel(image, x0, y0, color);
        set_pixel(image, x0, y1, color);
        set_pixel(image, x1, y0, color);
        set_pixel(image, x1, y1, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0++;
            x1--;
        }
        if (e2 < dx) {
            err += dx;
            y0++;
            y1--;
        }
    }
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    for (int x = x1; x <= x2; x++) {
        set_pixel(image, x, y1, color);
        set_pixel(image, x, y2, color);
    }
    for (int y = y1; y <= y2; y++) {
        set_pixel(image, x1, y, color);
        set_pixel(image, x2, y, color);
    }
}

void draw_text(Image *image, int x, int y, char *text, char color) {
    int i = 0;
    while (text[i] != '\0') {
        int char_width = 8;
        int char_height = 8;
        for (int j = 0; j < char_width; j++) {
            for (int k = 0; k < char_height; k++) {
                int bit = (text[i] >> (7 - j)) & 1;
                if (bit) {
                    set_pixel(image, x + j, y + k, color);
                }
            }
        }
        x += char_width;
        i++;
    }
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, sizeof(char), image->width * image->height, file);
    fclose(file);
}

int main() {
    Image *image = create_image(640, 480);
    draw_line(image, 0, 0, 640, 480, 255);
    draw_line(image, 0, 480, 640, 0, 255);
    draw_circle(image, 320, 240, 100, 255);
    draw_rectangle(image, 100, 100, 200, 200, 255);
    draw_text(image, 100, 300, "Hello, world!", 255);
    save_image(image, "output.pbm");
    destroy_image(image);
    return 0;
}