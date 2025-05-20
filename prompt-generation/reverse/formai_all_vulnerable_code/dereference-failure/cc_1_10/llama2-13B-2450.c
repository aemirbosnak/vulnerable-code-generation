//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_FILE "image.bmp"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *file_name) {
    int fd = open(file_name, O_RDONLY);
    struct stat sb;
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    fstat(fd, &sb);
    image_t *img = malloc(sizeof(image_t));
    img->width = sb.st_size / WIDTH * BITS_PER_PIXEL;
    img->height = HEIGHT;
    img->data = mmap(NULL, img->width * HEIGHT * BITS_PER_PIXEL, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img->data == MAP_FAILED) {
        perror("Error mapping file");
        return NULL;
    }

    close(fd);
    return img;
}

void draw_point(image_t *img, int x, int y, unsigned char color) {
    int offset = y * img->width * BITS_PER_PIXEL + x * BITS_PER_PIXEL;
    img->data[offset] = color;
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2, unsigned char color) {
    int offset1 = y1 * img->width * BITS_PER_PIXEL + x1 * BITS_PER_PIXEL;
    int offset2 = y2 * img->width * BITS_PER_PIXEL + x2 * BITS_PER_PIXEL;
    for (int i = x1; i <= x2; i++) {
        img->data[offset1 + i] = color;
    }
}

void draw_rectangle(image_t *img, int x, int y, int width, int height, unsigned char color) {
    for (int i = y; i <= height; i++) {
        for (int j = x; j <= width; j++) {
            img->data[i * img->width * BITS_PER_PIXEL + j * BITS_PER_PIXEL] = color;
        }
    }
}

void save_image(image_t *img, const char *file_name) {
    int fd = open(file_name, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct stat sb;
    fstat(fd, &sb);
    if (sb.st_size != 0) {
        unlink(file_name);
    }

    write(fd, img->data, img->width * HEIGHT * BITS_PER_PIXEL);
    close(fd);
}

int main() {
    image_t *img = load_image(IMAGE_FILE);
    if (img == NULL) {
        return 1;
    }

    draw_point(img, 100, 100, 0x000000FF);  // draw a blue point
    draw_line(img, 100, 100, 200, 200, 0x0000FF00);  // draw a blue line
    draw_rectangle(img, 100, 100, 200, 200, 0x00FF0000);  // draw a blue rectangle

    save_image(img, "output.bmp");

    munmap(img->data, img->width * HEIGHT * BITS_PER_PIXEL);
    free(img);

    return 0;
}