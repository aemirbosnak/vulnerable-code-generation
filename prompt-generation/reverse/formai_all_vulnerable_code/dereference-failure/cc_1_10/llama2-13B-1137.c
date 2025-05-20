//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define IMAGE_FILE "image.ppm"

typedef struct {
    char *data;
    size_t size;
} image_t;

image_t load_image(const char *file_name) {
    image_t img;
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return img;
    }

    struct stat stat_buf;
    if (fstat(fd, &stat_buf) == -1) {
        perror("Error stat'ing file");
        close(fd);
        return img;
    }

    size_t file_size = stat_buf.st_size;
    img.data = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img.data == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return img;
    }

    img.size = file_size;
    close(fd);
    return img;
}

void save_image(const char *file_name, image_t img) {
    int fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    if (write(fd, img.data, img.size) != img.size) {
        perror("Error writing to file");
        close(fd);
        return;
    }

    close(fd);
}

void draw_line(image_t img, int x1, int y1, int x2, int y2, int color) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            img.data[i * WIDTH * BPP + j * BPP] = color;
        }
    }
}

void draw_rectangle(image_t img, int x, int y, int width, int height, int color) {
    for (int i = x; i <= x + width; i++) {
        for (int j = y; j <= y + height; j++) {
            img.data[i * WIDTH * BPP + j * BPP] = color;
        }
    }
}

int main() {
    image_t img = load_image(IMAGE_FILE);
    if (img.data == MAP_FAILED) {
        perror("Error loading image");
        return 1;
    }

    // Draw some lines and rectangles
    draw_line(img, 0, 0, WIDTH, HEIGHT, 0xFF0000); // Black line
    draw_line(img, WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0x00FF00); // Green line
    draw_rectangle(img, 100, 100, 100, 100, 0xFFFFFF); // White rectangle

    // Save the modified image
    save_image("modified_image.ppm", img);

    return 0;
}