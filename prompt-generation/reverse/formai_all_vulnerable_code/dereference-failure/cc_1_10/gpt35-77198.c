//FormAI DATASET v1.0 Category: Image compression ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress an image
void compress_image(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    // Read the header information of the input file
    int width, height, max_val;
    char format[3];
    fscanf(input, "%s %d %d %d", format, &width, &height, &max_val);
    fgetc(input); // ignore the newline character after the header

    // Write the header to the output file
    fprintf(output, "%s %d %d %d\n", format, width, height, max_val);

    // Allocate memory for storing pixel data
    int** pixels = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(int));
    }

    // Read pixel data from the input file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = fgetc(input);
            pixels[i][j] = pixel_value;
        }
    }

    // Compress the pixel data by calculating the difference between pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int diff = 0;
            if (i > 0) {
                diff += pixels[i][j] - pixels[i-1][j];
            }
            if (j > 0) {
                diff += pixels[i][j] - pixels[i][j-1];
            }
            fputc(diff, output);
        }
    }

    // Free memory used for pixel data
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    // Close input and output files
    fclose(input);
    fclose(output);
}

int main() {
    char* input_file = "input.pgm";
    char* output_file = "output.pgm";

    compress_image(input_file, output_file);

    printf("Image compressed successfully!\n");

    return 0;
}