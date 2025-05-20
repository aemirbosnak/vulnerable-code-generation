//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color *data;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Color));
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
    image->data[y * image->width + x] = color;
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Color) {0, 0, 0};
    }
    return image->data[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * sizeof(Color), fp);
    fclose(fp);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Generate a gradient from red to blue
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float t = (float)x / WIDTH;
            Color color = {255 * t, 0, 255 * (1 - t)};
            set_pixel(image, x, y, color);
        }
    }

    // Save the image to a file
    save_image(image, "gradient.ppm");

    free_image(image);

    return 0;
}