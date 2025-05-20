//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void fill(Pixel **pixels, Pixel color) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x] = color;
        }
    }
}

void swap(Pixel *a, Pixel *b) {
    Pixel temp = *a;
    *a = *b;
    *b = temp;
}

void mirror_vertical(Pixel **pixels) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH/2; ++x) {
            swap(&pixels[y][x], &pixels[y][WIDTH-x-1]);
        }
    }
}

void mirror_horizontal(Pixel **pixels) {
    for (int y = 0; y < HEIGHT/2; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            swap(&pixels[y][x], &pixels[HEIGHT-y-1][x]);
        }
    }
}

void invert_colors(Pixel **pixels) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x].r = 255 - pixels[y][x].r;
            pixels[y][x].g = 255 - pixels[y][x].g;
            pixels[y][x].b = 255 - pixels[y][x].b;
        }
    }
}

void filter_noise(Pixel **pixels) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            unsigned char random = rand()%50;
            pixels[y][x].r += random;
            pixels[y][x].g += random;
            pixels[y][x].b += random;
        }
    }
}

int main(int argc, char const *argv[]) {
    Pixel **pixels = malloc(HEIGHT * sizeof(Pixel*));
    for (int y = 0; y < HEIGHT; ++y) {
        pixels[y] = malloc(WIDTH * sizeof(Pixel));
    }

    // Fill with red color
    Pixel red = {255, 0, 0};
    fill(pixels, red);

    // Add vertical mirror effect
    mirror_vertical(pixels);

    // Add blue color to the image
    Pixel blue = {0, 0, 255};
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x].r *= 0.8;
            pixels[y][x].b += blue.b;
        }
    }

    // Add horizontal mirror effect
    mirror_horizontal(pixels);

    // Add green color to the image
    Pixel green = {0, 255, 0};
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x].r += green.r;
            pixels[y][x].g *= 0.8;
        }
    }

    // Add invert colors effect
    invert_colors(pixels);

    // Add noise filter effect
    filter_noise(pixels);

    // Write image to file
    FILE *file = fopen("output.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y<HEIGHT; ++y) {
        fwrite(pixels[y], sizeof(Pixel), WIDTH, file);
    }
    fclose(file);

    // De-allocate memory
    for (int y = 0; y < HEIGHT; ++y) {
        free(pixels[y]);
    }
    free(pixels);

    return 0;
}