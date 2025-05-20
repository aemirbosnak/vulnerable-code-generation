//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, 54, 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    // Read the image data
    fread(image->data, width * height * 3, 1, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Save an image to a file
int save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }

    // Write the header
    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(int *)&header[28] = 24;
    *(int *)&header[34] = image->width * image->height * 3;

    // Write the image data
    fwrite(header, 54, 1, fp);
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    // Close the file
    fclose(fp);

    return 0;
}

// Apply a filter to an image
void apply_filter(Image *image, int filter_type) {
    int width = image->width;
    int height = image->height;
    unsigned char *data = image->data;

    // Apply the filter to each pixel
    for (int i = 0; i < width * height; i++) {
        int r = data[i * 3 + 0];
        int g = data[i * 3 + 1];
        int b = data[i * 3 + 2];

        // Apply the filter
        switch (filter_type) {
            case 0:  // Grayscale
                r = g = b = (r + g + b) / 3;
                break;
            case 1:  // Sepia
                r = (r * 0.393) + (g * 0.769) + (b * 0.189);
                g = (r * 0.349) + (g * 0.686) + (b * 0.168);
                b = (r * 0.272) + (g * 0.534) + (b * 0.131);
                break;
            case 2:  // Blur
                // TODO
                break;
            case 3:  // Sharpen
                // TODO
                break;
        }

        // Clamp the values to the range 0-255
        r = r < 0 ? 0 : r > 255 ? 255 : r;
        g = g < 0 ? 0 : g > 255 ? 255 : g;
        b = b < 0 ? 0 : b > 255 ? 255 : b;

        // Update the pixel data
        data[i * 3 + 0] = r;
        data[i * 3 + 1] = g;
        data[i * 3 + 2] = b;
    }
}

// Print the help message
void print_help() {
    printf("Usage: image_editor <input_file> <output_file> <filter_type>\n");
    printf("Filter types:\n");
    printf("  0: Grayscale\n");
    printf("  1: Sepia\n");
    printf("  2: Blur\n");
    printf("  3: Sharpen\n");
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        print_help();
        return 1;
    }

    // Get the input and output filenames
    char *input_filename = argv[1];
    char *output_filename = argv[2];

    // Get the filter type
    int filter_type = atoi(argv[3]);

    // Load the input image
    Image *image = load_image(input_filename);
    if (image == NULL) {
        return 1;
    }

    // Apply the filter to the image
    apply_filter(image, filter_type);

    // Save the output image
    if (save_image(output_filename, image) != 0) {
        return 1;
    }

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}