//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    int size = sb.st_size;
    char *data = malloc(size);
    read(fd, data, size);
    close(fd);
    image_t *img = malloc(sizeof(image_t));
    img->data = data;
    img->width = WIDTH;
    img->height = HEIGHT;
    return img;
}

void draw_shape(image_t *img, int x, int y, int width, int height, int color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->data[(y * img->width * BITS_PER_PIXEL) + (x * BITS_PER_PIXEL + j * BITS_PER_PIXEL)] = (color >> (j * BITS_PER_PIXEL)) & 0x1;
        }
        x += width;
    }
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steep = dx > dy;
    int y = y1;
    int x = x1;

    if (steep) {
        int temp = dx;
        dx = dy;
        dy = temp;
    }

    for (int i = 0; i < dx; i++) {
        img->data[(y * img->width * BITS_PER_PIXEL) + (x * BITS_PER_PIXEL)] = (color >> (i * BITS_PER_PIXEL)) & 0x1;
        x++;
    }

    for (int i = 0; i < dy; i++) {
        img->data[(y * img->width * BITS_PER_PIXEL) + (x * BITS_PER_PIXEL)] = (color >> (i * BITS_PER_PIXEL)) & 0x1;
        y++;
    }
}

void save_image(image_t *img, const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    mprotect(img->data, img->width * img->height * BITS_PER_PIXEL, PROT_READ | PROT_WRITE);
    write(fd, img->data, img->width * img->height * BITS_PER_PIXEL);
    close(fd);
}

int main() {
    image_t *img = load_image("image.bmp");
    draw_shape(img, 100, 100, 200, 100, 0x00ff0000);
    draw_line(img, 200, 100, 300, 200, 0x0000ff00);
    draw_line(img, 300, 200, 400, 300, 0x000000ff);
    save_image(img, "output.bmp");
    free(img->data);
    free(img);
    return 0;
}