//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32

typedef struct {
    uint32_t pixels[WIDTH * HEIGHT];
} image_t;

image_t *load_image(const char *filename) {
    int fd;
    uint32_t *ptr;
    size_t size;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    size = WIDTH * HEIGHT * BITS_PER_PIXEL / 8;
    ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return NULL;
    }

    image_t *img = (image_t *)ptr;
    close(fd);
    return img;
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    int x, y;
    for (x = x1; x <= x2; x++) {
        for (y = y1; y <= y2; y++) {
            img->pixels[y * WIDTH + x] = 0xFFFFFFFF;
        }
    }
}

void draw_rectangle(image_t *img, int x, int y, int width, int height) {
    draw_line(img, x, y, x + width, y + height);
    draw_line(img, x, y + height, x + width, y);
    draw_line(img, x + width, y, x, y + height);
    draw_line(img, x + width, y + height, x, y);
}

void draw_circle(image_t *img, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    draw_rectangle(img, x1, y1, x2 - x1, y2 - y1);
}

void save_image(image_t *img, const char *filename) {
    int fd;
    size_t size;

    fd = open(filename, O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    size = WIDTH * HEIGHT * BITS_PER_PIXEL / 8;
    munmap((void *)img, size);
    close(fd);
}

int main(void) {
    image_t *img = load_image("example.bmp");
    if (img == NULL) {
        perror("Error loading image");
        return 1;
    }

    draw_rectangle(img, 100, 100, 200, 200);
    draw_circle(img, 250, 250, 100);

    save_image(img, "output.bmp");

    return 0;
}