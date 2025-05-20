//FormAI DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITERATIONS 1000

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel** createPixelArray(int width, int height) {
    Pixel** array = (Pixel**) malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; ++i) {
        array[i] = (Pixel*) malloc(width * sizeof(Pixel));
    }
    return array;
}

void destroyPixelArray(Pixel** array, int height) {
    for (int i = 0; i < height; ++i) {
        free(array[i]);
    }
    free(array);
}

void setColor(Pixel* pixel, int i) {
    switch (i % 7) {
        case 0:
            pixel->r = 255;
            pixel->g = 0;
            pixel->b = 0;
            break;
        case 1:
            pixel->r = 255;
            pixel->g = 127;
            pixel->b = 0;
            break;
        case 2:
            pixel->r = 255;
            pixel->g = 255;
            pixel->b = 0;
            break;
        case 3:
            pixel->r = 0;
            pixel->g = 255;
            pixel->b = 0;
            break;
        case 4:
            pixel->r = 0;
            pixel->g = 0;
            pixel->b = 255;
            break;
        case 5:
            pixel->r = 75;
            pixel->g = 0;
            pixel->b = 130;
            break;
        case 6:
            pixel->r = 148;
            pixel->g = 0;
            pixel->b = 211;
            break;
    }
}

void generateFractal(Pixel** pixels) {
    double center_x = -0.75;
    double center_y = 0;
    double zoom = 0.005;
    double r, i, zr, zi, new_zr;
    int iterations;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            r = center_x + ((double)(x - WIDTH/2)/(double)(WIDTH/2))*zoom;
            i = center_y + ((double)(y - HEIGHT/2)/(double)(HEIGHT/2))*zoom;
            zr = r;
            zi = i;
            iterations = 0;
            while ((zr*zr + zi*zi < 4) && (iterations < MAX_ITERATIONS)) {
                new_zr = zr*zr - zi*zi + r;
                zi = 2*zr*zi + i;
                zr = new_zr;
                ++iterations;
            }
            setColor(&pixels[y][x], iterations);
        }
    }
}

int main() {
    Pixel** pixels = createPixelArray(WIDTH, HEIGHT);
    generateFractal(pixels);
    FILE* fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            fwrite(&(pixels[y][x]), sizeof(Pixel), 1, fp);
        }
    }
    fclose(fp);
    destroyPixelArray(pixels, HEIGHT);
    return 0;
}