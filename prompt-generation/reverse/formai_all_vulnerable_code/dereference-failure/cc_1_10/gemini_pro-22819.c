//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header information
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Read the image dimensions
    int width = *((int *)&header[18]);
    int height = *((int *)&header[22]);

    // Allocate memory for the image data
    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, fp);

    // Close the file
    fclose(fp);

    // Create an Image struct and return it
    Image *image = (Image *)malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image struct\n");
        free(data);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to release memory allocated for an image
void release_image(Image *image) {
    if (!image) {
        return;
    }

    free(image->data);
    free(image);
}

// Function to flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_image_vertically(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = image->data[i * image->width * 3 + j * 3 + k] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjust_contrast(Image *image, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = (image->data[i * image->width * 3 + j * 3 + k] - 128) * contrast + 128;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

// Function to save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header information
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    *((int *)&header[2]) = sizeof(header) + image->width * image->height * 3;
    *((int *)&header[18]) = image->width;
    *((int *)&header[22]) = image->height;
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main() {
    // Load an image from a file
    Image *image = load_image("input.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontally(image);

    // Flip the image vertically
    flip_image_vertically(image);

    // Adjust the brightness of the image
    adjust_brightness(image, 50);

    // Adjust the contrast of the image
    adjust_contrast(image, 1.5);

    // Save the image to a file
    save_image("output.bmp", image);

    // Release memory allocated for the image
    release_image(image);

    return 0;
}