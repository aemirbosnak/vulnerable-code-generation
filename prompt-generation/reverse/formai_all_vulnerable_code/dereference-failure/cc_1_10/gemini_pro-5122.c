//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image structure
typedef struct {
    unsigned char *data;
    int width, height;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    char header[2];
    fread(header, 1, 2, fp);
    if (strncmp(header, "P5", 2) != 0) {
        fprintf(stderr, "Error: invalid file format\n");
        fclose(fp);
        return NULL;
    }

    // Read the width and height
    int width, height;
    fscanf(fp, "%d %d\n", &width, &height);

    // Read the maximum value
    int max;
    fscanf(fp, "%d\n", &max);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height);

    // Read the image data
    fread(image->data, 1, width * height, fp);

    // Close the file
    fclose(fp);

    // Return the image
    return image;
}

// Free an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] + brightness;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            float value = (image->data[y * image->width + x] - 127.5) * contrast + 127.5;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        printf("Operations:\n");
        printf("  flip_horizontal\n");
        printf("  flip_vertical\n");
        printf("  change_brightness <value>\n");
        printf("  change_contrast <value>\n");
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_image_horizontal(image);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_image_vertical(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        int brightness = atoi(argv[4]);
        change_brightness(image, brightness);
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        float contrast = atof(argv[4]);
        change_contrast(image, contrast);
    } else {
        fprintf(stderr, "Error: invalid operation %s\n", argv[3]);
        free_image(image);
        return 1;
    }

    // Save the output image
    save_image(argv[2], image);

    // Free the image
    free_image(image);

    return 0;
}