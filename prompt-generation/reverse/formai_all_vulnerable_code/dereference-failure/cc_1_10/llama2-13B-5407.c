//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char red, green, blue;
} RGB;

typedef struct {
    RGB pixels[HEIGHT * WIDTH];
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fread(&image->pixels[i * WIDTH + j].red, 1, 1, file);
            fread(&image->pixels[i * WIDTH + j].green, 1, 1, file);
            fread(&image->pixels[i * WIDTH + j].blue, 1, 1, file);
        }
    }

    fclose(file);
    return image;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2) {
    int i, j;

    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->pixels[i * HEIGHT + j].red = 255;
            image->pixels[i * HEIGHT + j].green = 0;
            image->pixels[i * HEIGHT + j].blue = 0;
        }
    }
}

void draw_rectangle(Image *image, int x, int y, int width, int height) {
    int i, j;

    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            image->pixels[i * HEIGHT + j].red = 255;
            image->pixels[i * HEIGHT + j].green = 0;
            image->pixels[i * HEIGHT + j].blue = 0;
        }
    }
}

void draw_circle(Image *image, int x, int y, int radius) {
    int i, j;
    int x_offs = radius * cos(M_PI / 180 * 30);
    int y_offs = radius * sin(M_PI / 180 * 30);

    for (i = x - x_offs; i <= x + x_offs; i++) {
        for (j = y - y_offs; j <= y + y_offs; j++) {
            if (sqrt((i - x) * (i - x) + (j - y) * (j - y)) < radius) {
                image->pixels[i * HEIGHT + j].red = 255;
                image->pixels[i * HEIGHT + j].green = 0;
                image->pixels[i * HEIGHT + j].blue = 0;
            }
        }
    }
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fwrite(&image->pixels[i * WIDTH + j].red, 1, 1, file);
            fwrite(&image->pixels[i * WIDTH + j].green, 1, 1, file);
            fwrite(&image->pixels[i * WIDTH + j].blue, 1, 1, file);
        }
    }

    fclose(file);
}

int main() {
    Image *image = load_image("image.bmp");
    draw_line(image, 100, 100, 200, 200);
    draw_rectangle(image, 50, 50, 100, 100);
    draw_circle(image, 150, 150, 50);
    save_image(image, "output.bmp");
    return 0;
}