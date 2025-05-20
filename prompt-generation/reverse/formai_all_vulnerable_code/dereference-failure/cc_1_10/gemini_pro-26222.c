//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    if (!image) {
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (!image->data) {
        free(image);
        return NULL;
    }
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

int load_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }
    size_t bytes_read = fread(image->data, 1, image->width * image->height, file);
    fclose(file);
    return bytes_read == image->width * image->height ? 0 : -1;
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void print_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input image> <output text>\n", argv[0]);
        return 1;
    }
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);
    if (!image) {
        return 1;
    }
    if (load_image(image, argv[1]) < 0) {
        printf("Failed to load image: %s\n", argv[1]);
        return 1;
    }
    FILE *file = fopen(argv[2], "w");
    if (!file) {
        printf("Failed to open output file: %s\n", argv[2]);
        return 1;
    }
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int c = image->data[y * image->width + x];
            fprintf(file, "%c", c > 127 ? '#' : ' ');
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}