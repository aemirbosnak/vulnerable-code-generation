//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *pixels;
} image_t;

image_t *image_new(int width, int height)
{
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(pixel_t));
    if (!image->pixels) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return NULL;
    }

    return image;
}

void image_free(image_t *image)
{
    free(image->pixels);
    free(image);
}

int image_load(image_t *image, const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    int n = read(fd, image->pixels, image->width * image->height * sizeof(pixel_t));
    if (n < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    close(fd);

    return 0;
}

int image_save(image_t *image, const char *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    int n = write(fd, image->pixels, image->width * image->height * sizeof(pixel_t));
    if (n < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    close(fd);

    return 0;
}

void image_invert(image_t *image)
{
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

void image_grayscale(image_t *image)
{
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}

void image_rotate(image_t *image, double angle)
{
    double radians = angle * M_PI / 180.0;
    double sin_theta = sin(radians);
    double cos_theta = cos(radians);

    image_t *new_image = image_new(image->height, image->width);
    if (!new_image) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_x = (int)(x * cos_theta - y * sin_theta + image->width / 2.0);
            int new_y = (int)(x * sin_theta + y * cos_theta + image->height / 2.0);

            if (new_x >= 0 && new_x < image->width && new_y >= 0 && new_y < image->height) {
                new_image->pixels[new_y * image->width + new_x] = image->pixels[y * image->width + x];
            }
        }
    }

    image_free(image);
    *image = *new_image;
    image_free(new_image);
}

void image_flip(image_t *image, bool horizontal)
{
    int i, j;
    pixel_t temp;

    if (horizontal) {
        for (i = 0; i < image->height; i++) {
            for (j = 0; j < image->width / 2; j++) {
                temp = image->pixels[i * image->width + j];
                image->pixels[i * image->width + j] = image->pixels[i * image->width + image->width - j - 1];
                image->pixels[i * image->width + image->width - j - 1] = temp;
            }
        }
    } else {
        for (i = 0; i < image->height / 2; i++) {
            for (j = 0; j < image->width; j++) {
                temp = image->pixels[i * image->width + j];
                image->pixels[i * image->width + j] = image->pixels[(image->height - i - 1) * image->width + j];
                image->pixels[(image->height - i - 1) * image->width + j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    image_t *image = image_new(WIDTH, HEIGHT);
    if (!image) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    if (image_load(image, argv[1]) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // TODO: Apply image operations here

    if (image_save(image, argv[2]) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    image_free(image);

    return 0;
}