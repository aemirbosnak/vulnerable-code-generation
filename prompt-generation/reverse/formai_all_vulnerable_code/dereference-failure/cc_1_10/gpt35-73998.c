//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define the ASCII characters to use for conversion
char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.', ' '};
int num_chars = sizeof(ascii_chars) / sizeof(char);

// function to convert RGB color value to grayscale value
int grayscale_value(uint8_t red, uint8_t green, uint8_t blue) {
    // use luminosity method for grayscale conversion
    return (0.21 * red) + (0.72 * green) + (0.07 * blue);
}

int main(int argc, char *argv[]) {

    // check for correct usage
    if (argc != 3) {
        printf("Usage: %s [input_image_path] [output_txt_path]\n", argv[0]);
        exit(1);
    }

    // open input image file
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: Could not open input image file %s\n", argv[1]);
        exit(1);
    }

    // open output text file
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: Could not open output text file %s\n", argv[2]);
        exit(1);
    }

    // determine size of input image
    fseek(input_file, 0L, SEEK_END);
    int input_size = ftell(input_file);
    rewind(input_file);

    // read input image data into buffer
    uint8_t *input_buffer = (uint8_t*) malloc(input_size * sizeof(uint8_t));
    fread(input_buffer, sizeof(uint8_t), input_size, input_file);

    // close input image file
    fclose(input_file);

    // determine width and height of image
    int width = *(int*)(input_buffer + 18);
    int height = *(int*)(input_buffer + 22);

    // loop through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // calculate the starting index of the pixel
            int pixel_start = 54 + ((y * width) + x) * 3;

            // get the RGB color values for the pixel
            uint8_t red = *(input_buffer + pixel_start + 2);
            uint8_t green = *(input_buffer + pixel_start + 1);
            uint8_t blue = *(input_buffer + pixel_start);

            // convert RGB color values to grayscale value
            int grayscale = grayscale_value(red, green, blue);

            // determine the ASCII character to use for this grayscale value
            int ascii_index = (int) ((grayscale / 255.0) * (num_chars - 1));
            char ascii_char = ascii_chars[ascii_index];

            // write the ASCII character to the output file
            fprintf(output_file, "%c", ascii_char);
        }

        // write a new line character to the output file for each row of pixels
        fprintf(output_file, "\n");
    }

    // close output text file
    fclose(output_file);

    // free input buffer memory
    free(input_buffer);

    printf("Image conversion complete!\n");

    return 0;
}