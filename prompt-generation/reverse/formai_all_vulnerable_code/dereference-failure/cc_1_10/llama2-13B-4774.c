//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_NAME "image.bmp"

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    int image_size = sb.st_size;
    unsigned char *image_data = malloc(image_size);
    read(fd, image_data, image_size);
    close(fd);
    image_t *image = malloc(sizeof(image_t));
    image->data = image_data;
    image->width = WIDTH;
    image->height = HEIGHT;
    return image;
}

void edit_image(image_t *image, int x, int y, int width, int height) {
    int old_width = image->width;
    int old_height = image->height;
    int new_width = old_width + width - x;
    int new_height = old_height + height - y;
    if (new_width > WIDTH) {
        new_width = WIDTH;
        width = new_width - x;
    }
    if (new_height > HEIGHT) {
        new_height = HEIGHT;
        height = new_height - y;
    }
    image->width = new_width;
    image->height = new_height;
    int delta_x = x - (width / 2);
    int delta_y = y - (height / 2);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char pixel = image->data[(j * image->width + i) * BITS_PER_PIXEL / 8];
            if (pixel == 0) {
                image->data[(j * new_width + i) * BITS_PER_PIXEL / 8] = (i + delta_x >= width) ? 0 : 255;
            } else if (pixel == 255) {
                image->data[(j * new_width + i) * BITS_PER_PIXEL / 8] = (i + delta_x < width) ? 0 : 255;
            }
        }
    }
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd, image->data, image->width * image->height * BITS_PER_PIXEL / 8);
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <image_file> <x> <y> <width> <height>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    image_t *image = load_image(argv[1]);
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    int width = atoi(argv[4]);
    int height = atoi(argv[5]);
    edit_image(image, x, y, width, height);
    save_image(image, argv[1]);
    return 0;
}