//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fscanf(fp, "P5 %d %d 255\n", &width, &height);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);

    // Read the image data
    fread(image->data, 1, width * height, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    fprintf(fp, "P5 %d %d 255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, fp);

    // Close the file
    fclose(fp);
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            unsigned char temp = image->data[y * width + x];
            image->data[y * width + x] = image->data[y * width + width - x - 1];
            image->data[y * width + width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char temp = image->data[y * width + x];
            image->data[y * width + x] = image->data[(height - y - 1) * width + x];
            image->data[(height - y - 1) * width + x] = temp;
        }
    }
}

// Change the brightness of an image
void change_image_brightness(Image *image, int brightness) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = image->data[y * width + x] + brightness;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * width + x] = value;
        }
    }
}

// Change the contrast of an image
void change_image_contrast(Image *image, float contrast) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = (image->data[y * width + x] - 128) * contrast + 128;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * width + x] = value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> [<output image>]\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Change the image brightness
    change_image_brightness(image, 50);

    // Change the image contrast
    change_image_contrast(image, 1.2);

    // Save the output image
    if (argc >= 3) {
        save_image(argv[2], image);
    } else {
        save_image("output.pgm", image);
    }

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}