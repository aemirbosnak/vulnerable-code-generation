//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Image data structure
typedef struct {
    unsigned char *data;
    int width, height;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(f);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, 1, 18, f);
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(f);
        free(image);
        return NULL;
    }

    // Get the image dimensions
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fclose(f);
        free(image);
        return NULL;
    }

    // Read the image data
    fread(image->data, 1, image->width * image->height * 3, f);

    fclose(f);

    return image;
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            // Swap the pixels at (i, j) and (height - i - 1, j)
            unsigned char tmp = image->data[i * image->width * 3 + j * 3 + 0];
            image->data[i * image->width * 3 + j * 3 + 0] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 0];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 0] = tmp;

            tmp = image->data[i * image->width * 3 + j * 3 + 1];
            image->data[i * image->width * 3 + j * 3 + 1] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 1];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 1] = tmp;

            tmp = image->data[i * image->width * 3 + j * 3 + 2];
            image->data[i * image->width * 3 + j * 3 + 2] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 2];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 2] = tmp;
        }
    }
}

// Change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Adjust the brightness
            image->data[i * image->width * 3 + j * 3 + 0] = (int)round(image->data[i * image->width * 3 + j * 3 + 0] + brightness);
            image->data[i * image->width * 3 + j * 3 + 1] = (int)round(image->data[i * image->width * 3 + j * 3 + 1] + brightness);
            image->data[i * image->width * 3 + j * 3 + 2] = (int)round(image->data[i * image->width * 3 + j * 3 + 2] + brightness);

            // Adjust the contrast
            image->data[i * image->width * 3 + j * 3 + 0] = (int)round((image->data[i * image->width * 3 + j * 3 + 0] - 128) * contrast + 128);
            image->data[i * image->width * 3 + j * 3 + 1] = (int)round((image->data[i * image->width * 3 + j * 3 + 1] - 128) * contrast + 128);
            image->data[i * image->width * 3 + j * 3 + 2] = (int)round((image->data[i * image->width * 3 + j * 3 + 2] - 128) * contrast + 128);
        }
    }
}

// Save an image to a file
int save_image(const Image *image, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return -1;

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };

    *(int *)&header[2] = image->width * image->height * 3 + 54;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, 1, 18, f);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * 3, f);

    fclose(f);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input image> <flip> <brightness> <contrast>\n", argv[0]);
        return -1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading image: %s\n", argv[1]);
        return -1;
    }

    // Flip the image vertically
    if (strcmp(argv[2], "flip") == 0) {
        flip_vertical(image);
    }

    // Adjust the brightness and contrast
    float brightness = atof(argv[3]);
    float contrast = atof(argv[4]);
    adjust_brightness_contrast(image, brightness, contrast);

    // Save the output image
    char output_filename[256];
    sprintf(output_filename, "%s_modified.bmp", argv[1]);
    if (save_image(image, output_filename) != 0) {
        printf("Error saving image: %s\n", output_filename);
        return -1;
    }

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}