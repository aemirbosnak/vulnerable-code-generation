//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the ASCII characters to use in the conversion
const char *ASCII_CHARS = " .,:;i1tfLCG08@";

int main(int argc, char *argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open the input file in binary mode
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    // Determine the size of the input file
    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory to store the image data
    unsigned char *image_data = (unsigned char *) malloc(file_size * sizeof(unsigned char));
    if (!image_data) {
        printf("Error: could not allocate memory\n");
        fclose(input_file);
        exit(1);
    }

    // Read in the image data
    int read_size = fread(image_data, sizeof(unsigned char), file_size, input_file);
    if (read_size != file_size) {
        printf("Error: could not read input file data\n");
        free(image_data);
        fclose(input_file);
        exit(1);
    }

    // Close the input file
    fclose(input_file);

    // Determine the dimensions of the image
    int image_width = sqrt(file_size);
    int image_height = file_size / image_width;

    // Allocate memory to store the ASCII art
    char *ascii_data = (char *) calloc((image_width * image_height) + image_height, sizeof(char));
    if (!ascii_data) {
        printf("Error: could not allocate memory\n");
        free(image_data);
        exit(1);
    }

    // Convert the image to ASCII art
    for (int i = 0; i < file_size; i++) {
        int brightness = (int) image_data[i] / 11;
        ascii_data[i + (i / image_width)] = ASCII_CHARS[brightness];
    }

    // Open the output file in write mode
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: could not open output file\n");
        free(image_data);
        free(ascii_data);
        exit(1);
    }

    // Write out the ASCII art to the output file
    for (int i = 0; i < image_height; i++) {
        fwrite(&ascii_data[i * (image_width + 1)], sizeof(char), image_width, output_file);
        fwrite("\n", sizeof(char), 1, output_file);
    }

    // Close the output file
    fclose(output_file);

    // Free up memory
    free(image_data);
    free(ascii_data);

    return 0;
}