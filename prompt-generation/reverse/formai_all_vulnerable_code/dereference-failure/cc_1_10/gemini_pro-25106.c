//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color **pixels;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(sizeof(Color *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(Color) * width);
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < HEIGHT; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    image->pixels[y][x] = color;
}

Color get_pixel(Image *image, int x, int y) {
    return image->pixels[y][x];
}

void save_ppm(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color = get_pixel(image, x, y);
            fputc(color.r, fp);
            fputc(color.g, fp);
            fputc(color.b, fp);
        }
    }
    fclose(fp);
}

int main() {
    Image *image = new_image(WIDTH, HEIGHT);

    // Draw a circle
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int dx = x - WIDTH / 2;
            int dy = y - HEIGHT / 2;
            if (dx * dx + dy * dy < WIDTH * WIDTH / 4) {
                set_pixel(image, x, y, (Color) {255, 255, 255});
            }
        }
    }

    // Save the image
    save_ppm(image, "circle.ppm");

    // Free the image
    free_image(image);

    return 0;
}