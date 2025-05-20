//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024

typedef struct ImageData {
    unsigned char *data;
    int width;
    int height;
} ImageData;

ImageData *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    ImageData *image = malloc(sizeof(ImageData));
    image->data = malloc(MAX_IMAGE_SIZE);

    int width = 0;
    int height = 0;
    fscanf(fp, "width: %d, height: %d", &width, &height);

    image->width = width;
    image->height = height;

    fread(image->data, MAX_IMAGE_SIZE, 1, fp);
    fclose(fp);

    return image;
}

void save_image(ImageData *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "width: %d, height: %d\n", image->width, image->height);
    fwrite(image->data, MAX_IMAGE_SIZE, 1, fp);
    fclose(fp);
}

int main() {
    ImageData *image = load_image("image.jpg");

    // Modify image data here

    save_image(image, "image_edited.jpg");

    free(image->data);
    free(image);

    return 0;
}