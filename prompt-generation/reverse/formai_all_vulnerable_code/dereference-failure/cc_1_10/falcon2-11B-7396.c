//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int color_count;
    int* colors;
} image_t;

image_t* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    image_t* image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    image->width = 0;
    image->height = 0;
    image->color_count = 0;

    char* buffer = malloc(size);
    if (!buffer) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fread(buffer, 1, size, file)!= size) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    char* ptr = buffer;
    while (ptr < buffer + size) {
        int pixel_size = *ptr;
        if (pixel_size == 0) {
            break;
        }

        int pixel_count = *++ptr;
        if (pixel_count == 0) {
            break;
        }

        image->width += pixel_count;
        image->height += pixel_size;
        image->color_count += pixel_count * pixel_size;

        ptr += pixel_count * pixel_size;
    }

    image->colors = malloc(image->color_count * sizeof(int));
    if (!image->colors) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char* color_ptr = buffer + image->width * image->height;
    for (int i = 0; i < image->color_count; ++i) {
        int pixel_count = *--color_ptr;
        if (pixel_count == 0) {
            break;
        }

        for (int j = 0; j < pixel_count; ++j) {
            image->colors[i] = *--color_ptr;
        }
    }

    fclose(file);
    free(buffer);

    return image;
}

int main() {
    image_t* image = load_image("image.ppm");
    if (!image) {
        perror("load_image");
        exit(EXIT_FAILURE);
    }

    printf("Image loaded successfully\n");
    printf("Width: %d\n", image->width);
    printf("Height: %d\n", image->height);
    printf("Color count: %d\n", image->color_count);
    printf("Colors: ");
    for (int i = 0; i < image->color_count; ++i) {
        printf("%d ", image->colors[i]);
    }
    printf("\n");

    return 0;
}