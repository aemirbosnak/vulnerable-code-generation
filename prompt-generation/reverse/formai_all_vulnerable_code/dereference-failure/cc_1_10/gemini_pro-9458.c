//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int width, height;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }

    image->data = malloc(width * height * sizeof(char));
    if (image->data == NULL) {
        free(image);
        return NULL;
    }

    image->width = width;
    image->height = height;

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

int save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return -1;
    }

    fwrite(image->data, 1, image->width * image->height * sizeof(char), file);
    fclose(file);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return -1;
    }

    Image *image = new_image(640, 480);
    if (image == NULL) {
        printf("Error: Could not allocate memory for image.\n");
        return -1;
    }

    // Do something with the image here...

    int result = save_image(image, argv[2]);
    if (result != 0) {
        printf("Error: Could not save image.\n");
        return -1;
    }

    free_image(image);

    return 0;
}