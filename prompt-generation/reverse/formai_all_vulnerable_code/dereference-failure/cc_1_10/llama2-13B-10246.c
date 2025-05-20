//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

void load_image(Image* image, char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct stat stat;
    fstat(fd, &stat);

    image->width = stat.st_size / WIDTH * 3;
    image->height = stat.st_size / HEIGHT;
    image->data = mmap(NULL, stat.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);

    close(fd);
}

void draw_line(Image* image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = dx > 0 ? 1 : 0;
    int stepy = dy > 0 ? 1 : 0;

    for (int i = 0; i < abs(dx); i++) {
        for (int j = 0; j < abs(dy); j++) {
            if (dx > 0 && i == 0) {
                image->data[y1 * WIDTH * 3 + x1 * 3] = 0xFF;
            } else if (dx < 0 && i == (abs(dx) - 1)) {
                image->data[y1 * WIDTH * 3 + x1 * 3] = 0x00;
            } else if (dy > 0 && j == 0) {
                image->data[y1 * WIDTH * 3 + x1 * 3] = 0x00;
            } else if (dy < 0 && j == (abs(dy) - 1)) {
                image->data[y1 * WIDTH * 3 + x1 * 3] = 0xFF;
            } else {
                image->data[y1 * WIDTH * 3 + x1 * 3] = (dx > 0 && dy > 0) ? 0xFF : 0x00;
            }
        }
        x1 += stepx;
        y1 += stepy;
    }
}

void draw_circle(Image* image, int x, int y, int radius) {
    int fx = x - radius;
    int fy = y - radius;
    int cx = x + radius;
    int cy = y + radius;

    draw_line(image, fx, fy, cx, cy);
    draw_line(image, fx, cy, cx, fy);
    draw_line(image, fx, fy, cx, cy);
}

void draw_rectangle(Image* image, int x, int y, int width, int height) {
    int left = x;
    int top = y;
    int right = x + width;
    int bottom = y + height;

    draw_line(image, left, top, right, top);
    draw_line(image, left, bottom, right, bottom);
    draw_line(image, left, top, left, bottom);
    draw_line(image, right, top, right, bottom);
}

void save_image(Image* image, char* filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    munmap(image->data, image->width * image->height * 3);

    write(fd, image->data, image->width * image->height * 3);

    close(fd);
}

int main() {
    Image image;
    load_image(&image, "example.jpg");

    draw_circle(&image, 100, 100, 50);
    draw_rectangle(&image, 200, 200, 300, 200);

    save_image(&image, "output.jpg");

    return 0;
}