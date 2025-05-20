//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    Color **pixels;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(sizeof(Color *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(Color) * width);
    }
    return image;
}

void destroy_image(Image *image) {
    for (int i = 0; i < image->pixels; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    image->pixels[y][x] = color;
}

Color get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return (Color){0, 0, 0};
    }
    return image->pixels[y][x];
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color = get_pixel(image, x, y);
            fprintf(fp, "%d %d %d ", color.r, color.g, color.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    Image *image = create_image(WIDTH, HEIGHT);

    // Draw a nice ASCII smiley face
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x >= WIDTH / 2 - 100 && x <= WIDTH / 2 + 100 && y >= HEIGHT / 2 - 100 && y <= HEIGHT / 2 + 100) {
                set_pixel(image, x, y, (Color){255, 255, 0});
            } else if (x >= WIDTH / 2 - 50 && x <= WIDTH / 2 + 50 && y >= HEIGHT / 2 - 50 && y <= HEIGHT / 2 + 50) {
                set_pixel(image, x, y, (Color){0, 0, 0});
            }
        }
    }

    // Save the image to a file
    save_image(image, "smiley.ppm");

    // Destroy the image
    destroy_image(image);

    return 0;
}