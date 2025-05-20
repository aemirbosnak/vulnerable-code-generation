//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *pixels;
} Image;

Image *create_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for image.\n");
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(unsigned char));
    if (image->pixels == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for image pixels.\n");
        free(image);
        return NULL;
    }

    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

bool load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open image file.\n");
        return false;
    }

    fread(&image->width, sizeof(unsigned int), 1, file);
    fread(&image->height, sizeof(unsigned int), 1, file);

    image->pixels = malloc(image->width * image->height * sizeof(unsigned char));
    if (image->pixels == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for image pixels.\n");
        fclose(file);
        return false;
    }

    fread(image->pixels, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return true;
}

bool save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open image file.\n");
        return false;
    }

    fwrite(&image->width, sizeof(unsigned int), 1, file);
    fwrite(&image->height, sizeof(unsigned int), 1, file);

    fwrite(image->pixels, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return true;
}

void print_image(Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            printf("%u ", image->pixels[y * image->width + x]);
        }
        printf("\n");
    }
}
int main() {
    Image *image = create_image(640, 480);
    if (image == NULL) {
        return 1;
    }

    if (!load_image(image, "image.bmp")) {
        destroy_image(image);
        return 1;
    }

    print_image(image);

    destroy_image(image);

    return 0;
}