//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// A simple struct to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Loads an image from a file
Image load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[54];
    fread(header, 1, 54, file);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);

    // Read the image data
    fread(data, 1, width * height * 3, file);

    // Close the file
    fclose(file);

    // Return the image
    Image image = {
        .width = width,
        .height = height,
        .data = data
    };

    return image;
}

// Saves an image to a file
void save_image(Image image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image.width * image.height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image.width;
    *(int *)&header[22] = image.height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = image.width * image.height * 3;
    *(int *)&header[38] = 2834;
    *(int *)&header[42] = 2834;
    *(int *)&header[46] = 0;
    *(int *)&header[50] = 0;
    fwrite(header, 1, 54, file);

    // Write the image data
    fwrite(image.data, 1, image.width * image.height * 3, file);

    // Close the file
    fclose(file);
}

// Flips an image vertically
void flip_image_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char *pixel1 = &image->data[i * image->width * 3 + j * 3];
            unsigned char *pixel2 = &image->data[(image->height - i - 1) * image->width * 3 + j * 3];
            unsigned char temp = *pixel1;
            *pixel1 = *pixel2;
            *pixel2 = temp;
        }
    }
}

// Flips an image horizontally
void flip_image_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char *pixel1 = &image->data[i * image->width * 3 + j * 3];
            unsigned char *pixel2 = &image->data[i * image->width * 3 + (image->width - j - 1) * 3];
            unsigned char temp = *pixel1;
            *pixel1 = *pixel2;
            *pixel2 = temp;
        }
    }
}

// Changes the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, int brightness, int contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char *pixel = &image->data[i * image->width * 3 + j * 3];
            *pixel = (unsigned char)(*pixel + brightness);
            *pixel = (unsigned char)(*pixel * contrast / 100);
        }
    }
}

// The main function
int main() {
    // Load the image
    Image image = load_image("image.bmp");

    // Flip the image vertically
    flip_image_vertical(&image);

    // Flip the image horizontally
    flip_image_horizontal(&image);

    // Change the brightness and contrast of the image
    adjust_brightness_contrast(&image, 50, 150);

    // Save the image
    save_image(image, "new_image.bmp");

    // Free the image data
    free(image.data);

    return 0;
}