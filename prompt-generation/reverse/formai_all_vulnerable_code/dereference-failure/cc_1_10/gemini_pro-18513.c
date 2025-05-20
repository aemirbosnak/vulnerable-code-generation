//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to flip an image vertically */
void flip_vertical(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

/* Function to flip an image horizontally */
void flip_horizontal(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

/* Function to change the brightness of an image */
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] = (unsigned char) fmin(255, fmax(0, image[i * width + j] + brightness));
        }
    }
}

/* Function to change the contrast of an image */
void change_contrast(unsigned char *image, int width, int height, double contrast) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] = (unsigned char) fmin(255, fmax(0, (image[i * width + j] - 128) * contrast + 128));
        }
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 5) {
        printf("Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        return 1;
    }

    // Read the input image from a file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input image file %s\n", argv[1]);
        return 1;
    }

    // Get the width and height of the input image
    int width, height;
    fscanf(input_file, "%d %d", &width, &height);

    // Allocate memory for the input image
    unsigned char *input_image = (unsigned char *) malloc(width * height * sizeof(unsigned char));

    // Read the input image data into the buffer
    fread(input_image, sizeof(unsigned char), width * height, input_file);

    // Close the input image file
    fclose(input_file);

    // Perform the specified operation on the input image
    if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(input_image, width, height);
    } else if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(input_image, width, height);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        int brightness = atoi(argv[4]);
        change_brightness(input_image, width, height, brightness);
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        double contrast = atof(argv[4]);
        change_contrast(input_image, width, height, contrast);
    } else {
        printf("Error: Invalid operation %s\n", argv[3]);
        return 1;
    }

    // Write the output image to a file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output image file %s\n", argv[2]);
        return 1;
    }

    // Write the width and height of the output image to the file
    fprintf(output_file, "%d %d\n", width, height);

    // Write the output image data to the file
    fwrite(input_image, sizeof(unsigned char), width * height, output_file);

    // Close the output image file
    fclose(output_file);

    // Free the memory allocated for the input image
    free(input_image);

    return 0;
}