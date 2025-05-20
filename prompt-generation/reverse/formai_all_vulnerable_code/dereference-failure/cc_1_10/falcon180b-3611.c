//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

void load_image(const char *filename, image_t *image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    image->data = malloc(size);
    fread(image->data, size, 1, file);

    fclose(file);

    image->width = *(int *) image->data;
    image->height = *(int *) (image->data + sizeof(int));
}

void save_image(const char *filename, const image_t *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    int width = image->width;
    int height = image->height;

    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(image->data + sizeof(int) * 2, width * height, 1, file);

    fclose(file);
}

void apply_filter(image_t *image, int (*filter)(int)) {
    int width = image->width;
    int height = image->height;
    char *data = image->data + sizeof(int) * 2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int offset = (y * width + x) * 3;
            *(data + offset) = filter(*(data + offset));
            *(data + offset + 1) = filter(*(data + offset + 1));
            *(data + offset + 2) = filter(*(data + offset + 2));
        }
    }
}

int grayscale_filter(int value) {
    return (value >> 16 & 0xff) + (value >> 8 & 0xff) + (value & 0xff);
}

int main() {
    image_t image;

    load_image("input.bmp", &image);

    apply_filter(&image, grayscale_filter);

    save_image("output.bmp", &image);

    free(image.data);

    return 0;
}