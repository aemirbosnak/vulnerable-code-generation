//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 768
#define PIXEL_SIZE 1
#define PALETTE_SIZE 256

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

typedef struct {
    unsigned int width;
    unsigned int height;
    Color* pixels;
} Image;

Image* create_image(unsigned int width, unsigned int height) {
    Image* image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Color*)malloc(sizeof(Color) * width * height);
    return image;
}

void destroy_image(Image* image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image* image, unsigned int x, unsigned int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Color get_pixel(Image* image, unsigned int x, unsigned int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Color){0, 0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    Image* image = create_image(WIDTH, HEIGHT);

    // Draw a circle
    for (unsigned int y = 0; y < HEIGHT; y++) {
        for (unsigned int x = 0; x < WIDTH; x++) {
            int dx = (int)x - WIDTH / 2;
            int dy = (int)y - HEIGHT / 2;
            if (dx * dx + dy * dy < WIDTH * WIDTH / 4) {
                set_pixel(image, x, y, (Color){255, 255, 255, 255});
            }
        }
    }

    // Draw a rectangle
    for (unsigned int y = 0; y < HEIGHT / 2; y++) {
        for (unsigned int x = 0; x < WIDTH / 2; x++) {
            set_pixel(image, x, y, (Color){0, 0, 255, 255});
        }
    }

    // Draw a triangle
    for (unsigned int y = 0; y < HEIGHT / 2; y++) {
        for (unsigned int x = 0; x < WIDTH / 2 - y; x++) {
            set_pixel(image, x, y, (Color){0, 255, 0, 255});
        }
    }

    // Draw a line
    for (unsigned int y = 0; y < HEIGHT; y++) {
        set_pixel(image, WIDTH / 2, y, (Color){255, 0, 0, 255});
    }

    // Save the image
    save_image(image, "output.ppm");

    // Destroy the image
    destroy_image(image);

    return 0;
}