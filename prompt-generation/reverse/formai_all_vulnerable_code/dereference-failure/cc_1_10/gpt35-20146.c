//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255  // Maximum value of a pixel
#define MAX_WIDTH 1000       // Maximum width of the image
#define MAX_HEIGHT 1000      // Maximum height of the image

char ASCII_CHARS[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.', ' '};
// ASCII characters used to represent pixel values

int get_pixel_value(int red, int green, int blue);
// Function to convert the RGB values of a pixel to a single pixel value

void convert_image_to_ascii(FILE *infile, FILE *outfile, int width, int height, int char_width, int char_height);
// Function to convert the image to ASCII art

int main(int argc, char *argv[])
{
    if (argc < 6) {
        printf("Usage: %s input_file output_file width height char_width char_height\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int width = atoi(argv[3]);
    int height = atoi(argv[4]);
    int char_width = atoi(argv[5]);
    int char_height = atoi(argv[6]);

    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *outfile = fopen(output_file, "w");
    if (!outfile) {
        printf("Error opening output file\n");
        exit(1);
    }

    convert_image_to_ascii(infile, outfile, width, height, char_width, char_height);

    fclose(infile);
    fclose(outfile);

    return 0;
}

int get_pixel_value(int red, int green, int blue)
{
    // Convert the RGB values to grayscale
    int value = (red + green + blue) / 3;

    // Scale the pixel value to match the range of ASCII characters used
    int scaled_value = (value * 12) / MAX_PIXEL_VALUE;

    // Make sure the pixel value is not out of range
    if (scaled_value >= 12) {
        scaled_value = 11;
    }

    return scaled_value;
}

void convert_image_to_ascii(FILE *infile, FILE *outfile, int width, int height, int char_width, int char_height)
{
    unsigned char image[MAX_WIDTH][MAX_HEIGHT][3];  // Array to store pixel values of the image
    int char_count = 0;                             // Counter for the number of characters written in each row
    char character;                                 // Current ASCII character
    int pixel_value;                                 // Current pixel value
    int row, col, i, j;                             // Loop variables

    // Read the image data from the input file
    fread(image, sizeof(unsigned char), width * height * 3, infile);

    // Write the ASCII art to the output file
    for (row = 0; row < height; row += char_height) {
        for (col = 0; col < width; col += char_width) {
            // Calculate the average pixel value for the current character block
            pixel_value = 0;
            for (i = 0; i < char_height && row + i < height; i++) {
                for (j = 0; j < char_width && col + j < width; j++) {
                    pixel_value += get_pixel_value(image[row + i][col + j][0], 
                                                     image[row + i][col + j][1], 
                                                     image[row + i][col + j][2]);
                }
            }
            pixel_value /= (char_width * char_height);

            // Write the corresponding ASCII character to the output file based on the pixel value
            character = ASCII_CHARS[pixel_value];
            fputc(character, outfile);
            char_count++;

            // Print a space character between each block of characters
            if (char_count == (width / char_width)) {
                fputc('\n', outfile);
                char_count = 0;
            } else {
                fputc(' ', outfile);
            }
        }
        if (char_count != 0) {
            fputc('\n', outfile);
            char_count = 0;
        }
    }
}