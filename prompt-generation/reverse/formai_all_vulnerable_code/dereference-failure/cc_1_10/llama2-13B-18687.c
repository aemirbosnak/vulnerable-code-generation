//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define IMAGE_PATH "example.bmp"

typedef struct {
    unsigned char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    struct stat stat_info;
    if (fstat(fd, &stat_info) == -1) {
        perror("Error stat'ing file");
        close(fd);
        return NULL;
    }

    int image_size = stat_info.st_size;
    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        perror("Error allocating memory");
        close(fd);
        return NULL;
    }

    ssize_t read_size = read(fd, image_data, image_size);
    if (read_size == -1) {
        perror("Error reading file");
        free(image_data);
        close(fd);
        return NULL;
    }

    close(fd);

    image_t *image = malloc(sizeof(image_t));
    image->data = image_data;
    image->width = stat_info.st_size / BITS_PER_PIXEL / WIDTH;
    image->height = stat_info.st_size / BITS_PER_PIXEL / HEIGHT;

    return image;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int x = x1 * BITS_PER_PIXEL / WIDTH;
    int y = y1 * BITS_PER_PIXEL / HEIGHT;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = abs(dy) > abs(dx);
    int y_step = steep ? dy : dx;
    int x_step = steep ? dx : dy;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            image->data[(i * BITS_PER_PIXEL / WIDTH + j * BITS_PER_PIXEL / HEIGHT) * BITS_PER_PIXEL] = (i == x1 && j == y1) ? 0xFF000000 : 0x00000000;
        }
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    for (int i = x; i <= x + width; i++) {
        for (int j = y; j <= y + height; j++) {
            draw_line(image, i, j, i, j + height);
        }
    }
}

void draw_circle(image_t *image, int x, int y, int radius) {
    int fx = x - radius;
    int fy = y - radius;
    int cx = x + radius;
    int cy = y + radius;

    int x_step = abs(fx) > abs(cx) ? 1 : -1;
    int y_step = abs(fy) > abs(cy) ? 1 : -1;

    for (int i = x; i <= cx; i++) {
        for (int j = y; j <= cy; j++) {
            int distance = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (distance <= radius) {
                image->data[(i * BITS_PER_PIXEL / WIDTH + j * BITS_PER_PIXEL / HEIGHT) * BITS_PER_PIXEL] = 0xFF000000;
            }
        }
    }
}

void save_image(image_t *image, const char *path) {
    int fd = open(path, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    mprotect(image->data, image->width * image->height * BITS_PER_PIXEL, PROT_READ | PROT_WRITE);
    msync(image->data, image->width * image->height * BITS_PER_PIXEL, MS_SYNC);

    write(fd, image->data, image->width * image->height * BITS_PER_PIXEL);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <image_path>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image %s\n", argv[1]);
        return 2;
    }

    draw_rectangle(image, 10, 10, 300, 200);
    draw_circle(image, 200, 200, 100);

    save_image(image, "output.bmp");

    free(image->data);
    free(image);

    return 0;
}