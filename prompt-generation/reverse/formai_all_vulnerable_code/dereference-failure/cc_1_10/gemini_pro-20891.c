//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 128
#define MAX_HEIGHT 64

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t *load_image(char *filename) {
    FILE *fp;
    int width, height;
    image_t *image;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    fscanf(fp, "%d %d\n", &width, &height);

    image = malloc(sizeof(image_t));
    image->data = malloc(width * height);
    image->width = width;
    image->height = height;

    fread(image->data, 1, width * height, fp);

    fclose(fp);

    return image;
}

void free_image(image_t *image) {
    free(image->data);
    free(image);
}

void print_image(image_t *image) {
    int x, y;

    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            printf("%c", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    image_t *image;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    image = load_image(argv[1]);
    if (image == NULL) {
        printf("Could not load image: %s\n", argv[1]);
        return 1;
    }

    print_image(image);

    free_image(image);

    return 0;
}