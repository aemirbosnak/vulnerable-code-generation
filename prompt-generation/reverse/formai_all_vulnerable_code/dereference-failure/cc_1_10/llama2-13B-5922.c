//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define IMAGE_FILE "image.bmp"

typedef struct {
    int x, y;
    unsigned char r, g, b, a;
} pixel_t;

pixel_t* load_image(const char* file_name) {
    int fd = open(file_name, O_RDONLY);
    struct stat stat_info;
    fstat(fd, &stat_info);
    unsigned char* buffer = mmap(NULL, stat_info.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    pixel_t* pixels = (pixel_t*)buffer;
    close(fd);
    return pixels;
}

void draw_line(pixel_t* pixels, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepx = (x2 < x1) ? 1 : -1;
    int stepy = (y2 < y1) ? 1 : -1;
    pixel_t current = {x1, y1, r, g, b, 255};
    pixel_t next = {x1, y1, r, g, b, 255};
    for (int i = 0; i < dx; i++) {
        next.x += stepx;
        next.y += stepy;
        if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT) break;
        pixels[next.x + next.y * WIDTH] = next;
        current.x = next.x;
        current.y = next.y;
    }
}

void draw_circle(pixel_t* pixels, int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b) {
    int fx = x - radius;
    int fy = y - radius;
    int dx = 2 * (radius - fx);
    int dy = 2 * (radius - fy);
    int stepx = (dx > 0) ? 1 : -1;
    int stepy = (dy > 0) ? 1 : -1;
    pixel_t current = {x, y, r, g, b, 255};
    pixel_t next = {x, y, r, g, b, 255};
    for (int i = 0; i < dx; i++) {
        next.x += stepx;
        next.y += stepy;
        if (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT) break;
        pixels[next.x + next.y * WIDTH] = next;
        current.x = next.x;
        current.y = next.y;
    }
}

void draw_image(pixel_t* pixels, int x, int y, pixel_t* image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i] = image[i];
    }
}

int main() {
    pixel_t* pixels = load_image(IMAGE_FILE);
    draw_circle(pixels, 100, 100, 50, 255, 0, 0);
    draw_line(pixels, 100, 100, 200, 200, 0, 255, 0);
    draw_image(pixels, 0, 0, pixels);
    munmap((void*)pixels, WIDTH * HEIGHT * sizeof(pixel_t));
    return 0;
}