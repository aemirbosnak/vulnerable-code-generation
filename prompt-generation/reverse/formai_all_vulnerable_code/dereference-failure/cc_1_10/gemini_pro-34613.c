//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(unsigned int), 1, file);
    fread(&image->height, sizeof(unsigned int), 1, file);

    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

void free_image(image_t *image) {
    if (image) {
        if (image->data) {
            free(image->data);
        }
        free(image);
    }
}

void flip_image_horizontal(image_t *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

void flip_image_vertical(image_t *image) {
    for (unsigned int y = 0; y < image->height / 2; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void change_brightness_contrast(image_t *image, double brightness, double contrast) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] + brightness;
            value = value * contrast;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

void save_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(unsigned int), 1, file);
    fwrite(&image->height, sizeof(unsigned int), 1, file);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <flip horizontal/vertical> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    if (strcmp(argv[3], "horizontal") == 0) {
        flip_image_horizontal(image);
    } else if (strcmp(argv[3], "vertical") == 0) {
        flip_image_vertical(image);
    } else {
        fprintf(stderr, "Error: invalid flip direction %s\n", argv[3]);
        free_image(image);
        return 1;
    }

    double brightness = atof(argv[4]);
    double contrast = atof(argv[5]);
    change_brightness_contrast(image, brightness, contrast);

    save_image(image, argv[2]);

    free_image(image);

    return 0;
}