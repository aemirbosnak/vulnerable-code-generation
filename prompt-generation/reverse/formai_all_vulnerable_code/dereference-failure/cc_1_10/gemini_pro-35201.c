//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scientific
// A simple C program for basic image processing tasks
// including flipping, brightness/contrast adjustment

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read header information
    unsigned char header[54];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP image\n", filename);
        fclose(file);
        return NULL;
    }

    // Extract image dimensions and channels
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int channels = 3; // Assuming the image is RGB

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * channels);
    image->width = width;
    image->height = height;
    image->channels = channels;

    // Read image data
    fread(image->data, width * height * channels, 1, file);
    fclose(file);

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write header information
    unsigned char header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };

    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, sizeof(header), 1, file);

    // Write image data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int c = 0; c < image->channels; c++) {
                unsigned char temp = image->data[(i * image->width + j) * image->channels + c];
                image->data[(i * image->width + j) * image->channels + c] = image->data[((image->height - 1 - i) * image->width + j) * image->channels + c];
                image->data[((image->height - 1 - i) * image->width + j) * image->channels + c] = temp;
            }
        }
    }
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            for (int c = 0; c < image->channels; c++) {
                unsigned char temp = image->data[(i * image->width + j) * image->channels + c];
                image->data[(i * image->width + j) * image->channels + c] = image->data[(i * image->width + (image->width - 1 - j)) * image->channels + c];
                image->data[(i * image->width + (image->width - 1 - j)) * image->channels + c] = temp;
            }
        }
    }
}

// Adjust the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, double brightness, double contrast) {
    // Convert brightness and contrast to a range of [0, 1]
    brightness = fmin(1.0, fmax(0.0, brightness));
    contrast = fmin(1.0, fmax(0.0, contrast));

    // Apply the brightness and contrast adjustments
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int c = 0; c < image->channels; c++) {
                // Calculate the adjusted pixel value
                double adjusted_value = image->data[(i * image->width + j) * image->channels + c] * contrast + brightness;

                // Clamp the adjusted value to the range [0, 255]
                image->data[(i * image->width + j) * image->channels + c] = (unsigned char)fmin(255.0, fmax(0.0, adjusted_value));
            }
        }
    }
}

int main() {
    // Load an image from a file
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flip_vertical(image);

    // Flip the image horizontally
    flip_horizontal(image);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(image, 0.5, 1.5);

    // Save the modified image to a file
    save_image("modified_image.bmp", image);

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}