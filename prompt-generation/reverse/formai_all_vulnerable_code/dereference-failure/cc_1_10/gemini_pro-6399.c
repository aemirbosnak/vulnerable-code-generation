//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image struct
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Function to flip an image vertically
void flip_vertical(Image *image) {
    int i, j, temp;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                temp = image->data[(i * image->width + j) * image->channels + k];
                image->data[(i * image->width + j) * image->channels + k] = image->data[((image->height - i - 1) * image->width + j) * image->channels + k];
                image->data[((image->height - i - 1) * image->width + j) * image->channels + k] = temp;
            }
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    int i, j, temp;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            for (int k = 0; k < image->channels; k++) {
                temp = image->data[(i * image->width + j) * image->channels + k];
                image->data[(i * image->width + j) * image->channels + k] = image->data[(i * image->width + (image->width - j - 1)) * image->channels + k];
                image->data[(i * image->width + (image->width - j - 1)) * image->channels + k] = temp;
            }
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                int pixel = image->data[(i * image->width + j) * image->channels + k] + brightness;
                image->data[(i * image->width + j) * image->channels + k] = (pixel > 255) ? 255 : (pixel < 0) ? 0 : pixel;
            }
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                float pixel = factor * (image->data[(i * image->width + j) * image->channels + k] - 128) + 128;
                image->data[(i * image->width + j) * image->channels + k] = (pixel > 255) ? 255 : (pixel < 0) ? 0 : pixel;
            }
        }
    }
}

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, 1, 18, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: '%s' is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Get the number of channels
    int channels = header[28] / 8;

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);

    // Read the image data
    fread(image->data, 1, width * height * channels, file);

    // Close the file
    fclose(file);

    return image;
}

// Function to save an image to a file
void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, image->width, 0, image->height, 0,
    };
    fwrite(header, 1, 18, file);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * image->channels, file);

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <operation> [arguments]\n", argv[0]);
        fprintf(stderr, "Operations:\n");
        fprintf(stderr, "  - flip-v: Flip the image vertically\n");
        fprintf(stderr, "  - flip-h: Flip the image horizontally\n");
        fprintf(stderr, "  - brightness <value>: Change the brightness of the image\n");
        fprintf(stderr, "  - contrast <value>: Change the contrast of the image\n");
        return 1;
    }

    // Load the image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation
    if (strcmp(argv[3], "flip-v") == 0) {
        flip_vertical(image);
    } else if (strcmp(argv[3], "flip-h") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "brightness") == 0) {
        if (argc < 5) {
            fprintf(stderr, "Error: Missing brightness value\n");
            return 1;
        }
        int brightness = atoi(argv[4]);
        change_brightness(image, brightness);
    } else if (strcmp(argv[3], "contrast") == 0) {
        if (argc < 5) {
            fprintf(stderr, "Error: Missing contrast value\n");
            return 1;
        }
        float contrast = atof(argv[4]);
        change_contrast(image, contrast);
    } else {
        fprintf(stderr, "Error: Invalid operation '%s'\n", argv[3]);
        return 1;
    }

    // Save the image
    save_image(image, argv[2]);

    // Free the image
    free(image->data);
    free(image);

    return 0;
}