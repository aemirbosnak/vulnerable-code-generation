//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header information
    int width, height;
    if (fscanf(file, "P5 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Error reading header information from file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height);
    if (!data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    if (fread(data, width * height, 1, file) != 1) {
        fprintf(stderr, "Error reading image data from file %s\n", filename);
        free(data);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Create an image struct and return it
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to write an image to a file
void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header information
    fprintf(file, "P5 %d %d\n", image->width, image->height);

    // Write the image data
    if (fwrite(image->data, image->width * image->height, 1, file) != 1) {
        fprintf(stderr, "Error writing image data to file %s\n", filename);
        fclose(file);
        return;
    }

    // Close the file
    fclose(file);
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - 1 - x];
            image->data[y * image->width + image->width - 1 - x] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, int brightness) {
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

// Function to change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = 128 + contrast * (image->data[y * image->width + x] - 128);
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
    // Check the command line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <amount>\n", argv[0]);
        fprintf(stderr, "Operation can be one of: flip_horizontal, flip_vertical, change_brightness, change_contrast\n");
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation
    int amount = atoi(argv[4]);
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        change_brightness(image, amount);
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        change_contrast(image, amount);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        free(image->data);
        free(image);
        return 1;
    }

    // Write the output image
    write_image(image, argv[2]);

    // Free the memory used by the image
    free(image->data);
    free(image);

    return 0;
}