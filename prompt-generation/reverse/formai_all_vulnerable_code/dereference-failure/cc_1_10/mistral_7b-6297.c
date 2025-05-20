//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define BUFFER_SIZE (WIDTH * HEIGHT * BPP)

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel* pixels;

void init() {
    pixels = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memset(pixels, 0, BUFFER_SIZE);
}

void generate_pixel_art() {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            pixels[y * WIDTH + x].r = x % 16;
            pixels[y * WIDTH + x].g = y % 16;
            pixels[y * WIDTH + x].b = (x + y) % 16;
        }
    }
}

void save_image(const char* filename) {
    int fd;
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    write(fd, pixels, BUFFER_SIZE);
    close(fd);
}

int main() {
    init();
    generate_pixel_art();
    save_image("output.png");
    munmap(pixels, BUFFER_SIZE);
    return 0;
}