//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024
#define BITS_PER_BYTE 8
#define WORD_SIZE 32
#define FRAME_SIZE (WORD_SIZE * BITS_PER_BYTE)
#define BLOCK_SIZE (FRAME_SIZE * 16)
#define ROWS 16
#define COLS 16

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

void print_binary(uint32_t num) {
    uint32_t i, bit;

    for (i = 31; i >= 0; i--) {
        bit = num >> i & 1;
        putchar(bit + '0');
    }
    putchar('\n');
}

void process_image(const char *filename) {
    int fd, i, j;
    char *image_data;
    uint32_t *pixels;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    image_data = mmap(NULL, BLOCK_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (image_data == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    pixels = (uint32_t *) image_data;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            uint32_t pixel = pixels[i * COLS + j];
            print_binary(pixel);
        }
    }

    munmap(image_data, BLOCK_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    process_image(argv[1]);

    return EXIT_SUCCESS;
}