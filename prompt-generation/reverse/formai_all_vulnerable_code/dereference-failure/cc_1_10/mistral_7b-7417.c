//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 31
#define HEIGHT 11
#define BMP_SIZE(width, height) ((width) * (height) * 3 + 54)
#define BMP_FILEHEADER_SIZE 14
#define BMP_INFOHEADER_SIZE 40
#define BMP_PIXEL_SIZE 3

typedef struct {
    char signature[2];
    int file_size;
    char reserved1[2];
    char reserved2[2];
    char offset_data;
} bmp_fileheader;

typedef struct {
    int size;
    int width;
    int height;
    short planes;
    short bit_count;
    int compression;
    int size_image;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    int colors_used;
    int colors_important;
} bmp_infoheader;

typedef unsigned char byte;

byte* load_bmp(const char* filename) {
    int fd = open(filename, O_RDONLY);
    byte* data = mmap(NULL, BMP_SIZE(WIDTH, HEIGHT), PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    return data;
}

void print_ascii_art(const byte* data) {
    bmp_fileheader fileheader;
    bmp_infoheader infoheader;
    int i, j, index;

    memcpy(&fileheader, data, sizeof(fileheader));
    memcpy(&infoheader, data + BMP_FILEHEADER_SIZE, sizeof(infoheader));

    for (i = HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < WIDTH; j++) {
            index = (i * WIDTH + j) * 3;
            printf("%c", (infoheader.bit_count == 1)
                       ? (data[index] > 128 ? '#' : ' ')
                       : (isprint(data[index]) ? data[index] : ' '));
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <path_to_bmp_file>\n", argv[0]);
        return 1;
    }

    byte* data = load_bmp(argv[1]);
    print_ascii_art(data);
    munmap(data, BMP_SIZE(WIDTH, HEIGHT));

    return 0;
}