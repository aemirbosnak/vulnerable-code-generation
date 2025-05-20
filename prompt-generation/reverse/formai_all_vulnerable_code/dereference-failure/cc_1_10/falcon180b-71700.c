//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

// Define the color palette
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define ORANGE 6
#define CYAN 7
#define MAGENTA 8
#define PINK 9

int main() {
    FILE *fp;
    int x, y, i, j, k, iter, color;
    unsigned char *pixels;
    char filename[1024];

    // Initialize the image
    pixels = (unsigned char*) malloc(WIDTH * HEIGHT * 3);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i * 3] = BLACK;
        pixels[i * 3 + 1] = BLACK;
        pixels[i * 3 + 2] = BLACK;
    }

    // Generate the fractal
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            iter = 0;
            while (iter < MAX_ITER) {
                k = x * (y * 10000.0 + iter) / (WIDTH * HEIGHT);
                color = (k % 9) + 1;
                if (color == WHITE)
                    break;
                iter++;
            }
            pixels[(y * WIDTH + x) * 3] = (color - 1) * 36;
            pixels[(y * WIDTH + x) * 3 + 1] = (color - 1) * 6;
            pixels[(y * WIDTH + x) * 3 + 2] = (color - 1) * 6;
        }
    }

    // Save the image to a file
    sprintf(filename, "fractal.png");
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fwrite(pixels, 3, WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Done!\n");
    return 0;
}