//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Image format
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Load image from file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read header
    int width, height, channels;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&channels, sizeof(int), 1, file);

    // Allocate memory for image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);

    // Read image data
    fread(image->data, sizeof(unsigned char), width * height * channels, file);

    fclose(file);

    return image;
}

// Save image to file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->channels, sizeof(int), 1, file);

    // Write image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * image->channels, file);

    fclose(file);
}

// Flip image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                unsigned char temp = image->data[(y * image->width + x) * image->channels + c];
                image->data[(y * image->width + x) * image->channels + c] = image->data[((image->height - y - 1) * image->width + x) * image->channels + c];
                image->data[((image->height - y - 1) * image->width + x) * image->channels + c] = temp;
            }
        }
    }
}

// Flip image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            for (int c = 0; c < image->channels; c++) {
                unsigned char temp = image->data[(y * image->width + x) * image->channels + c];
                image->data[(y * image->width + x) * image->channels + c] = image->data[(y * image->width + (image->width - x - 1)) * image->channels + c];
                image->data[(y * image->width + (image->width - x - 1)) * image->channels + c] = temp;
            }
        }
    }
}

// Change brightness of image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                int new_value = image->data[(y * image->width + x) * image->channels + c] + brightness;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[(y * image->width + x) * image->channels + c] = new_value;
            }
        }
    }
}

// Change contrast of image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                int new_value = (image->data[(y * image->width + x) * image->channels + c] - 127.5) * contrast + 127.5;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[(y * image->width + x) * image->channels + c] = new_value;
            }
        }
    }
}

// Main function
int main() {
    // Load image
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip image vertically
    flip_vertical(image);

    // Change brightness of image
    change_brightness(image, 50);

    // Change contrast of image
    change_contrast(image, 1.5);

    // Save image
    save_image("new_image.bmp", image);

    // Free memory
    free(image->data);
    free(image);

    return 0;
}