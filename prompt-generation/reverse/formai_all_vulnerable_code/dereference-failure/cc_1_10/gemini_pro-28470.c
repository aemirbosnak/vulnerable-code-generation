//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
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
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    if (fscanf(file, "P5 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Error: could not read header from file '%s'\n", filename);
        fclose(file);
        return NULL;
    }

    // Read the data
    unsigned char *data = malloc(width * height);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        return NULL;
    }
    if (fread(data, width * height, 1, file) != 1) {
        fprintf(stderr, "Error: could not read data from file '%s'\n", filename);
        fclose(file);
        free(data);
        return NULL;
    }

    fclose(file);

    // Create the image
    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        free(data);
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Write an image to a file
void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    // Write the header
    fprintf(file, "P5 %d %d\n", image->width, image->height);

    // Write the data
    fwrite(image->data, image->width * image->height, 1, file);

    fclose(file);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
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
void change_contrast(Image *image, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = (image->data[y * image->width + x] - 127) * contrast + 127;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <operation> <value>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        change_brightness(image, atoi(argv[4]));
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        change_contrast(image, atoi(argv[4]));
    } else {
        fprintf(stderr, "Error: unknown operation '%s'\n", argv[3]);
        free_image(image);
        return 1;
    }

    // Write the output image
    write_image(argv[2], image);

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}