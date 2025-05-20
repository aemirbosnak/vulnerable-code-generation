//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    int num_pixels;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->num_pixels = width * height;
    image->data = malloc(image->num_pixels);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    int width, height;
    if (fscanf(file, "P2 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Error: invalid image header\n");
        fclose(file);
        return NULL;
    }

    Image *image = new_image(width, height);
    for (int i = 0; i < image->num_pixels; i++) {
        if (fscanf(file, "%hhu\n", &image->data[i]) != 1) {
            fprintf(stderr, "Error: invalid image data\n");
            fclose(file);
            free_image(image);
            return NULL;
        }
    }

    fclose(file);
    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fprintf(file, "P2 %d %d\n", image->width, image->height);
    for (int i = 0; i < image->num_pixels; i++) {
        fprintf(file, "%hhu\n", image->data[i]);
    }

    fclose(file);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->num_pixels; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void blur_image(Image *image, int radius) {
    int new_width = image->width + 2 * radius;
    int new_height = image->height + 2 * radius;
    int new_num_pixels = new_width * new_height;

    char *new_data = malloc(new_num_pixels);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int sum = 0;
            int count = 0;

            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    int offset_x = x + i;
                    int offset_y = y + j;

                    if (offset_x >= 0 && offset_x < new_width && offset_y >= 0 && offset_y < new_height) {
                        sum += image->data[offset_y * image->width + offset_x];
                        count++;
                    }
                }
            }

            new_data[y * new_width + x] = sum / count;
        }
    }

    free(image->data);
    image->data = new_data;
    image->width = new_width;
    image->height = new_height;
    image->num_pixels = new_num_pixels;
}

void print_image(const Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    invert_image(image);
    blur_image(image, 1);

    save_image(image, argv[2]);
    free_image(image);

    return 0;
}