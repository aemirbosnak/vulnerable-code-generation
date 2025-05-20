//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to ASCII art function
void image_to_ascii(FILE *input, FILE *output, int width, int height) {
    // Check if images are not null
    if (input == NULL || output == NULL) {
        printf("Error! Invalid file.");
        return;
    }

    // Initialize variables for image dimensions
    int x, y, gray;
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    // Iterate through pixels in image
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Read the gray value of pixel
            fread(&gray, 1, 1, input);

            // Calculate ASCII index based on gray value
            int ascii_index = round((gray / 255.0) * 9.0);

            // Write corresponding ASCII character to output
            fprintf(output, "%c", ascii_chars[ascii_index]);
        }

        // Add newline character for each row
        fprintf(output, "\n");
    }

    // Close input and output files
    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if number of arguments is correct
    if (argc != 4) {
        printf("Usage: ./image_to_ascii input.bmp output.txt size\n");
        return 1;
    }

    // Read the input file
    FILE *input_file = fopen(argv[1], "rb");

    // Check if input file is null
    if (input_file == NULL) {
        printf("Error! Invalid file.");
        return 1;
    }

    // Get the dimensions of the image
    fseek(input_file, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, input_file);
    fread(&height, 4, 1, input_file);

    // Set image size from command line argument
    int size = atoi(argv[3]);

    // Calculate new width and height of image based on desired size
    int new_width = (width * size) / height;
    int new_height = size;

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char *)malloc(width * height);
    fseek(input_file, 54, SEEK_SET);
    fread(image_data, 1, width * height, input_file);

    // Calculate scaling factors for rows and columns
    float row_factor = (float)height / (float)new_height;
    float col_factor = (float)width / (float)new_width;

    // Open output file for writing
    FILE *output_file = fopen(argv[2], "w");

    // Iterate through new image rows
    int i, j;
    for (i = 0; i < new_height; i++) {
        // Iterate through new image columns
        for (j = 0; j < new_width; j++) {
            // Calculate position of old image pixel
            int old_x = (int)(j * col_factor);
            int old_y = (int)(i * row_factor);

            // Calculate index of old image pixel
            int old_index = (old_y * width) + old_x;

            // Write pixel data to output file
            fprintf(output_file, "%c", image_data[old_index]);
        }

        // Add newline character for each row
        fprintf(output_file, "\n");
    }

    // Convert image to ASCII art with calculated dimensions
    image_to_ascii(input_file, output_file, new_width, new_height);

    // Free image data memory and close output file
    free(image_data);
    fclose(output_file);

    return 0;
}