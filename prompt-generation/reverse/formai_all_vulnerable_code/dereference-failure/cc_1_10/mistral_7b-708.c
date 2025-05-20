//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define BUFFER_SIZE (WIDTH * HEIGHT * BPP)

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void generate_random_palette(pixel palette[16]) {
    for (int i = 0; i < 16; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }
}

void generate_random_image(pixel *image_buffer, pixel palette[16]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image_buffer[(y * WIDTH) + x] = palette[rand() % 16];
        }
    }
}

void save_image(const char *filename, pixel *image_buffer, pixel palette[16]) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    char magic_number[3] = { 'P', '5' };
    write(fd, magic_number, sizeof(magic_number));

    write(fd, "PPM\n", 3);
    write(fd, "64 64\n", 6);
    write(fd, "255\n", 3);

    for (int i = 0; i < 16; i++) {
        write(fd, "255 ", 4);
        write(fd, &palette[i].b, 1);
        write(fd, " ", 1);
        write(fd, &palette[i].g, 1);
        write(fd, " ", 1);
        write(fd, &palette[i].r, 1);
        write(fd, "\n", 1);
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel current_pixel = image_buffer[(y * WIDTH) + x];
            write(fd, &current_pixel.b, 1);
            write(fd, &current_pixel.g, 1);
            write(fd, &current_pixel.r, 1);
        }
    }

    close(fd);
}

int main() {
    srand(time(NULL));

    pixel palette[16];
    generate_random_palette(palette);

    pixel *image_buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (image_buffer == MAP_FAILED) {
        perror("Error mapping memory");
        exit(EXIT_FAILURE);
    }

    generate_random_image(image_buffer, palette);

    const char *filename = "output.ppm";
    save_image(filename, image_buffer, palette);

    munmap(image_buffer, BUFFER_SIZE);

    printf("Pixel art generator has created an image named %s.\n", filename);

    return EXIT_SUCCESS;
}