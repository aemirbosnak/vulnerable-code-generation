//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    struct stat stats;
    fstat(fd, &stats);
    image_t *image = malloc(sizeof(image_t));
    image->width = stats.st_size / WIDTH;
    image->height = stats.st_size % WIDTH;
    image->data = mmap(NULL, stats.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    return image;
}

void draw_circle(image_t *image, int x, int y, int radius) {
    int i, j;
    for (i = 0; i < radius; i++) {
        for (j = 0; j < radius; j++) {
            image->data[i * WIDTH * 3 + j * 3] = (i * j) % 255;
            image->data[i * WIDTH * 3 + j * 3 + 1] = (i * j) % 255;
            image->data[i * WIDTH * 3 + j * 3 + 2] = (i * j) % 255;
        }
    }
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int i, j;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            image->data[i * WIDTH * 3 + j * 3] = 255;
            image->data[i * WIDTH * 3 + j * 3 + 1] = 255;
            image->data[i * WIDTH * 3 + j * 3 + 2] = 255;
        }
    }
}

void draw_text(image_t *image, int x, int y, const char *text) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < 3; j++) {
            image->data[x * WIDTH * 3 + y * WIDTH * 3 + j] = text[i] % 255;
        }
        x += 3;
    }
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    munmap(image->data, image->width * image->height * 3);
    write(fd, image->data, image->width * image->height * 3);
    close(fd);
}

int main() {
    image_t *image = load_image("image.bmp");
    draw_circle(image, 100, 100, 50);
    draw_line(image, 200, 200, 300, 300);
    draw_text(image, 400, 400, "Hello, World!");
    save_image(image, "output.bmp");
    return 0;
}