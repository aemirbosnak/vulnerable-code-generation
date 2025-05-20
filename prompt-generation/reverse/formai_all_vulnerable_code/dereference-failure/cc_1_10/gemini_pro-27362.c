//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(width * height * sizeof(Pixel));
    image->width = width;
    image->height = height;
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }
    image->pixels[y * image->width + x] = color;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return (Pixel){0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

int main() {
    Image *image = create_image(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double dx = (x - WIDTH / 2) / (double)WIDTH;
            double dy = (y - HEIGHT / 2) / (double)HEIGHT;
            double r = sqrt(dx * dx + dy * dy);
            double theta = atan2(dy, dx);

            Pixel color;
            if (r < 0.5) {
                color.r = 255 * r * 2;
                color.g = 255 * (1 - r) * 2;
                color.b = 0;
            } else if (r < 1.0) {
                color.r = 255 * (1 - r) * 2;
                color.g = 0;
                color.b = 255 * r * 2;
            } else {
                color.r = 0;
                color.g = 255 * (r - 1) * 2;
                color.b = 255 * (1 - r) * 2;
            }

            set_pixel(image, x, y, color);
        }
    }

    save_image(image, "output.ppm");
    destroy_image(image);

    return 0;
}