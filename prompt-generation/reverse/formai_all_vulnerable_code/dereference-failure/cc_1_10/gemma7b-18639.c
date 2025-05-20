//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *image_load(char *filename) {
    Image *image = malloc(sizeof(Image));

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    image->data = (unsigned char *)malloc(MAX_IMAGE_SIZE);
    image->width = image->height = 0;

    // Read image header information
    image->width = fread(&image->width, sizeof(int), 1, file);
    image->height = fread(&image->height, sizeof(int), 1, file);

    // Read image data
    fread(image->data, MAX_IMAGE_SIZE, 1, file);

    fclose(file);

    return image;
}

void image_save(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write image header information
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write image data
    fwrite(image->data, MAX_IMAGE_SIZE, 1, file);

    fclose(file);
}

int main() {
    Image *image = image_load("image.jpg");
    image_save(image, "image_edited.jpg");

    free(image->data);
    free(image);

    return 0;
}