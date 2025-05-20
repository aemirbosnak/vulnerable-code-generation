//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define PIXELS (WIDTH * HEIGHT * BPP / 8)

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void generate_random_pixels(pixel *pixels) {
    for (int i = 0; i < PIXELS; ++i) {
        pixels[i].r = rand() % 256;
        pixels[i].g = rand() % 256;
        pixels[i].b = rand() % 256;
    }
}

void save_ppm(const char *filename, const pixel *pixels) {
    FILE *file = fopen(filename, "wb");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int i = 0; i < PIXELS; ++i) {
        fprintf(file, "%d %d %d\n", pixels[i].b, pixels[i].g, pixels[i].r);
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    pixel *pixels = mmap(NULL, PIXELS * sizeof(pixel), PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (pixels == MAP_FAILED) {
        perror("Error mapping memory");
        exit(EXIT_FAILURE);
    }

    generate_random_pixels(pixels);
    save_ppm("output.ppm", pixels);

    munmap(pixels, PIXELS * sizeof(pixel));

    return EXIT_SUCCESS;
}