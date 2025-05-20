//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 192
#define PALETTE_SIZE 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);
    image->width = width;
    image->height = height;
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    int index = (y * image->width + x) * 3;
    image->data[index + 0] = color.r;
    image->data[index + 1] = color.g;
    image->data[index + 2] = color.b;
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Color){0, 0, 0};
    }
    int index = (y * image->width + x) * 3;
    return (Color){image->data[index + 0], image->data[index + 1], image->data[index + 2]};
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double r = (double)x / WIDTH;
            double g = (double)y / HEIGHT;
            double b = (r + g) / 2;
            set_pixel(image, x, y, (Color){(unsigned char)(r * 255), (unsigned char)(g * 255), (unsigned char)(b * 255)});
        }
    }

    save_image(image, "gradient.ppm");
    free_image(image);

    return 0;
}