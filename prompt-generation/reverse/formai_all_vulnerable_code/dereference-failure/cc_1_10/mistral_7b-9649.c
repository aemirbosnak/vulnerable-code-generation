//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 256

typedef struct {
    int x, y;
} point;

typedef struct {
    float r, g, b;
} color;

typedef struct {
    int width, height;
    color **pixels;
} image;

image create_image(int width, int height) {
    image img;
    img.width = width;
    img.height = height;
    img.pixels = malloc(height * sizeof(color *));
    for (int i = 0; i < height; i++) {
        img.pixels[i] = calloc(width, sizeof(color));
    }
    return img;
}

void free_image(image img) {
    for (int i = 0; i < img.height; i++) {
        free(img.pixels[i]);
    }
    free(img.pixels);
}

void set_pixel(image img, int x, int y, color c) {
    img.pixels[y][x] = c;
}

color get_pixel(image img, int x, int y) {
    return img.pixels[y][x];
}

color random_color() {
    color c;
    c.r = rand() % MAX_COLOR;
    c.g = rand() % MAX_COLOR;
    c.b = rand() % MAX_COLOR;
    return c;
}

point random_point(int width, int height) {
    point p;
    p.x = rand() % width;
    p.y = rand() % height;
    return p;
}

void generate_pixel_art(image img) {
    color c;
    point p;
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            p = random_point(img.width, img.height);
            c = get_pixel(img, p.x, p.y);
            set_pixel(img, x, y, c);
        }
    }
}

int main() {
    image img = create_image(WIDTH, HEIGHT);
    generate_pixel_art(img);

    // Display the generated image here or save it to a file.

    free_image(img);
    return 0;
}