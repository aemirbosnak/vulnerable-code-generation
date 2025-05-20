//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char *data;
    size_t size;
} image_t;

void load_image(image_t *image, const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open image file");
        return;
    }

    struct stat stat;
    fstat(fd, &stat);
    size_t file_size = stat.st_size;

    image->data = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Failed to mmap image data");
        close(fd);
        return;
    }

    image->size = file_size;
    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, unsigned char color) {
    int x = x1;
    int y = y1;
    while (x <= x2) {
        image->data[y * WIDTH * 3 + x * 3] = color;
        image->data[y * WIDTH * 3 + x * 3 + 1] = color;
        image->data[y * WIDTH * 3 + x * 3 + 2] = color;
        x++;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height, unsigned char color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image->data[y * WIDTH * 3 + x * 3] = color;
            image->data[y * WIDTH * 3 + x * 3 + 1] = color;
            image->data[y * WIDTH * 3 + x * 3 + 2] = color;
            x++;
        }
        x = 0;
    }
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Failed to create image file");
        return;
    }

    munmap(image->data, image->size);

    write(fd, image->data, image->size);
    close(fd);
}

int main(void) {
    image_t image;
    load_image(&image, "example.jpg");

    draw_rectangle(&image, 10, 10, 100, 50, 0xFF0000);
    draw_line(&image, 10, 10, 150, 50, 0x00FF00);

    save_image(&image, "output.jpg");

    return 0;
}