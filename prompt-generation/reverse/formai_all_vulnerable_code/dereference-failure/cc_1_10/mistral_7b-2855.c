//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void generate_random_pixel(Pixel* pixel) {
    pixel->r = rand() % 256;
    pixel->g = rand() % 256;
    pixel->b = rand() % 256;
}

void save_ppm(const char* filename, Pixel* data, int width, int height) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P3\n%d %d\n255\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel* pixel = data + (y * width + x);
            fprintf(file, "%d %d %d\n", pixel->r, pixel->g, pixel->b);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    Pixel* pixels = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (pixels == MAP_FAILED) {
        perror("Error initializing memory mapping");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        generate_random_pixel(pixels + i);
    }

    char filename[100];
    sprintf(filename, "output.ppm");
    save_ppm(filename, pixels, WIDTH, HEIGHT);

    munmap(pixels, WIDTH * HEIGHT * BPP);

    return EXIT_SUCCESS;
}