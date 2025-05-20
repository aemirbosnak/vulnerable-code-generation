//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32

typedef struct {
    char name[32];
    unsigned short width, height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *filename) {
    image_t *img = malloc(sizeof(image_t));
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
    img->width = stat.st_size / WIDTH * BPP;
    img->height = stat.st_size / HEIGHT;
    img->data = mmap(NULL, stat.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img->data == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return NULL;
    }
    close(fd);
    return img;
}

void save_image(const char *filename, image_t *img) {
    int fd = open(filename, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }
    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        perror("Error statting file");
        close(fd);
        return;
    }
    if (stat.st_size != 0) {
        unlink(filename);
    }
    if (write(fd, img->data, img->width * img->height * BPP) == -1) {
        perror("Error writing to file");
        close(fd);
        return;
    }
    if (close(fd) == -1) {
        perror("Error closing file");
    }
}

void draw_point(image_t *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return;
    }
    if (img->data[y * img->width * BPP + x * BPP] == 0) {
        img->data[y * img->width * BPP + x * BPP] = 1;
    }
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= img->width || y1 < 0 || y1 >= img->height ||
            x2 < 0 || x2 >= img->width || y2 < 0 || y2 >= img->height) {
        return;
    }
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepx = x2 > x1 ? 1 : -1;
    int stepy = y2 > y1 ? 1 : -1;
    int x = x1;
    int y = y1;
    while (dx > 0 || dy > 0) {
        draw_point(img, x, y);
        if (dx > 0) {
            x += stepx;
            dx--;
        }
        if (dy > 0) {
            y += stepy;
            dy--;
        }
    }
}

int main() {
    image_t *img = load_image("image.bmp");
    if (img == NULL) {
        perror("Error loading image");
        return 1;
    }
    printf("Image dimensions: %dx%d\n", img->width, img->height);
    printf("Image data: ");
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%02x ", img->data[y * img->width * BPP + x * BPP]);
        }
        printf("\n");
    }
    printf("\n");
    draw_line(img, 100, 100, 200, 200);
    draw_line(img, 100, 200, 200, 100);
    save_image("output.bmp", img);
    return 0;
}