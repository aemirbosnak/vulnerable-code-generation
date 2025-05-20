//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64

void generate_pixel(int *image, int x, int y) {
    int r, g, b;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
    image[(y * WIDTH) + x] = r << 16 | g << 8 | b;
}

int main() {
    int seed;
    int *image;
    int i, j;

    seed = time(NULL);
    srand(seed);

    image = malloc(WIDTH * HEIGHT * sizeof(int));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            generate_pixel(image, j, i);
        }
    }

    FILE *fp;
    fp = fopen("output.bmp", "wb");

    fputc('B', fp);
    fputc('M', fp);

    fputc(14 + 10, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(54, fp);

    fputc(40, fp);

    fputc(WIDTH, fp);
    fputc(HEIGHT, fp);
    fputc(1, fp);
    fputc(24, fp);

    int padding = (3 * (WIDTH * HEIGHT)) % 4;
    fputc(padding, fp);
    fputc(padding, fp);
    fputc(padding, fp);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int pixel = image[(i * WIDTH) + j];
            fputc(BGR2BMP(pixel), fp);
            fputc(BGR2BMP(pixel), fp);
            fputc(BGR2BMP(pixel), fp);
        }
        fputc(padding, fp);
    }

    fclose(fp);
    free(image);

    return 0;
}

int BGR2BMP(int bgr) {
    int b = bgr & 0xFF;
    int g = (bgr & 0xFF00) >> 8;
    int r = (bgr & 0xFF0000) >> 16;
    return (r << 11) | (g << 5) | b;
}