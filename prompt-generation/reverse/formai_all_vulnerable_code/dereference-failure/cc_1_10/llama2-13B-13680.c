//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: minimalist
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
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error statting file");
        close(fd);
        return NULL;
    }

    off_t file_size = stat.st_size;
    off_t offset = 0;

    image_t *image = calloc(1, sizeof(image_t));
    image->data = calloc(1, file_size);

    if (file_size > 0) {
        read(fd, image->data, file_size);
    }

    close(fd);

    image->width = WIDTH;
    image->height = HEIGHT;

    return image;
}

void save_image(const char *filename, image_t *image) {
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    off_t file_size = image->width * image->height * 3; // 3 bytes per pixel (RGB)
    off_t offset = 0;

    if (file_size > 0) {
        write(fd, image->data, file_size);
    }

    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int x = x1 * image->width / WIDTH;
    int y = y1 * image->height / HEIGHT;
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx > 0 && dy > 0) {
        for (int i = 0; i < dx; i++) {
            image->data[y * image->width + x] = 255; // white
            x++;
        }

        for (int i = 0; i < dy; i++) {
            image->data[y * image->width + x] = 0; // black
            y++;
        }
    }
}

int main() {
    image_t *image = load_image("example.bmp");
    if (image == NULL) {
        return 1;
    }

    draw_line(image, 0, 0, WIDTH, HEIGHT);

    save_image("output.bmp", image);

    free(image->data);
    free(image);

    return 0;
}