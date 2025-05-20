//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }
    struct stat stats;
    if (fstat(fd, &stats) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }
    image->width = stats.st_size / 3;
    image->height = stats.st_size % 3;
    image->data = mmap(NULL, stats.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }
    close(fd);
    return image;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int x = x1 < x2 ? x1 : x2;
    int y = y1 < y2 ? y1 : y2;
    while (x <= x2) {
        image->data[y * image->width * 3 + x * 3] = 255;
        image->data[y * image->width * 3 + x * 3 + 1] = 0;
        image->data[y * image->width * 3 + x * 3 + 2] = 0;
        x++;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    int x1 = x;
    int y1 = y;
    int x2 = x + width - 1;
    int y2 = y + height - 1;
    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x1, y2, x2, y1);
}

void draw_circle(image_t *image, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;
    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x1, y2, x2, y1);
}

void draw_text(image_t *image, int x, int y, const char *text) {
    int i = 0;
    while (text[i]) {
        int font_width = 10;
        int font_height = 10;
        draw_rectangle(image, x, y + i * font_height, font_width, font_height);
        i++;
    }
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }
    if (write(fd, image->data, image->width * image->height * 3) == -1) {
        perror("write");
        close(fd);
        return;
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    image_t *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Failed to load image %s\n", argv[1]);
        return 2;
    }
    draw_rectangle(image, 100, 100, 200, 100);
    draw_circle(image, 200, 200, 50);
    draw_text(image, 300, 300, "Hello, World!");
    save_image(image, "output.ppm");
    return 0;
}