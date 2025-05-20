//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *img = malloc(sizeof(image_t));
    int fd = open(filename, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    img->width = sb.st_size / WIDTH;
    img->height = HEIGHT;
    img->data = mmap(NULL, sb.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    return img;
}

void save_image(const char *filename, image_t *img) {
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    munmap(img->data, img->width * img->height * sizeof(char));
    write(fd, img->data, img->width * img->height);
    close(fd);
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    int i, j;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            img->data[(i * img->width + j) * 3] = 255;
        }
    }
}

void draw_rectangle(image_t *img, int x, int y, int width, int height) {
    int i, j;
    for (i = x; i <= x + width; i++) {
        for (j = y; j <= y + height; j++) {
            img->data[(i * img->width + j) * 3] = 255;
        }
    }
}

int main(void) {
    image_t *img = load_image("image.jpg");
    draw_rectangle(img, 100, 100, 200, 100);
    draw_line(img, 200, 100, 300, 200);
    save_image("output.jpg", img);
    return 0;
}