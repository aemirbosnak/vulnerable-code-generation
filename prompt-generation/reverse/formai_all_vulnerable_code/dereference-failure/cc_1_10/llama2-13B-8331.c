//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_FILE "image.ppm"

typedef struct {
    unsigned char *data;
    size_t width, height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }
    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error statting file");
        close(fd);
        return NULL;
    }
    image->width = stat.st_size / WIDTH * HEIGHT;
    image->height = HEIGHT;
    image->data = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return NULL;
    }
    close(fd);
    return image;
}

void save_image(const char *filename, image_t *image) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error statting file");
        close(fd);
        return;
    }
    if (stat.st_size != image->width * image->height * BITS_PER_PIXEL / 8) {
        close(fd);
        fprintf(stderr, "Error: Image size mismatch\n");
        return;
    }
    if (mmap(image->data, image->width * image->height * BITS_PER_PIXEL / 8, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0) == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return;
    }
    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    unsigned char *p = image->data + (y1 * image->width * BITS_PER_PIXEL / 8) + (x1 * BITS_PER_PIXEL / 8);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = 1;
    int stepy = dy > 0 ? 1 : -1;
    if (dx == 0) {
        stepx = 0;
    }
    if (dy == 0) {
        stepy = 0;
    }
    for (int x = x1; x <= x2; x++) {
        *p = (x == x1) ? 255 : 0;
        p += BITS_PER_PIXEL / 8;
    }
    for (int y = y1; y <= y2; y++) {
        p = image->data + (y * image->width * BITS_PER_PIXEL / 8) + (x1 * BITS_PER_PIXEL / 8);
        if (dy > 0) {
            *p = (y == y1) ? 255 : 0;
            p += BITS_PER_PIXEL / 8;
        } else {
            *p = (y == y1) ? 0 : 255;
            p -= BITS_PER_PIXEL / 8;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    draw_line(image, x, y, x + width, y);
    draw_line(image, x, y + height, x + width, y + height);
    draw_line(image, x, y, x, y + height);
    draw_line(image, x + width, y, x + width, y + height);
}

int main() {
    image_t *image = load_image(IMAGE_FILE);
    if (image == NULL) {
        perror("Error loading image");
        return 1;
    }
    draw_rectangle(image, 100, 100, 200, 100);
    draw_rectangle(image, 300, 100, 100, 200);
    save_image("output.ppm", image);
    return 0;
}