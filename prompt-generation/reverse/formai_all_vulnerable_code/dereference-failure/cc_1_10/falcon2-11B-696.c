//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int size;
    int* data;
} Image;

void create_image(Image* image, int width, int height, int size) {
    image->width = width;
    image->height = height;
    image->size = size;
    image->data = malloc(image->size * image->width);
}

void free_image(Image* image) {
    free(image->data);
    image->data = NULL;
}

void print_image(Image image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            printf("%d ", image.data[i * image.size + j]);
        }
        printf("\n");
    }
}

int main() {
    Image image;
    create_image(&image, 3, 3, 3);
    image.data[0 * image.size + 0] = 1;
    image.data[0 * image.size + 1] = 2;
    image.data[0 * image.size + 2] = 3;
    image.data[1 * image.size + 0] = 4;
    image.data[1 * image.size + 1] = 5;
    image.data[1 * image.size + 2] = 6;
    image.data[2 * image.size + 0] = 7;
    image.data[2 * image.size + 1] = 8;
    image.data[2 * image.size + 2] = 9;

    printf("Original Image:\n");
    print_image(image);

    image.data[0 * image.size + 0] = 1;
    image.data[0 * image.size + 1] = 2;
    image.data[0 * image.size + 2] = 3;
    image.data[1 * image.size + 0] = 4;
    image.data[1 * image.size + 1] = 5;
    image.data[1 * image.size + 2] = 6;
    image.data[2 * image.size + 0] = 7;
    image.data[2 * image.size + 1] = 8;
    image.data[2 * image.size + 2] = 9;

    printf("Modified Image:\n");
    print_image(image);

    free_image(&image);

    return 0;
}