//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define WIDTH 10
#define HEIGHT 10
#define MAX_ITERATIONS 100
#define PIXEL_SIZE 3

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} pixel;

pixel **pixels;

void generate_fractal(int x, int y, int iteration) {
    double zx = 0;
    double zy = 0;

    while (iteration > 0 && zx * zx + zy * zy < 4) {
        double temp_zx = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = temp_zx;

        if (iteration > MAX_ITERATIONS) {
            pixels[x + y][0] = (pixel){x, y, rand() % 256, rand() % 256, rand() % 256};
            return;
        }

        iteration--;
    }

    pixels[x + y][0] = (pixel){x, y, 0, 0, 0}; // Set background color if it reaches the limit
}

int main() {
    srand(time(NULL));
    pixels = malloc(WIDTH * HEIGHT * sizeof(pixel *));

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i] = calloc(1, sizeof(pixel));
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            generate_fractal(x, y, MAX_ITERATIONS);
        }
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        for (int j = 0; j < PIXEL_SIZE; j++) {
            int x = i % WIDTH;
            int y = i / WIDTH;

            if (j == 0) {
                printf("\033[%d;%d;1m%d,%d: (%d,%d) R:%d G:%d B:%d\n", y + 1, x + 1, pixels[i][0].x, pixels[i][0].y, pixels[i][0].x, pixels[i][0].y, pixels[i][0].r, pixels[i][0].g, pixels[i][0].b);
            }

            int red = pixels[i][0].r + (rand() % PIXEL_SIZE);
            int green = pixels[i][0].g + (rand() % PIXEL_SIZE);
            int blue = pixels[i][0].b + (rand() % PIXEL_SIZE);

            if (red > 255) red %= 256;
            if (green > 255) green %= 256;
            if (blue > 255) blue %= 256;

            printf("\033[%d;%dH\033[%dm%dm%dm\033[0m", y + 1, x + 1, 31, red, green);
            usleep(50000); // Delay to avoid flickering
        }
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}