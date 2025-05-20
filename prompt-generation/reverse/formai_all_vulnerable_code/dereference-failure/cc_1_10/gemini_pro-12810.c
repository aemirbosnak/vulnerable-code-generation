//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image dimensions
#define WIDTH 512
#define HEIGHT 512

// Image data type
typedef unsigned char pixel;

// Image struct
typedef struct {
    pixel *data;
    int width;
    int height;
} image;

// Load an image from a file
image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image *img = malloc(sizeof(image));
    img->data = malloc(width * height * sizeof(pixel));
    img->width = width;
    img->height = height;

    // Read the image data
    fread(img->data, sizeof(pixel), width * height, fp);

    // Close the file
    fclose(fp);

    return img;
}

// Save an image to a file
void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the image header
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    // Close the file
    fclose(fp);
}

// Flip an image horizontally
void flip_horizontal(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + img->width - 1 - x];
            img->data[y * img->width + img->width - 1 - x] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - 1 - y) * img->width + x];
            img->data[(img->height - 1 - y) * img->width + x] = temp;
        }
    }
}

// Adjust the brightness and contrast of an image
void adjust_brightness_contrast(image *img, float brightness, float contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel old_value = img->data[y * img->width + x];
            float new_value = (old_value - 128.0) * contrast + 128.0 + brightness;
            img->data[y * img->width + x] = (new_value < 0.0) ? 0.0 : (new_value > 255.0) ? 255.0 : new_value;
        }
    }
}

// Main function
int main() {
    // Load the input image
    image *img = load_image("input.bmp");
    if (!img) return 1;

    // Flip the image horizontally
    flip_horizontal(img);

    // Flip the image vertically
    flip_vertical(img);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(img, 50.0, 1.5);

    // Save the output image
    save_image(img, "output.bmp");

    // Free the memory allocated for the image
    free(img->data);
    free(img);

    return 0;
}