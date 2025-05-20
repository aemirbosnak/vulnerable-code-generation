//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char **pixels;
} Image;

Image* read_image(const char *filename) {
    Image *image = malloc(sizeof(Image));

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'.\n", filename);
        return NULL;
    }

    fscanf(file, "%d %d", &image->width, &image->height);
    if (image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image is too large (%d x %d).\n", image->width, image->height);
        fclose(file);
        free(image);
        return NULL;
    }

    image->pixels = malloc(sizeof(char *) * image->height);
    for (int i = 0; i < image->height; i++) {
        image->pixels[i] = malloc(sizeof(char) * image->width);
        fread(image->pixels[i], sizeof(char), image->width, file);
    }

    fclose(file);

    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void print_image(const Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->pixels[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    print_image(image);

    free_image(image);

    return EXIT_SUCCESS;
}