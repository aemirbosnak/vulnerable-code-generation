//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *load_image(const char *filename);
void save_image(const char *filename, Image *image);
Image *flip_image(Image *image);
Image *adjust_brightness_contrast(Image *image, int brightness, float contrast);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file_flip> <output_file_brightness> <brightness_value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file_flip = argv[2];
    const char *output_file_brightness = argv[3];
    int brightness = atoi(argv[4]);

    Image *image = load_image(input_file);
    if (!image) {
        return EXIT_FAILURE;
    }

    Image *flipped_image = flip_image(image);
    save_image(output_file_flip, flipped_image);

    Image *bright_image = adjust_brightness_contrast(image, brightness, 1.0f); // No contrast adjustment
    save_image(output_file_brightness, bright_image);

    free_image(image);
    free_image(flipped_image);
    free_image(bright_image);

    return EXIT_SUCCESS;
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PNM format: %s\n", header);
        fclose(file);
        return NULL;
    }

    int width, height, max_value;
    fscanf(file, "%d %d %d", &width, &height, &max_value);
    fgetc(file); // Read the newline character

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(Pixel) * width * height);

    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

Image *flip_image(Image *image) {
    Image *flipped_image = malloc(sizeof(Image));
    flipped_image->width = image->width;
    flipped_image->height = image->height;
    flipped_image->data = malloc(sizeof(Pixel) * image->width * image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            flipped_image->data[y * image->width + (image->width - 1 - x)] = image->data[y * image->width + x];
        }
    }
    return flipped_image;
}

Image *adjust_brightness_contrast(Image *image, int brightness, float contrast) {
    Image *new_image = malloc(sizeof(Image));
    new_image->width = image->width;
    new_image->height = image->height;
    new_image->data = malloc(sizeof(Pixel) * image->width * image->height);

    for (int i = 0; i < image->width * image->height; i++) {
        int r = image->data[i].r + brightness;
        int g = image->data[i].g + brightness;
        int b = image->data[i].b + brightness;

        r = ((r - 128) * contrast) + 128;
        g = ((g - 128) * contrast) + 128;
        b = ((b - 128) * contrast) + 128;

        new_image->data[i].r = r < 0 ? 0 : (r > 255 ? 255 : r);
        new_image->data[i].g = g < 0 ? 0 : (g > 255 ? 255 : g);
        new_image->data[i].b = b < 0 ? 0 : (b > 255 ? 255 : b);
    }
    return new_image;
}

void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}