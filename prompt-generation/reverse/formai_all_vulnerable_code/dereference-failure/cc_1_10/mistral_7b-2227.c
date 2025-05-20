//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define PALETTE_SIZE 16

typedef struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct Palette {
    Pixel colors[PALETTE_SIZE];
} Palette;

void generate_random_palette(Palette *palette) {
    srand(time(NULL));
    for (int i = 0; i < PALETTE_SIZE; ++i) {
        palette->colors[i].r = rand() % 256;
        palette->colors[i].g = rand() % 256;
        palette->colors[i].b = rand() % 256;
    }
}

void save_image(const char *filename, const void *data, size_t size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(data, size, 1, fd);
    close(fd);
}

void create_image(const Palette *palette, uint8_t **image_data) {
    size_t image_size = WIDTH * HEIGHT * BPP / 8;
    *image_data = mmap(NULL, image_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (*image_data == MAP_FAILED) {
        perror("Error creating image memory mapping");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int index = rand() % PALETTE_SIZE;
            (*image_data)[y * WIDTH * BPP / 8 + x * BPP / 8] = palette->colors[index].b;
            (*image_data)[y * WIDTH * BPP / 8 + x * BPP / 8 + 1] = palette->colors[index].g;
            (*image_data)[y * WIDTH * BPP / 8 + x * BPP / 8 + 2] = palette->colors[index].r;
        }
    }
}

int main() {
    Palette palette;
    generate_random_palette(&palette);
    uint8_t *image_data;
    create_image(&palette, &image_data);

    char filename[64];
    sprintf(filename, "output.png");

    save_image(filename, image_data, WIDTH * HEIGHT * BPP / 8);

    munmap(image_data, WIDTH * HEIGHT * BPP / 8);

    return EXIT_SUCCESS;
}