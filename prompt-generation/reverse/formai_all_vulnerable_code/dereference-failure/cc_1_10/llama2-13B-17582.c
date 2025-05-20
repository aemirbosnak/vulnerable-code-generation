//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32

typedef struct {
    unsigned char *data;
    size_t width, height;
} image_t;

image_t *load_image(const char *filename) {
    image_t *image = malloc(sizeof(image_t));
    image->data = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (image->data == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    image->width = WIDTH;
    image->height = HEIGHT;
    if (load_image_from_file(filename, image) < 0) {
        munmap(image->data, WIDTH * HEIGHT * BPP);
        return NULL;
    }
    return image;
}

int load_image_from_file(const char *filename, image_t *image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return -1;
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    if (file_size != WIDTH * HEIGHT * BPP) {
        fprintf(stderr, "File size mismatch: expected %zu, got %zu\n", WIDTH * HEIGHT * BPP, file_size);
        return -1;
    }
    image->data = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (image->data == MAP_FAILED) {
        perror("mmap");
        return -1;
    }
    size_t bytes_read = fread(image->data, 1, WIDTH * HEIGHT * BPP, file);
    if (bytes_read != WIDTH * HEIGHT * BPP) {
        fprintf(stderr, "Error reading file: only read %zu bytes out of %zu\n", bytes_read, WIDTH * HEIGHT * BPP);
        munmap(image->data, WIDTH * HEIGHT * BPP);
        return -1;
    }
    fclose(file);
    return 0;
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = dy > dx;
    if (steep) {
        dx = x2 - x1;
        dy = y2 - y1;
    }
    for (int x = x1; x <= x2; x++) {
        image->data[x * HEIGHT * BPP + y1 * BPP] = (x == x1) ? 0xFF : 0x00;
        image->data[x * HEIGHT * BPP + y2 * BPP] = (x == x2) ? 0xFF : 0x00;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image->data[i * WIDTH * BPP + j * BPP] = (i == y && j == x) ? 0xFF : 0x00;
        }
    }
}

void save_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return;
    }
    fwrite(image->data, 1, WIDTH * HEIGHT * BPP, file);
    fclose(file);
}

int main() {
    image_t *image = load_image("example.bmp");
    if (!image) {
        perror("load_image");
        return 1;
    }
    draw_line(image, 10, 10, 30, 30);
    draw_rectangle(image, 20, 20, 40, 40);
    save_image(image, "output.bmp");
    munmap(image->data, WIDTH * HEIGHT * BPP);
    return 0;
}