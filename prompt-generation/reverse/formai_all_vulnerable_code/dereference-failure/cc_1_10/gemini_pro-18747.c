//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
// A journey into the realm of basic image processing
// A visual odyssey where pixels dance to our commands

#include <stdio.h>
#include <stdlib.h>

// Introducing our canvas, a matrix of pixels
unsigned char** image;

// Dimensions of our canvas
int width, height;

// Load the image from a file
void load_image(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the header
    fscanf(fp, "P5\n%d %d\n255\n", &width, &height);

    // Allocate memory for the image
    image = malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(unsigned char));
    }

    // Read the pixel data
    fread(image[0], width * height, 1, fp);

    // Close the file
    fclose(fp);
}

// Reflecting the image across the vertical axis
void flip_vertical() {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            // Swap the pixels at (i, j) and (height - 1 - i, j)
            unsigned char temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

// Adjusting the brightness and contrast of the image
void adjust_brightness_contrast(int brightness, int contrast) {
    // Apply the brightness adjustment
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] += brightness;
        }
    }

    // Apply the contrast adjustment
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] *= contrast;
        }
    }
}

// Saving our masterpiece to a file
void save_image(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the header
    fprintf(fp, "P5\n%d %d\n255\n", width, height);

    // Write the pixel data
    fwrite(image[0], width * height, 1, fp);

    // Close the file
    fclose(fp);
}

// Witnessing the transformation unveil
int main() {
    // Embarking on our journey with the "image.pgm"
    load_image("image.pgm");

    // Flipping the image to gaze upon its mirror reflection
    flip_vertical();

    // Adding vibrancy with increased brightness and contrast
    adjust_brightness_contrast(50, 120);

    // Preserving our creation for posterity
    save_image("transformed_image.pgm");

    // Deallocating the canvas
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}