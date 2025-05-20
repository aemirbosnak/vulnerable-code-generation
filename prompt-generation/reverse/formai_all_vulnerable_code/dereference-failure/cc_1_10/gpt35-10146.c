//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define constants for ASCII characters that will be used
#define ASCII_0        48
#define ASCII_A_UPPER  65
#define ASCII_A_LOWER  97

// Define the size of the output image
#define OUT_IMG_WIDTH  120
#define OUT_IMG_HEIGHT 60

// Define the size of the input image
#define IN_IMG_WIDTH  640
#define IN_IMG_HEIGHT 480

// Define the pixel structure to hold the RGB values
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

// Define the image structure to hold the pixel array
typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

// Function to read an image from file
void read_image(char *filename, image_t *image);

// Function to convert an image to ASCII art
void image_to_ascii(image_t *image, char *output);

int main(int argc, char *argv[]) {
    // Check that the user has provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input image> <output text file>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the input image
    image_t *input_image = (image_t *) malloc(sizeof(image_t));
    input_image->width = IN_IMG_WIDTH;
    input_image->height = IN_IMG_HEIGHT;
    input_image->pixels = (pixel_t *) malloc(sizeof(pixel_t) * input_image->width * input_image->height);

    // Read the input image from file
    read_image(argv[1], input_image);

    // Allocate memory for the output text
    char *output_text = (char *) malloc(sizeof(char) * OUT_IMG_WIDTH * OUT_IMG_HEIGHT);

    // Convert the input image to ASCII art
    image_to_ascii(input_image, output_text);

    // Write the output text to file
    FILE *output_file = fopen(argv[2], "w");
    fwrite(output_text, sizeof(char), OUT_IMG_WIDTH * OUT_IMG_HEIGHT, output_file);
    fclose(output_file);

    // Free the memory allocated for the input image and output text
    free(input_image->pixels);
    free(input_image);
    free(output_text);

    return 0;
}

void read_image(char *filename, image_t *image) {
    FILE *fp = fopen(filename, "rb");

    // Check that the file was opened successfully
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the BMP header to get information about the image
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, fp);

    // Check that the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: invalid BMP file format\n");
        exit(1);
    }

    // Extract the width and height of the image from the header
    int width = *(int *)(header + 18);
    int height = *(int *)(header + 22);

    // Check that the image is the correct size
    if (width != image->width || height != image->height) {
        printf("Error: image size does not match expected size\n");
        exit(1);
    }

    // Read the image data into the pixel array
    int padding = (4 - (width * 3) % 4) % 4;
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            pixel_t *pixel = &(image->pixels[y * width + x]);
            fread(&(pixel->blue), sizeof(uint8_t), 1, fp);
            fread(&(pixel->green), sizeof(uint8_t), 1, fp);
            fread(&(pixel->red), sizeof(uint8_t), 1, fp);
        }
        fseek(fp, padding, SEEK_CUR);
    }

    // Close the file
    fclose(fp);
}

void image_to_ascii(image_t *image, char *output) {
    // Define the ASCII character set
    char charset[] = {'#', 'M', 'X', 'D', 'O', 'I', 'Z', 'L', 'C', 'J', ';', ':', ',', '.', '-'};
    int num_chars = sizeof(charset) / sizeof(char);

    // Loop through each row of output pixels
    for (int y_out = 0; y_out < OUT_IMG_HEIGHT; y_out++) {
        // Calculate the corresponding row of input pixels
        int y_in = y_out * image->height / OUT_IMG_HEIGHT;

        // Loop through each column of output pixels
        for (int x_out = 0; x_out < OUT_IMG_WIDTH; x_out++) {
            // Calculate the corresponding column of input pixels
            int x_in = x_out * image->width / OUT_IMG_WIDTH;

            // Calculate the average brightness of the surrounding pixels
            int brightness = 0;
            for (int y_offset = -1; y_offset <= 1; y_offset++) {
                for (int x_offset = -1; x_offset <= 1; x_offset++) {
                    int x = x_in + x_offset;
                    int y = y_in + y_offset;
                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        pixel_t *pixel = &(image->pixels[y * image->width + x]);
                        brightness += pixel->red + pixel->green + pixel->blue;
                    }
                }
            }
            brightness /= 9;

            // Map the brightness to an ASCII character
            int index = (num_chars - 1) * brightness / 255;
            output[y_out * OUT_IMG_WIDTH + x_out] = charset[index];
        }
        // Set the end of the row to a newline character
        output[y_out * OUT_IMG_WIDTH + OUT_IMG_WIDTH - 1] = '\n';
    }
}