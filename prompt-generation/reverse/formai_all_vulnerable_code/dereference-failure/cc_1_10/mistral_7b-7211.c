//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3

typedef struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

Pixel random_pixel() {
    static const uint8_t RANGE = 255;
    Pixel pixel;

    pixel.r = rand() % RANGE;
    pixel.g = rand() % RANGE;
    pixel.b = rand() % RANGE;

    return pixel;
}

void generate_random_image(void *data) {
    Pixel *p;
    size_t size = WIDTH * HEIGHT * BPP / 8;

    for (p = data; size; size--) {
        *((Pixel *) p++) = random_pixel();
    }
}

int main(int argc, char *argv[]) {
    int fd;
    void *image_data;
    char *filename;
    clock_t start;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <output-filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];

    start = clock();

    fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) die("open");

    image_data = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (image_data == MAP_FAILED) die("mmap");

    generate_random_image(image_data);

    if (write(fd, image_data, WIDTH * HEIGHT * BPP) == -1) die("write");

    munmap(image_data, WIDTH * HEIGHT * BPP);
    close(fd);

    printf("Image generated in %f seconds.\n", (double) (clock() - start) / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}