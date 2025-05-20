//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <utime.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char *data;
    size_t size;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    int fd = open(filename, O_RDONLY);
    struct stat stat;
    fstat(fd, &stat);
    image->size = stat.st_size;
    image->data = mmap(NULL, image->size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    return image;
}

void save_image(const char *filename, image_t *image) {
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    munmap(image->data, image->size);
    write(fd, image->data, image->size);
    close(fd);
}

void edit_image(image_t *image, int x, int y, int width, int height) {
    int new_width = width + x;
    int new_height = height + y;
    if (new_width > WIDTH) {
        new_width = WIDTH;
        new_height = height;
    } else if (new_height > HEIGHT) {
        new_height = HEIGHT;
        new_width = width;
    }
    unsigned char *new_data = calloc(new_width * new_height, 3);
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            int ox = j - x;
            int oy = i - y;
            int nx = j % width;
            int ny = i % height;
            new_data[i * new_width * 3 + j * 3] =
                    image->data[ox * HEIGHT * 3 + oy * WIDTH * 3 + nx * 3 + ny * 3];
        }
    }
    image->data = new_data;
    image->size = new_width * new_height * 3;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image_file> <x> <y> <width> <height>\n", argv[0]);
        return 1;
    }
    image_t *image = load_image(argv[1]);
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    int width = atoi(argv[4]);
    int height = atoi(argv[5]);
    edit_image(image, x, y, width, height);
    save_image(argv[1], image);
    return 0;
}