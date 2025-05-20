//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an image
typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header information
    unsigned int width, height;
    fread(&width, sizeof(unsigned int), 1, fp);
    fread(&height, sizeof(unsigned int), 1, fp);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    // Read the image data
    fread(image->data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Function to save an image to a file
void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header information
    fwrite(&image->width, sizeof(unsigned int), 1, fp);
    fwrite(&image->height, sizeof(unsigned int), 1, fp);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    // Close the file
    fclose(fp);
}

// Function to flip an image vertically
void flip_image_vertical(Image *image) {
    int i, j;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            unsigned char tmp = image->data[i * image->width * 3 + j * 3];
            image->data[i * image->width * 3 + j * 3] = image->data[(image->height - i - 1) * image->width * 3 + j * 3];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3] = tmp;
            
            tmp = image->data[i * image->width * 3 + j * 3 + 1];
            image->data[i * image->width * 3 + j * 3 + 1] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 1];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 1] = tmp;
            
            tmp = image->data[i * image->width * 3 + j * 3 + 2];
            image->data[i * image->width * 3 + j * 3 + 2] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 2];
            image->data[(image->height - i - 1) * image->width * 3 + j * 3 + 2] = tmp;
        }
    }
}

// Function to flip an image horizontally
void flip_image_horizontal(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            unsigned char tmp = image->data[i * image->width * 3 + j * 3];
            image->data[i * image->width * 3 + j * 3] = image->data[i * image->width * 3 + (image->width - j - 1) * 3];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3] = tmp;
            
            tmp = image->data[i * image->width * 3 + j * 3 + 1];
            image->data[i * image->width * 3 + j * 3 + 1] = image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 1];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 1] = tmp;
            
            tmp = image->data[i * image->width * 3 + j * 3 + 2];
            image->data[i * image->width * 3 + j * 3 + 2] = image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 2];
            image->data[i * image->width * 3 + (image->width - j - 1) * 3 + 2] = tmp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, int brightness) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width * 3 + j * 3] += brightness;
            image->data[i * image->width * 3 + j * 3 + 1] += brightness;
            image->data[i * image->width * 3 + j * 3 + 2] += brightness;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, float contrast) {
    int i, j;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width * 3 + j * 3] = factor * (image->data[i * image->width * 3 + j * 3] - 128) + 128;
            image->data[i * image->width * 3 + j * 3 + 1] = factor * (image->data[i * image->width * 3 + j * 3 + 1] - 128) + 128;
            image->data[i * image->width * 3 + j * 3 + 2] = factor * (image->data[i * image->width * 3 + j * 3 + 2] - 128) + 128;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided enough arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> [output image]\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Flip the image vertically
    flip_image_vertical(image);

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the output image
    if (argc >= 3) {
        save_image(image, argv[2]);
    } else {
        save_image(image, "output.bmp");
    }

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}