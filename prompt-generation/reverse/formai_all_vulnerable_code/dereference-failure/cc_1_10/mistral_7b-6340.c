//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 128
#define HEIGHT 128
#define BPP 3

typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel* pixels = NULL;

void read_pgm(const char* filename) {
    char magic_number[3];
    int width, height, max_value;
    FILE* file = fopen(filename, "rb");
    fgets(magic_number, 3, file);
    fscanf(file, "%d%d%d", &width, &height, &max_value);
    pixels = (Pixel*) mmap(NULL, width * height * BPP, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (pixels == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    size_t i;
    for (i = 0; i < width * height; i++) {
        fscanf(file, "%d%d%d", &pixels[i].r, &pixels[i].g, &pixels[i].b);
    }
    fclose(file);
}

void save_pgm(const char* filename) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(file, "%d %d %d\n", pixels[i].r, pixels[i].g, pixels[i].b);
    }
    fclose(file);
}

void generate_pixel_art(int x, int y, unsigned char r, unsigned char g, unsigned char b, size_t radius) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }

    pixels[y * WIDTH + x].r += r;
    pixels[y * WIDTH + x].g += g;
    pixels[y * WIDTH + x].b += b;

    for (size_t i = 1; i <= radius; i++) {
        int dx = 2 * i - 1;
        int dy = 2 * i;
        if (x + dx < 0 || x + dx >= WIDTH || y + dy < 0 || y + dy >= HEIGHT) {
            continue;
        }
        pixels[(y + dy) * WIDTH + (x + dx)].r += r;
        pixels[(y + dy) * WIDTH + (x + dx)].g += g;
        pixels[(y + dy) * WIDTH + (x + dx)].b += b;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_pgm> <output_pgm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];

    read_pgm(input_filename);

    generate_pixel_art(50, 50, 255, 0, 0, 10);

    save_pgm(output_filename);

    munmap(pixels, WIDTH * HEIGHT * BPP);

    return EXIT_SUCCESS;
}