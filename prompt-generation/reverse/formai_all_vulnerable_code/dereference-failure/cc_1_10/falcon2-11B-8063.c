//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

#define MAX_LINE_SIZE 10000
#define MAX_WIDTH 200
#define MAX_HEIGHT 200

#define GRAY_MAX 255
#define GRAY_MIN 0

typedef struct {
    int width;
    int height;
    int depth;
    int size;
    int *data;
} image;

image *load_image(char *filename) {
    image *image = malloc(sizeof(image));
    if (!image) {
        fprintf(stderr, "Error: Unable to allocate memory for image.\n");
        return NULL;
    }
    image->width = 0;
    image->height = 0;
    image->depth = 0;
    image->size = 0;
    image->data = NULL;

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file '%s'.\n", filename);
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    int num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (strncmp(line, "width", 5) == 0) {
            sscanf(line, "width %d", &image->width);
        } else if (strncmp(line, "height", 6) == 0) {
            sscanf(line, "height %d", &image->height);
        } else if (strncmp(line, "depth", 5) == 0) {
            sscanf(line, "depth %d", &image->depth);
        } else if (strncmp(line, "size", 4) == 0) {
            sscanf(line, "size %d", &image->size);
        } else {
            continue;
        }
        num_lines++;
    }

    if (num_lines!= 4) {
        fprintf(stderr, "Error: Incorrect number of lines in file '%s'.\n", filename);
        return NULL;
    }

    image->data = malloc(image->size * sizeof(int));
    if (!image->data) {
        fprintf(stderr, "Error: Unable to allocate memory for image data.\n");
        return NULL;
    }

    for (int i = 0; i < image->size; i++) {
        image->data[i] = 0;
    }

    fclose(file);

    return image;
}

void free_image(image *image) {
    if (!image) {
        return;
    }
    free(image->data);
    free(image);
}

int main() {
    image *original = load_image("input.ppm");
    if (!original) {
        fprintf(stderr, "Error: Failed to load image from 'input.ppm'.\n");
        return 1;
    }

    image *flipped = load_image("flipped.ppm");
    if (!flipped) {
        fprintf(stderr, "Error: Failed to load image from 'flipped.ppm'.\n");
        return 1;
    }

    image *brightness_changed = load_image("brightness_changed.ppm");
    if (!brightness_changed) {
        fprintf(stderr, "Error: Failed to load image from 'brightness_changed.ppm'.\n");
        return 1;
    }

    image *contrast_changed = load_image("contrast_changed.ppm");
    if (!contrast_changed) {
        fprintf(stderr, "Error: Failed to load image from 'contrast_changed.ppm'.\n");
        return 1;
    }

    image *resized = load_image("resized.ppm");
    if (!resized) {
        fprintf(stderr, "Error: Failed to load image from'resized.ppm'.\n");
        return 1;
    }

    free_image(original);
    free_image(flipped);
    free_image(brightness_changed);
    free_image(contrast_changed);
    free_image(resized);

    return 0;
}