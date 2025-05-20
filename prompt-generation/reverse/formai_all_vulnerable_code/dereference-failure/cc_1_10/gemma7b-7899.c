//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image {
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *image_load(char *filename) {
    Image *image = malloc(sizeof(Image));
    image->pixels = NULL;

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    image->width = fread(image, sizeof(int), 1, file);
    image->height = fread(image, sizeof(int), 1, file);
    image->pixels = malloc(image->width * image->height * sizeof(unsigned char *));

    for (int y = 0; y < image->height; y++) {
        image->pixels[y] = malloc(image->width * sizeof(unsigned char));
        fread(image->pixels[y], image->width, sizeof(unsigned char), file);
    }

    fclose(file);
    return image;
}

void image_save(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    for (int y = 0; y < image->height; y++) {
        fwrite(image->pixels[y], image->width, sizeof(unsigned char), file);
        free(image->pixels[y]);
    }

    free(image->pixels);
    fclose(file);
}

int main() {
    Image *image = image_load("image.jpg");
    image_save(image, "image_edited.jpg");
    free(image);

    return 0;
}