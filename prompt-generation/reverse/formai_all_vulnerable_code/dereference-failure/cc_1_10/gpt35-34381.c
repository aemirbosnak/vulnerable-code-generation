//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255 // Maximum value of a pixel
#define MAX_OUTPUT_CHAR 256 // Maximum number of ASCII characters used to represent an image 

// Function to read in an image from a file
void read_image(char* filename, unsigned char** image_data, int* rows, int* cols) {
    FILE* fp = fopen(filename, "rb"); // Open the file in binary mode for reading

    if (fp != NULL) {
        // Read in the magic number and image dimensions
        char magic_number[3];
        fscanf(fp, "%s %d %d %*d", magic_number, cols, rows);

        // Allocate memory for the image data
        int num_pixels = (*rows) * (*cols);
        (*image_data) = (unsigned char*) malloc(num_pixels * sizeof(unsigned char));

        // Read in the pixel data
        fread(*image_data, sizeof(unsigned char), num_pixels, fp);

        // Close the file
        fclose(fp);
    } else {
        printf("Error: could not open file \"%s\".\n", filename);
    }
}

// Function to convert an image to ASCII art
void convert_to_ascii(unsigned char* image_data, int rows, int cols, char* output) {
    // Define the ASCII characters used to represent different pixel values
    char ascii_chars[MAX_OUTPUT_CHAR + 1] = " .:-=+*#%@"; // Add more characters to increase resolution

    int num_pixels = rows * cols;
    int ascii_index = 0;
    for (int i = 0; i < num_pixels; i++) {
        // Calculate the index of the ASCII character to use based on the pixel value
        ascii_index = ((int) image_data[i] * (MAX_OUTPUT_CHAR - 1)) / MAX_PIXEL_VALUE;

        // Append the ASCII character to the output string
        strncat(output, &ascii_chars[ascii_index], 1);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Define variables to store the image data and dimensions
    unsigned char* image_data = NULL;
    int rows = 0, cols = 0;

    // Read in the image from a file
    read_image(argv[1], &image_data, &rows, &cols);

    // Allocate memory for the output string
    char* output = (char*) malloc((rows * cols * 2 + 1) * sizeof(char)); // Multiply by 2 to account for '\n' characters
    output[0] = '\0'; // Initialize the output string

    // Convert the image to ASCII art
    convert_to_ascii(image_data, rows, cols, output);

    // Print the ASCII art to the console
    printf("%s\n", output);

    // Free allocated memory
    free(image_data);
    free(output);

    return 0;
}