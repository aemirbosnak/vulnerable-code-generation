//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    char *data;
    size_t size;
} image_t;

void load_image(image_t *image, const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    struct stat stat;
    fstat(fd, &stat);
    image->size = stat.st_size;

    image->data = mmap(NULL, image->size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return;
    }

    close(fd);
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }

    size_t written = 0;
    while (written < image->size) {
        ssize_t ret = write(fd, image->data + written, image->size - written);
        if (ret == -1) {
            perror("write");
            break;
        }
        written += ret;
    }

    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, int color) {
    int x = x1, y = y1;
    while (x <= x2) {
        image->data[y * WIDTH * 3 + x * 3] = color;
        image->data[y * WIDTH * 3 + x * 3 + 1] = color;
        image->data[y * WIDTH * 3 + x * 3 + 2] = color;
        x++;
    }
}

void draw_rectangle(image_t *image, int x, int y, int w, int h, int color) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image->data[y * WIDTH * 3 + x * 3 + i * w * 3] = color;
            image->data[y * WIDTH * 3 + x * 3 + (i * w) * 3 + 1] = color;
            image->data[y * WIDTH * 3 + x * 3 + (i * w) * 3 + 2] = color;
        }
    }
}

int main() {
    image_t image;
    load_image(&image, "example.png");

    draw_line(&image, 0, 0, WIDTH, HEIGHT, 0x00FF0000); // green
    draw_rectangle(&image, 10, 10, 30, 30, 0xFF000000); // red
    draw_rectangle(&image, WIDTH - 20, 20, 20, 30, 0x00FFFF00); // blue

    save_image(&image, "output.png");

    return 0;
}