//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Assuming PPM format for simplicity
    char buf[16];
    int max_color;
    if (!fgets(buf, sizeof(buf), file)) {
        fprintf(stderr, "Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }

    if (buf[0] != 'P' || buf[1] != '6') {
        fprintf(stderr, "Invalid PPM file format\n");
        exit(EXIT_FAILURE);
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d %d", &image->width, &image->height, &max_color);
    fgetc(file); // consume the newline after max color

    image->data = malloc(sizeof(Pixel) * image->width * image->height);
    fread(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void flip_image_horizontally(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int opposite_x = image->width - x - 1;
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + opposite_x];
            image->data[y * image->width + opposite_x] = temp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        int r = image->data[i].r + brightness;
        int g = image->data[i].g + brightness;
        int b = image->data[i].b + brightness;

        image->data[i].r = r < 0 ? 0 : (r > 255 ? 255 : r);
        image->data[i].g = g < 0 ? 0 : (g > 255 ? 255 : g);
        image->data[i].b = b < 0 ? 0 : (b > 255 ? 255 : b);
    }
}

void adjust_contrast(Image *image, float factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = clip((int)(factor * (image->data[i].r - 128) + 128));
        image->data[i].g = clip((int)(factor * (image->data[i].g - 128) + 128));
        image->data[i].b = clip((int)(factor * (image->data[i].b - 128) + 128));
    }
}

int clip(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm brightness | contrast_factor\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);

    if (strcmp(argv[3], "brightness") == 0) {
        int brightness = atoi(argv[4]);
        change_brightness(image, brightness);
    } else {
        float contrast_factor = atof(argv[3]);
        adjust_contrast(image, contrast_factor);
    }

    flip_image_horizontally(image);
    save_image(argv[2], image);
    free_image(image);

    return EXIT_SUCCESS;
}