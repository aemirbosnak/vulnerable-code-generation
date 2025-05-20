//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

// Function to convert image to ASCII art
void image_to_ascii(char *input_file, char *output_file) {
    FILE *input, *output;
    int width, height, i, j, k, x, y, c;
    unsigned char *pixels;

    // Open input file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get image dimensions
    fseek(input, 18, SEEK_SET);
    fread(&width, 4, 1, input);
    fread(&height, 4, 1, input);
    fclose(input);

    // Open output file
    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Allocate memory for pixels
    pixels = (unsigned char *) malloc(width * height);
    if (pixels == NULL) {
        printf("Error: Could not allocate memory for pixels.\n");
        exit(1);
    }

    // Read image data
    input = fopen(input_file, "rb");
    fseek(input, 54, SEEK_SET);
    fread(pixels, 1, width * height, input);
    fclose(input);

    // Convert image to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            c = pixels[i * width + j];
            if (c == 0) {
                fprintf(output, " ");
            } else if (c == 255) {
                fprintf(output, "X");
            } else {
                fprintf(output, ".");
            }
        }
        fprintf(output, "\n");
    }

    // Free memory
    free(pixels);

    // Close output file
    fclose(output);
}

// Function to print usage
void print_usage() {
    printf("Usage: image_to_ascii <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    // Convert image to ASCII art
    image_to_ascii(argv[1], argv[2]);

    return 0;
}