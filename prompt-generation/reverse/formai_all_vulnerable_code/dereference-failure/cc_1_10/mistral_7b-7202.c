//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define BUFFER_SIZE (WIDTH * HEIGHT * BPP / 8)

typedef struct {
    int x, y, size;
} Point;

Point recursive_pixel(int x, int y, unsigned char *img_data, int size) {
    Point p = {x, y, size};
    if (size <= 0)
        return p;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return p;

    if (img_data[y * WIDTH * BPP / 8 + x * BPP / 8] != 255) {
        p.size = size / 2;
        p.x -= p.size;
        p.y -= p.size;
        return recursive_pixel(p.x, p.y, img_data, p.size);
    }

    img_data[y * WIDTH * BPP / 8 + x * BPP / 8] = 0;

    for (int i = -size / 2; i <= size / 2; i++) {
        for (int j = -size / 2; j <= size / 2; j++) {
            if (recursive_pixel((x + i) % WIDTH, (y + j) % HEIGHT, img_data, p.size).size > 0) {
                img_data[y * WIDTH * BPP / 8 + x * BPP / 8] = 255;
                break;
            }
        }
    }

    return p;
}

int main() {
    unsigned char *img_data;
    int fd = open("output.png", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    img_data = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    memset(img_data, 255, BUFFER_SIZE);

    recursive_pixel(32, 32, img_data, 32);

    munmap(img_data, BUFFER_SIZE);
    close(fd);

    return 0;
}