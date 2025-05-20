//MISTRAL-7B DATASET v1.0 Category: Image Classification system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256
#define IMAGE_SIZE IMAGE_WIDTH * IMAGE_HEIGHT
#define THRESHOLD 128

typedef unsigned char pixel_t;

void read_image(const char *filename, pixel_t *data) {
    int fd = open(filename, O_RDONLY);
    mmap(data, IMAGE_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
}

void write_image(const char *filename, const pixel_t *data) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    msync(data, IMAGE_SIZE, MS_ASYNC);
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel_t *image = mmap(NULL, IMAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    read_image(argv[1], image);

    for (int y = 0; y < IMAGE_HEIGHT; ++y) {
        for (int x = 0; x < IMAGE_WIDTH; ++x) {
            if (image[y * IMAGE_WIDTH + x] < THRESHOLD) {
                image[y * IMAGE_WIDTH + x] = 0;
            } else {
                image[y * IMAGE_WIDTH + x] = 255;
            }
        }
    }

    const char *output_filename = "output.pgm";
    write_image(output_filename, image);

    munmap(image, IMAGE_SIZE);

    printf("Image classified. Output saved to %s.\n", output_filename);
    return EXIT_SUCCESS;
}