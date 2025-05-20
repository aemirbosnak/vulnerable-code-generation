//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t load_image(const char *filename) {
    image_t img;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open image file");
        return img;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("Failed to stat image file");
        close(fd);
        return img;
    }

    img.width = sb.st_size / WIDTH * BPP;
    img.height = HEIGHT;
    img.data = mmap(NULL, sb.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img.data == MAP_FAILED) {
        perror("Failed to mmap image data");
        close(fd);
        return img;
    }

    close(fd);
    return img;
}

void save_image(const char *filename, image_t img) {
    int fd;

    fd = open(filename, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Failed to open image file");
        return;
    }

    if (ftruncate(fd, img.width * HEIGHT * BPP) == -1) {
        perror("Failed to truncate image file");
        close(fd);
        return;
    }

    if (write(fd, img.data, img.width * HEIGHT * BPP) == -1) {
        perror("Failed to write image data");
        close(fd);
        return;
    }

    close(fd);
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    int x, y, i;

    for (x = x1; x <= x2; x++) {
        for (y = y1; y <= y2; y++) {
            i = (x + y * WIDTH) * BPP;
            img->data[i] = 255;
        }
    }
}

void draw_rectangle(image_t *img, int x1, int y1, int x2, int y2) {
    int x, y, i;

    for (x = x1; x <= x2; x++) {
        for (y = y1; y <= y2; y++) {
            i = (x + y * WIDTH) * BPP;
            img->data[i] = 255;
        }
    }
}

int main() {
    image_t img;

    img = load_image("image.bmp");
    if (img.data == MAP_FAILED) {
        perror("Failed to load image");
        return 1;
    }

    draw_line(&img, 0, 0, WIDTH, HEIGHT);
    draw_rectangle(&img, 100, 100, 200, 200);

    save_image("output.bmp", img);

    return 0;
}