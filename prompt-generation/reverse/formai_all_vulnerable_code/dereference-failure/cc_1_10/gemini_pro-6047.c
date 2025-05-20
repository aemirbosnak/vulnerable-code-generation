//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef unsigned char byte;
typedef struct {
    int width;
    int height;
    byte *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(byte));
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

int load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fread(image->data, sizeof(byte), image->width * image->height, file);

    fclose(file);
    return 0;
}

int save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, sizeof(byte), image->width * image->height, file);

    fclose(file);
    return 0;
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        byte gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void blur_image(Image *image, int radius) {
    int width = image->width;
    int height = image->height;
    byte *blurred_data = malloc(width * height * sizeof(byte));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            int count = 0;

            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        sum += image->data[ny * width + nx];
                        count++;
                    }
                }
            }

            blurred_data[y * width + x] = sum / count;
        }
    }

    memcpy(image->data, blurred_data, width * height * sizeof(byte));
    free(blurred_data);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = create_image(MAX_WIDTH, MAX_HEIGHT);
    if (!image) {
        printf("Failed to create image\n");
        return 1;
    }

    if (load_image(image, argv[1]) < 0) {
        printf("Failed to load image\n");
        return 1;
    }

    invert_image(image);
    grayscale_image(image);
    blur_image(image, 5);

    if (save_image(image, argv[2]) < 0) {
        printf("Failed to save image\n");
        return 1;
    }

    destroy_image(image);
    return 0;
}