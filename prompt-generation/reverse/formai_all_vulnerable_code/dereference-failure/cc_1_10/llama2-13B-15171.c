//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32

struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct image {
    struct pixel *data;
    size_t width;
    size_t height;
};

void load_image(struct image *image, const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error stat'ing file");
        return;
    }

    size_t size = stat.st_size;
    if (size == 0) {
        fprintf(stderr, "Error: file is empty\n");
        return;
    }

    image->data = mmap(NULL, size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Error mmapping file");
        return;
    }

    image->width = stat.st_size / BITS_PER_PIXEL / WIDTH;
    image->height = stat.st_size / BITS_PER_PIXEL / HEIGHT;

    close(fd);
}

void save_image(struct image *image, const char *filename) {
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    size_t size = image->width * image->height * BITS_PER_PIXEL;
    struct pixel *data = image->data;
    size_t written = 0;

    while (written < size) {
        ssize_t written_now = write(fd, data + written, size - written);
        if (written_now == -1) {
            perror("Error writing to file");
            break;
        }

        written += written_now;
    }

    close(fd);
}

void draw_line(struct image *image, int x1, int y1, int x2, int y2, struct pixel color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = 1;
    int stepy = dx > 0 ? 1 : 0;
    struct pixel pixel;

    pixel.r = color.r;
    pixel.g = color.g;
    pixel.b = color.b;
    pixel.a = 255;

    for (int x = x1; x <= x2; x += stepx) {
        for (int y = y1; y <= y2; y += stepy) {
            int index = (y * image->width + x) * BITS_PER_PIXEL;
            image->data[index] = pixel;
        }
    }
}

int main() {
    struct image image;
    load_image(&image, "image.bmp");

    draw_line(&image, 0, 0, image.width, image.height, (struct pixel) {255, 0, 0});

    save_image(&image, "output.bmp");

    return 0;
}