//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Read an image from a file
Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
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

// Write an image to a file
void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    };
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    // Close the file
    fclose(fp);
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < 3; c++) {
                unsigned char tmp = image->data[y * image->width * 3 + x * 3 + c];
                image->data[y * image->width * 3 + x * 3 + c] = image->data[(image->height - y - 1) * image->width * 3 + x * 3 + c];
                image->data[(image->height - y - 1) * image->width * 3 + x * 3 + c] = tmp;
            }
        }
    }
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            for (int c = 0; c < 3; c++) {
                unsigned char tmp = image->data[y * image->width * 3 + x * 3 + c];
                image->data[y * image->width * 3 + x * 3 + c] = image->data[y * image->width * 3 + (image->width - x - 1) * 3 + c];
                image->data[y * image->width * 3 + (image->width - x - 1) * 3 + c] = tmp;
            }
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < 3; c++) {
                int value = image->data[y * image->width * 3 + x * 3 + c] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[y * image->width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < 3; c++) {
                int value = (image->data[y * image->width * 3 + x * 3 + c] - 128) * contrast + 128;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[y * image->width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Print the usage information
void usage() {
    printf("Usage: image_processing <input_file> <output_file> <operation> [<args>]\n");
    printf("Operations:\n");
    printf("  - flip_vertical\n");
    printf("  - flip_horizontal\n");
    printf("  - change_brightness <brightness>\n");
    printf("  - change_contrast <contrast>\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc < 4) {
        usage();
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation
    if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(image);
    } else if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        if (argc < 5) {
            usage();
            return 1;
        }
        int brightness = atoi(argv[4]);
        change_brightness(image, brightness);
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        if (argc < 5) {
            usage();
            return 1;
        }
        int contrast = atoi(argv[4]);
        change_contrast(image, contrast);
    } else {
        usage();
        return 1;
    }

    // Write the output image
    write_image(image, argv[2]);

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}