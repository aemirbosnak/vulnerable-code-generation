//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define MAX_IMAGE_SIZE 1024 * 1024
#define MAX_BRUSH_SIZE 32

typedef struct {
    char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *name;
    int x;
    int y;
    int size;
} Brush;

Image *load_image(const char *file_name) {
    Image *image = malloc(sizeof(Image));
    int fd = open(file_name, O_RDONLY);
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
    image->width = file_stat.st_size / 3;
    image->height = file_stat.st_size % 3;
    image->data = malloc(image->width * image->height * 3);
    if (image->data == NULL) {
        perror("Error allocating memory for image data");
        close(fd);
        return NULL;
    }
    size_t bytes_read = read(fd, image->data, image->width * image->height * 3);
    if (bytes_read != image->width * image->height * 3) {
        perror("Error reading file");
        close(fd);
        return NULL;
    }
    close(fd);
    return image;
}

Brush *load_brush(const char *file_name) {
    Brush *brush = malloc(sizeof(Brush));
    int fd = open(file_name, O_RDONLY);
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
    brush->name = malloc(strlen(file_name) + 1);
    strcpy(brush->name, file_name);
    brush->x = 0;
    brush->y = 0;
    brush->size = file_stat.st_size;
    close(fd);
    return brush;
}

void draw_image(Image *image, Brush *brush) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int pixel = 0;
            for (int i = 0; i < brush->size; i++) {
                pixel += (image->data[y * image->width * 3 + x * 3 + i] >> i) & 1;
            }
            image->data[y * image->width * 3 + x * 3] = pixel;
        }
    }
}

void save_image(Image *image, const char *file_name) {
    int fd = open(file_name, O_WRONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    write(fd, image->data, image->width * image->height * 3);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image_file> <brush_file>\n", argv[0]);
        return 1;
    }
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error loading image %s\n", argv[1]);
        return 2;
    }
    Brush *brush = load_brush(argv[2]);
    if (brush == NULL) {
        fprintf(stderr, "Error loading brush %s\n", argv[2]);
        return 2;
    }
    draw_image(image, brush);
    save_image(image, argv[1]);
    return 0;
}