//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the image data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Read the image dimensions
    int width = * (int *) &header[18];
    int height = * (int *) &header[22];

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height * 3, file);

    // Close the file
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

    // Write the image header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    * (int *) &header[18] = image->width;
    * (int *) &header[22] = image->height;

    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * 3, file);

    // Close the file
    fclose(file);
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + (image->width - j - 1)];
            image->data[i * image->width + (image->width - j - 1)] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int r = image->data[i * image->width + j * 3];
            int g = image->data[i * image->width + j * 3 + 1];
            int b = image->data[i * image->width + j * 3 + 2];

            r += brightness;
            g += brightness;
            b += brightness;

            r = r > 255 ? 255 : r;
            g = g > 255 ? 255 : g;
            b = b > 255 ? 255 : b;

            image->data[i * image->width + j * 3] = r;
            image->data[i * image->width + j * 3 + 1] = g;
            image->data[i * image->width + j * 3 + 2] = b;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, int contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int r = image->data[i * image->width + j * 3];
            int g = image->data[i * image->width + j * 3 + 1];
            int b = image->data[i * image->width + j * 3 + 2];

            r = factor * (r - 128) + 128;
            g = factor * (g - 128) + 128;
            b = factor * (b - 128) + 128;

            r = r > 255 ? 255 : r;
            g = g > 255 ? 255 : g;
            b = b > 255 ? 255 : b;

            image->data[i * image->width + j * 3] = r;
            image->data[i * image->width + j * 3 + 1] = g;
            image->data[i * image->width + j * 3 + 2] = b;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified an input image file
    if (argc < 2) {
        fprintf(stderr, "Error: no input image file specified\n");
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flip_image_vertical(image);

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 50);

    // Save the output image
    save_image("output.bmp", image);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}