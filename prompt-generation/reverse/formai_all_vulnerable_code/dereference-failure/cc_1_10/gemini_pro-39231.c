//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    unsigned char r, g, b, a;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(sizeof(Pixel) * width * height);
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
        return (Pixel){0, 0, 0, 0};
    }
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    Image *image = create_image(WIDTH, HEIGHT);

    // Draw a circle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int dx = x - WIDTH / 2;
            int dy = y - HEIGHT / 2;
            if (dx * dx + dy * dy < WIDTH * WIDTH / 4) {
                set_pixel(image, x, y, (Pixel){255, 0, 0, 255});
            }
        }
    }

    save_image(image, "circle.ppm");
    destroy_image(image);

    return 0;
}