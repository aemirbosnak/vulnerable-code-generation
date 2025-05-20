//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/**
 * This program converts a given image file into ASCII art.
 * It reads the image pixel by pixel and maps each pixel to a corresponding ASCII character.
 * The output is written to a new file in txt format.
 * The program takes the following arguments:
 *   - the input image file path
 *   - the width of the ASCII art in characters
 *   - the output file path
 */

// Define character mapping array
static const char ASCII_CHARS[] = {
    ' ', '.', ',', ':', ';', 'i', 'l', 'f', 't', 'L', 'C', 'G', 'O', '0', '@'
};

// Calculate the number of characters in the mapping array
static const int MAPPING_SIZE = sizeof(ASCII_CHARS) / sizeof(char);

// Define a struct to hold RGB pixel values
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

// Define a function to get the average value of RGB components in a pixel
static int get_average_color(pixel_t p) {
    return (p.r + p.g + p.b) / 3;
}

// Define a function to map a pixel to an ASCII character
static char get_ascii_char(pixel_t p) {
    // Get the average color value of the pixel
    int avg_color = get_average_color(p);
    // Calculate the index of the ASCII character that matches the pixel
    int char_index = avg_color * (MAPPING_SIZE - 1) / 255;
    // Return the corresponding ASCII character
    return ASCII_CHARS[char_index];
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments have been provided
    if (argc != 4) {
        printf("Invalid number of arguments!\n");
        return 1;
    }
    // Open the input file for reading in binary mode
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Failed to open input file: %s\n", argv[1]);
        return 1;
    }
    // Open the output file for writing
    FILE *output_file = fopen(argv[3], "w");
    if (!output_file) {
        printf("Failed to open output file: %s\n", argv[3]);
        fclose(input_file);
        return 1;
    }
    // Read the width of the ASCII art
    int width = atoi(argv[2]);
    if (width <= 0) {
        printf("Invalid width value: %s\n", argv[2]);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    // Calculate the height of the ASCII art based on the width and aspect ratio of the image
    fseek(input_file, 0, SEEK_END);
    long int file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    // The image format is assumed to be BMP
    uint16_t pixel_offset = *(uint16_t *)(fread(&pixel_offset, sizeof(uint16_t), 1, input_file), &pixel_offset);
    uint32_t header_size = *(uint32_t *)(fread(&header_size, sizeof(uint32_t), 1, input_file), &header_size);
    uint32_t image_width = *(uint32_t *)(fread(&image_width, sizeof(uint32_t), 1, input_file), &image_width);
    uint32_t image_height = *(uint32_t *)(fread(&image_height, sizeof(uint32_t), 1, input_file), &image_height);
    // Calculate the padding used in the image file
    uint32_t row_size = ((image_width * 3) + 3) & ~3;
    uint32_t padding_size = row_size - (image_width * 3);
    // Calculate the height of the ASCII art
    int height = (int)((double)image_height * width / image_width * 0.5);
    // Allocate memory for the image data
    pixel_t *image_data = malloc(image_height * image_width * sizeof(pixel_t));
    // Read the image data into memory
    fseek(input_file, pixel_offset, SEEK_SET);
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            // Read the RGB pixel values from the file
            pixel_t p;
            fread(&p.b, sizeof(uint8_t), 1, input_file);
            fread(&p.g, sizeof(uint8_t), 1, input_file);
            fread(&p.r, sizeof(uint8_t), 1, input_file);
            // Map the pixel to an ASCII character and write it to the output file
            char c = get_ascii_char(p);
            fprintf(output_file, "%c", c);
        }
        // Write padding characters to the output file
        for (int k = 0; k < padding_size; k++) {
            fprintf(output_file, " ");
        }
        // Write a new line character to the output file
        fprintf(output_file, "\n");
    }
    // Free the allocated memory and close the files
    free(image_data);
    fclose(input_file);
    fclose(output_file);
    return 0;
}