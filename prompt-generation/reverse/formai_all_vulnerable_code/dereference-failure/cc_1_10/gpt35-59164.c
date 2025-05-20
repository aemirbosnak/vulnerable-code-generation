//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 50

// Function declarations
void apply_grayscale_filter(unsigned char *image_data, int image_width, int image_height);
void apply_invert_filter(unsigned char *image_data, int image_width, int image_height);
void apply_blur_filter(unsigned char *image_data, int image_width, int image_height);
void save_image(unsigned char *image_data, int image_width, int image_height, char *filename);

int main() {
    // Prompt user for input image filename
    char input_filename[MAX_FILENAME_LENGTH];
    printf("Enter input image filename: ");
    fgets(input_filename, MAX_FILENAME_LENGTH, stdin);
    input_filename[strlen(input_filename)-1] = '\0'; // remove newline character

    // Open input image file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("ERROR: Could not open input image file.");
        return 1;
    }

    // Read input image dimensions from file
    int image_width, image_height;
    fscanf(input_file, "P5 %d %d 255 ", &image_width, &image_height);

    // Allocate memory for image data
    unsigned char *image_data = malloc(image_width * image_height);

    // Read image data from file
    fread(image_data, sizeof(unsigned char), image_width * image_height, input_file);

    // Close input image file
    fclose(input_file);

    // Prompt user for command to apply to image
    char command[MAX_COMMAND_LENGTH];
    printf("Enter command ('grayscale', 'invert', 'blur'): ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strlen(command)-1] = '\0'; // remove newline character

    // Apply specified filter to image data
    if (strcmp(command, "grayscale") == 0) {
        apply_grayscale_filter(image_data, image_width, image_height);
    } else if (strcmp(command, "invert") == 0) {
        apply_invert_filter(image_data, image_width, image_height);
    } else if (strcmp(command, "blur") == 0) {
        apply_blur_filter(image_data, image_width, image_height);
    } else {
        printf("ERROR: Unrecognized command.");
        return 1;
    }

    // Prompt user for output image filename
    char output_filename[MAX_FILENAME_LENGTH];
    printf("Enter output image filename: ");
    fgets(output_filename, MAX_FILENAME_LENGTH, stdin);
    output_filename[strlen(output_filename)-1] = '\0'; // remove newline character

    // Save image data to output file
    save_image(image_data, image_width, image_height, output_filename);

    // Free allocated memory
    free(image_data);

    return 0;
}

// Function to apply grayscale filter to image data
void apply_grayscale_filter(unsigned char *image_data, int image_width, int image_height) {
    for (int i = 0; i < image_width * image_height; i++) {
        unsigned char pixel_value = image_data[i];
        unsigned char grayscale_value = 0.21 * pixel_value + 0.72 * pixel_value + 0.07 * pixel_value;
        image_data[i] = grayscale_value;
    }
}

// Function to apply invert filter to image data
void apply_invert_filter(unsigned char *image_data, int image_width, int image_height) {
    for (int i = 0; i < image_width * image_height; i++) {
        image_data[i] = 255 - image_data[i];
    }
}

// Function to apply blur filter to image data
void apply_blur_filter(unsigned char *image_data, int image_width, int image_height) {
    unsigned char *temp_data = malloc(image_width * image_height);
    memcpy(temp_data, image_data, image_width * image_height);

    for (int i = 1; i < image_height - 1; i++) {
        for (int j = 1; j < image_width - 1; j++) {
            unsigned int avg = 0;
            avg += temp_data[(i-1)*image_width + (j-1)];
            avg += temp_data[(i-1)*image_width + j];
            avg += temp_data[(i-1)*image_width + (j+1)];
            avg += temp_data[i*image_width + (j-1)];
            avg += temp_data[i*image_width + j];
            avg += temp_data[i*image_width + (j+1)];
            avg += temp_data[(i+1)*image_width + (j-1)];
            avg += temp_data[(i+1)*image_width + j];
            avg += temp_data[(i+1)*image_width + (j+1)];
            avg /= 9;
            image_data[i*image_width + j] = avg;
        }
    }

    free(temp_data);
}

// Function to save image data to file
void save_image(unsigned char *image_data, int image_width, int image_height, char *filename) {
    FILE *output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        printf("ERROR: Could not open output image file.");
        exit(1);
    }

    fprintf(output_file, "P5 %d %d 255 ", image_width, image_height);
    fwrite(image_data, sizeof(unsigned char), image_width * image_height, output_file);

    fclose(output_file);
}