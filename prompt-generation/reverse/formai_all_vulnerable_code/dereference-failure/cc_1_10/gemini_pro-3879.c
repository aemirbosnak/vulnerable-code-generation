//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Read an image from a file
Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    // Return the image
    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        free(data);
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = data;
    return image;
}

// Write an image to a file
void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0
    };
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char tmp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - 1 - j];
            image->data[i * image->width + image->width - 1 - j] = tmp;
        }
    }
}

// Flip an image vertically
void flip_vertically(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char tmp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - 1 - i) * image->width + j];
            image->data[(image->height - 1 - i) * image->width + j] = tmp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int r = image->data[i * image->width + j * 3 + 0];
            int g = image->data[i * image->width + j * 3 + 1];
            int b = image->data[i * image->width + j * 3 + 2];

            r += brightness;
            g += brightness;
            b += brightness;

            r = r < 0 ? 0 : r;
            r = r > 255 ? 255 : r;
            g = g < 0 ? 0 : g;
            g = g > 255 ? 255 : g;
            b = b < 0 ? 0 : b;
            b = b > 255 ? 255 : b;

            image->data[i * image->width + j * 3 + 0] = r;
            image->data[i * image->width + j * 3 + 1] = g;
            image->data[i * image->width + j * 3 + 2] = b;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int r = image->data[i * image->width + j * 3 + 0];
            int g = image->data[i * image->width + j * 3 + 1];
            int b = image->data[i * image->width + j * 3 + 2];

            r = (r - 128) * contrast + 128;
            g = (g - 128) * contrast + 128;
            b = (b - 128) * contrast + 128;

            r = r < 0 ? 0 : r;
            r = r > 255 ? 255 : r;
            g = g < 0 ? 0 : g;
            g = g > 255 ? 255 : g;
            b = b < 0 ? 0 : b;
            b = b > 255 ? 255 : b;

            image->data[i * image->width + j * 3 + 0] = r;
            image->data[i * image->width + j * 3 + 1] = g;
            image->data[i * image->width + j * 3 + 2] = b;
        }
    }
}

int main() {
    // Read an image from a file
    Image *image = read_image("input.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontally(image);

    // Flip the image vertically
    flip_vertically(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Write the image to a file
    write_image(image, "output.bmp");

    // Free the image memory
    free(image->data);
    free(image);

    return 0;
}