//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    RGB *pixels;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(width * height * sizeof(RGB));
    image->width = width;
    image->height = height;
    return image;
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, RGB color) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) return;
    image->pixels[y * image->width + x] = color;
}

RGB get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) return (RGB){0, 0, 0};
    return image->pixels[y * image->width + x];
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(RGB), image->width * image->height, fp);
    fclose(fp);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a gradient from black to white
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            RGB color = {
                .r = (unsigned char)((float)x / WIDTH * 255),
                .g = (unsigned char)((float)y / HEIGHT * 255),
                .b = (unsigned char)((float)(x + y) / (WIDTH + HEIGHT) * 255),
            };
            set_pixel(image, x, y, color);
        }
    }

    // Draw a circle
    int cx = WIDTH / 2;
    int cy = HEIGHT / 2;
    int r = 100;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int dx = x - cx;
            int dy = y - cy;
            if (dx * dx + dy * dy <= r * r) {
                set_pixel(image, x, y, (RGB){255, 255, 255});
            }
        }
    }

    // Draw a line
    int x1 = 100;
    int y1 = 100;
    int x2 = 700;
    int y2 = 500;
    float dx = (float)(x2 - x1) / (y2 - y1);
    for (int y = y1; y <= y2; y++) {
        int x = x1 + (y - y1) * dx;
        set_pixel(image, x, y, (RGB){255, 0, 0});
    }

    // Save the image
    save_image(image, "output.ppm");

    free_image(image);

    return 0;
}