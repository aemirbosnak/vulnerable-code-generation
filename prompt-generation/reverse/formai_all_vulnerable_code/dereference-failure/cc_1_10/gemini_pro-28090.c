//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define WIDTH 512
#define HEIGHT 512

// Image data type
typedef unsigned char pixel_t;

// Image structure
typedef struct {
    pixel_t *data;
    int width;
    int height;
} image_t;

// Load an image from a file
image_t *image_load(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    // Read the image header
    int width, height;
    if (fscanf(fp, "P5 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Invalid image header\n");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(pixel_t));
    if (!image->data) {
        perror("malloc");
        free(image);
        fclose(fp);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, sizeof(pixel_t), width * height, fp) != width * height) {
        fprintf(stderr, "Invalid image data\n");
        free(image->data);
        free(image);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return image;
}

// Save an image to a file
void image_save(image_t *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    // Write the image header
    fprintf(fp, "P5 %d %d\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp);

    fclose(fp);
}

// Flip an image horizontally
void image_flip_horizontal(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void image_flip_vertical(image_t *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void image_brightness(image_t *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = image->data[y * image->width + x] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }
}

// Change the contrast of an image
void image_contrast(image_t *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = (image->data[y * image->width + x] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    image_t *image = image_load(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    image_flip_horizontal(image);

    // Flip the image vertically
    image_flip_vertical(image);

    // Change the brightness of the image
    image_brightness(image, 50);

    // Change the contrast of the image
    image_contrast(image, 150);

    // Save the output image
    image_save(image, argv[2]);

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}