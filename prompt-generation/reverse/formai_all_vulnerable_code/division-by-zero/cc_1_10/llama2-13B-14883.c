//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <utime.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 8
#define BYTES_PER_PIXEL (WIDTH * HEIGHT * BITS_PER_PIXEL / 8)

typedef struct {
    int width, height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    image_t *img = malloc(sizeof(image_t));
    img->width = sb.st_size / WIDTH * HEIGHT;
    img->height = HEIGHT;
    img->data = mmap(NULL, BYTES_PER_PIXEL, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    return img;
}

void paint(image_t *img, int x, int y, int size, unsigned char color) {
    int start_x = (x / size) * size;
    int start_y = (y / size) * size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                img->data[start_x + i * WIDTH + j] = color;
            } else {
                img->data[start_x + i * WIDTH + j] = (img->data[start_x + i * WIDTH + j] + color) % 256;
            }
        }
    }
}

void zoom(image_t *img, int x, int y, int size) {
    int start_x = (x / size) * size;
    int start_y = (y / size) * size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int src_x = start_x + i * WIDTH;
            int src_y = start_y + j * HEIGHT;
            int dst_x = src_x * size / WIDTH;
            int dst_y = src_y * size / HEIGHT;
            img->data[dst_x + dst_y * WIDTH] = img->data[src_x + src_y * WIDTH];
        }
    }
}

void pan(image_t *img, int x, int y) {
    img->data += (y * WIDTH + x) * BITS_PER_PIXEL / 8;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    image_t *img = load_image(argv[1]);
    printf("Image size: %dx%d\n", img->width, img->height);

    char cmd;
    while (1) {
        printf("Commands: z (zoom), p (pan), c (change color), q (quit)\n");
        scanf("%c", &cmd);
        if (cmd == 'z') {
            int size;
            scanf("%d", &size);
            zoom(img, 0, 0, size);
        } else if (cmd == 'p') {
            int x, y;
            scanf("%d,%d", &x, &y);
            pan(img, x, y);
        } else if (cmd == 'c') {
            int color;
            scanf("%d", &color);
            paint(img, 0, 0, 1, color);
        } else if (cmd == 'q') {
            break;
        }
    }

    munmap(img->data, BYTES_PER_PIXEL);
    free(img);
    return 0;
}