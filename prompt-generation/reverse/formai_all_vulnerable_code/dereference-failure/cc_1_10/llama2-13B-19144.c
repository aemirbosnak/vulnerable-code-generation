//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int width;
    int height;
    unsigned char* data;
} image_t;

image_t* load_image(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error statting file");
        close(fd);
        return NULL;
    }

    image_t* image = malloc(sizeof(image_t));
    image->width = file_stat.st_size / 3;
    image->height = file_stat.st_size / 3 * 4;
    image->data = mmap(NULL, image->width * image->height * 3, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return NULL;
    }

    close(fd);
    return image;
}

void draw_line(image_t* image, int x1, int y1, int x2, int y2) {
    int x3 = x2;
    int y3 = y1;
    while (x3 >= 0 && x3 < image->width && y3 >= 0 && y3 < image->height) {
        image->data[(y3 * image->width * 3) + (x3 * 3)] = (x3 == x1) ? 0xFF : 0x00;
        image->data[(y3 * image->width * 3) + (x3 * 3) + 1] = (y3 == y1) ? 0xFF : 0x00;
        image->data[(y3 * image->width * 3) + (x3 * 3) + 2] = (x3 == x2) ? 0xFF : 0x00;
        x3++;
    }
}

void draw_rectangle(image_t* image, int x, int y, int width, int height) {
    for (int i = 0; i < width; i++) {
        draw_line(image, x, y, x + i, y + height);
    }
}

void draw_circle(image_t* image, int x, int y, int radius) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;
    draw_line(image, x1, y1, x2, y2);
    draw_line(image, x1, y2, x2, y1);
    draw_line(image, x2, y1, x1, y2);
    draw_line(image, x2, y2, x1, y1);
}

void save_image(image_t* image, const char* filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    if (mmap(NULL, image->width * image->height * 3, PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0) == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int pixel = image->data[i * image->width * 3 + j * 3];
            write(fd, &pixel, 3);
        }
    }

    munmap(image->data, image->width * image->height * 3);
    close(fd);
}

int main() {
    image_t* image = load_image("image.bmp");
    if (image == NULL) {
        perror("Error loading image");
        return 1;
    }

    draw_rectangle(image, 100, 100, 200, 100);
    draw_circle(image, 200, 200, 50);

    save_image(image, "output.bmp");

    munmap(image->data, image->width * image->height * 3);
    free(image);

    return 0;
}