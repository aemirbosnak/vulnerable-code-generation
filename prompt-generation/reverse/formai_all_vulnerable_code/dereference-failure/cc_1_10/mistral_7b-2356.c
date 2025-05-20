//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdint.h>

#define WIDTH 51
#define HEIGHT 11
#define BMP_SIZE (WIDTH * HEIGHT * 3)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} bitmap_file_header;

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t padding;
} info_header;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pixel;

static void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        die("Failed to open image file.");
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        die("Failed to get image file stats.");
    }

    if (st.st_size < BMP_SIZE) {
        fprintf(stderr, "Image file is not a valid BMP.\n");
        close(fd);
        exit(1);
    }

    bitmap_file_header file_header;
    info_header info_header;
    char bmp_header[14];

    lseek(fd, 0, SEEK_SET);
    read(fd, bmp_header, 14);

    memcpy(&file_header, bmp_header, sizeof(bitmap_file_header));
    lseek(fd, file_header.offset_data, SEEK_SET);
    pixel *pixels = mmap(NULL, BMP_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);

    if (pixels == MAP_FAILED) {
        die("Failed to map image data into memory.");
    }

    close(fd);

    printf("+-----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+\n");
    for (int y = 0; y < HEIGHT; ++y) {
        printf("| ");
        for (int x = 0; x < WIDTH; ++x) {
            int index = y * WIDTH + x;
            pixel p = pixels[index];
            printf("%c", isprint(p.blue) ? p.blue : '.');
            printf("%c", isprint(p.green) ? p.green : '.');
            printf("%c", isprint(p.red) ? p.red : '.');
        }
        printf("|\n");
    }
    printf("+-----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+\n");

    munmap(pixels, BMP_SIZE);

    return 0;
}