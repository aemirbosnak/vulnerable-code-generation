//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    uint8_t *data;
    int width;
    int height;
    int channels;
} Image;

// Load an image from a file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Read the header
    uint16_t magic;
    fread(&magic, sizeof(magic), 1, file);
    if (magic != 0x4D42) {
        fprintf(stderr, "Error: Invalid file format\n");
        fclose(file);
        return NULL;
    }

    uint32_t size;
    fread(&size, sizeof(size), 1, file);

    uint32_t offset;
    fread(&offset, sizeof(offset), 1, file);

    // Read the image data
    fseek(file, offset, SEEK_SET);
    uint8_t *data = malloc(size);
    fread(data, size, 1, file);

    fclose(file);

    // Create an image struct
    Image *image = malloc(sizeof(Image));
    image->data = data;
    image->width = size / 3;
    image->height = 1;
    image->channels = 3;

    return image;
}

// Free an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            uint8_t tmp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = tmp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            uint8_t tmp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = tmp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                int value = (int)image->data[y * image->width * image->channels + x * image->channels + c] + brightness;
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                image->data[y * image->width * image->channels + x * image->channels + c] = (uint8_t)value;
            }
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                float value = (float)image->data[y * image->width * image->channels + x * image->channels + c] * contrast;
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                image->data[y * image->width * image->channels + x * image->channels + c] = (uint8_t)value;
            }
        }
    }
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s for writing\n", filename);
        return;
    }

    // Write the header
    uint16_t magic = 0x4D42;
    fwrite(&magic, sizeof(magic), 1, file);

    uint32_t size = image->width * image->height * image->channels + 14;
    fwrite(&size, sizeof(size), 1, file);

    uint32_t offset = 14;
    fwrite(&offset, sizeof(offset), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);

    fclose(file);
}

// Main function
int main(void) {
    // Load an image
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the image
    save_image("new_image.bmp", image);

    // Free the image
    free_image(image);

    return 0;
}