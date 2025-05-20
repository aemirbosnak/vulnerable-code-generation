//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

image_t *
image_new(int width, int height)
{
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (!image->data) {
        free(image);
        return NULL;
    }

    return image;
}

void
image_free(image_t *image)
{
    free(image->data);
    free(image);
}

int
image_set_pixel(image_t *image, int x, int y, char c)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return -1;
    }

    image->data[y * image->width + x] = c;
    return 0;
}

char
image_get_pixel(image_t *image, int x, int y)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return 0;
    }

    return image->data[y * image->width + x];
}

int
image_load(image_t *image, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    fscanf(fp, "%d %d", &image->width, &image->height);

    image->data = malloc(image->width * image->height);
    if (!image->data) {
        fclose(fp);
        return -1;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fscanf(fp, " %c", &image->data[y * image->width + x]);
        }
    }

    fclose(fp);
    return 0;
}

int
image_save(image_t *image, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        return -1;
    }

    fprintf(fp, "%d %d\n", image->width, image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(fp, " %c", image->data[y * image->width + x]);
        }
    }

    fclose(fp);
    return 0;
}

int
main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    image_t *image = image_new(MAX_WIDTH, MAX_HEIGHT);
    if (!image) {
        fprintf(stderr, "Failed to create image\n");
        return 1;
    }

    if (image_load(image, argv[1]) != 0) {
        fprintf(stderr, "Failed to load image\n");
        image_free(image);
        return 1;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            char c = image_get_pixel(image, x, y);
            if (c == ' ') {
                c = '.';
            } else if (c == '#') {
                c = '@';
            } else if (c == '@') {
                c = '#';
            } else if (c == '.') {
                c = ' ';
            }
            image_set_pixel(image, x, y, c);
        }
    }

    if (image_save(image, argv[2]) != 0) {
        fprintf(stderr, "Failed to save image\n");
        image_free(image);
        return 1;
    }

    image_free(image);
    return 0;
}