//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of the ASCII art
#define HEIGHT 20 // Height of the ASCII art

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    // Open the input image file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Get the size of the input image
    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for the input image data
    unsigned char *input_data = malloc(input_size);
    if (input_data == NULL) {
        printf("Error: Could not allocate memory for input data.\n");
        fclose(input_file);
        return 1;
    }

    // Read the input image data
    fread(input_data, input_size, 1, input_file);
    fclose(input_file);

    // Open the output ASCII art file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        free(input_data);
        return 1;
    }

    // Convert the input image to ASCII art
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int pixel_value = (int) input_data[(y * WIDTH + x) * 3];
            char ascii_character = (pixel_value / 51) % 6 + 33; // Convert pixel value to ASCII character
            fprintf(output_file, "%c", ascii_character);
        }
        fprintf(output_file, "\n");
    }

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the input data
    free(input_data);

    return 0;
}