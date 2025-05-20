//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_RGB_VALUE 255
#define MIN_RGB_VALUE 0

#define SINGLE_IMAGE_SIZE 1024

#define MAX_FILE_NAME_SIZE 255

// Function to print a given error message and exit the program
void error_exit(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// Function to flip the given single row of RGB pixel values horizontally
void flip_row(unsigned char *row, const size_t row_size) {
    unsigned char temp_pixel[3];
    for (size_t i = 0; i < row_size / 2; i++) {
        memcpy(temp_pixel, &row[i * 3], 3);
        memcpy(&row[i * 3], &row[(row_size - i - 1) * 3], 3);
        memcpy(&row[(row_size - i - 1) * 3], temp_pixel, 3);
    }
}

// Function to flip the given image horizontally
void flip_image(unsigned char *image, const size_t image_width, const size_t image_height) {
    unsigned char *current_row = image;
    for (size_t i = 0; i < image_height; i++) {
        flip_row(current_row, image_width);
        current_row += image_width * 3;
    }
}

// Function to adjust the brightness of the given image by the given amount
void adjust_brightness(unsigned char *image, const size_t image_size, const int brightness_adjustment) {
    int pixel_rgb_values[3];
    for (size_t i = 0; i < image_size; i += 3) {
        // Extract the RGB pixel values from the image data
        memcpy(pixel_rgb_values, &image[i], 3);

        // Adjust the RGB pixel values based on the given brightness adjustment
        pixel_rgb_values[0] += brightness_adjustment;
        pixel_rgb_values[1] += brightness_adjustment;
        pixel_rgb_values[2] += brightness_adjustment;

        // Ensure the RGB pixel values are within the valid range of 0 to 255
        pixel_rgb_values[0] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[0]));
        pixel_rgb_values[1] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[1]));
        pixel_rgb_values[2] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[2]));

        // Update the RGB pixel values in the image data
        memcpy(&image[i], pixel_rgb_values, 3);
    }
}

// Function to adjust the contrast of the given image by the given amount
void adjust_contrast(unsigned char *image, const size_t image_size, const double contrast_adjustment) {
    int pixel_rgb_values[3];
    double contrast_factor = (100 + contrast_adjustment) / 100.0;
    contrast_factor *= contrast_factor;

    for (size_t i = 0; i < image_size; i += 3) {
        // Extract the RGB pixel values from the image data
        memcpy(pixel_rgb_values, &image[i], 3);

        // Adjust the RGB pixel values based on the given contrast adjustment
        pixel_rgb_values[0] = (int)(((pixel_rgb_values[0] / 255.0 - 0.5) * contrast_factor + 0.5) * 255.0);
        pixel_rgb_values[1] = (int)(((pixel_rgb_values[1] / 255.0 - 0.5) * contrast_factor + 0.5) * 255.0);
        pixel_rgb_values[2] = (int)(((pixel_rgb_values[2] / 255.0 - 0.5) * contrast_factor + 0.5) * 255.0);

        // Ensure the RGB pixel values are within the valid range of 0 to 255
        pixel_rgb_values[0] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[0]));
        pixel_rgb_values[1] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[1]));
        pixel_rgb_values[2] = fmax(MIN_RGB_VALUE, fmin(MAX_RGB_VALUE, pixel_rgb_values[2]));

        // Update the RGB pixel values in the image data
        memcpy(&image[i], pixel_rgb_values, 3);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter the file name of the image: ");
    scanf("%s", file_name);

    // Open the input image file
    FILE *input_file = fopen(file_name, "rb");
    if (!input_file) {
        error_exit("Error opening input file");
    }

    // Read the header information from the input file
    unsigned char header_buffer[54];
    if (fread(header_buffer, sizeof(unsigned char), 54, input_file) != 54) {
        error_exit("Error reading input file header");
    }

    // Extract the image width, height, and size from the header information
    size_t image_width = *(int*)&header_buffer[18];
    size_t image_height = *(int*)&header_buffer[22];
    size_t image_size = image_width * image_height * 3;

    // Ensure the input image is a valid single-channel RGB image
    if (header_buffer[0] != 'B' || header_buffer[1] != 'M' || *(int*)&(header_buffer[0x1E]) != 0 || *(int*)&(header_buffer[0x1C]) != 24) {
        error_exit("Input file format not supported");
    }

    // Allocate memory for the input and output images
    unsigned char *input_image = (unsigned char*) malloc(image_size);
    unsigned char *output_image = (unsigned char*) malloc(image_size);

    // Read the image data from the input file
    if (fread(input_image, sizeof(unsigned char), image_size, input_file) != image_size) {
        error_exit("Error reading input file data");
    }

    // Close the input file
    fclose(input_file);

    // Flip the image horizontally
    flip_image(input_image, image_width, image_height);

    // Adjust the brightness and contrast of the image
    adjust_brightness(input_image, image_size, 30);
    adjust_contrast(input_image, image_size, 20);

    // Save the output image to a new file
    FILE *output_file;
    char output_file_name[MAX_FILE_NAME_SIZE];
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "wb");
    if (!output_file) {
        error_exit("Error opening output file");
    }

    // Write the header information to the output file
    if (fwrite(header_buffer, sizeof(unsigned char), 54, output_file) != 54) {
        error_exit("Error writing output file header");
    }

    // Save the modified image data to the output file
    if (fwrite(input_image, sizeof(unsigned char), image_size, output_file) != image_size) {
        error_exit("Error writing output file data");
    }

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the images
    free(input_image);
    free(output_image);

    printf("Image processing complete.\n");

    return 0;
}