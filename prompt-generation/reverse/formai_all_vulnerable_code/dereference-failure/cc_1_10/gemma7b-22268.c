//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024

typedef struct Image {
    int width, height;
    unsigned char *pixels;
} Image;

Image *load_image(char *filename) {
    Image *image = malloc(sizeof(Image));
    image->pixels = malloc(MAX_IMAGE_SIZE);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read image header
    image->width = fread(&image->width, sizeof(int), 1, file);
    image->height = fread(&image->height, sizeof(int), 1, file);

    // Read image pixels
    fread(image->pixels, MAX_IMAGE_SIZE, 1, file);

    fclose(file);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write image header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write image pixels
    fwrite(image->pixels, MAX_IMAGE_SIZE, 1, file);

    fclose(file);
}

int main() {
    Image *image = load_image("image.jpg");
    save_image(image, "image_edited.jpg");

    free(image->pixels);
    free(image);

    return 0;
}