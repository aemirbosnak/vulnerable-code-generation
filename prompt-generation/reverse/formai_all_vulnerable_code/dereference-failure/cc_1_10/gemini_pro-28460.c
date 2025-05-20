//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to represent different shades of gray
char *shades[] = {
    " ", ".", ",", "-", "~", ":", ";", "=", "+", "*", "#", "@", "%", "$", "!", "(", ")", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
};
// Get the width and height of the image
int get_image_dimensions(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    // Read the header of the image
    char header[54];
    fread(header, sizeof(char), 54, fp);

    // Get the width and height of the image
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Close the file
    fclose(fp);

    return 0;
}

// Read the pixel data from the image
int read_pixel_data(char *filename, unsigned char *data, int width, int height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    // Seek to the start of the pixel data
    fseek(fp, 54, SEEK_SET);

    // Read the pixel data
    fread(data, sizeof(unsigned char), width * height * 3, fp);

    // Close the file
    fclose(fp);

    return 0;
}

// Convert the pixel data to ASCII art
char *convert_to_ascii_art(unsigned char *data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii_art = malloc(width * height * sizeof(char));
    if (ascii_art == NULL) {
        return NULL;
    }

    // Convert the pixel data to ASCII art
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Get the average of the red, green, and blue values of the pixel
            int average = (data[i * width * 3 + j * 3] + data[i * width * 3 + j * 3 + 1] + data[i * width * 3 + j * 3 + 2]) / 3;

            // Get the corresponding character for the shade of gray
            char shade = shades[average / 25];

            // Set the character in the ASCII art
            ascii_art[i * width + j] = shade;
        }
    }

    // Return the ASCII art
    return ascii_art;
}

// Write the ASCII art to a file
int write_ascii_art_to_file(char *filename, char *ascii_art, int width, int height) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the ASCII art to the file
    fprintf(fp, "%s", ascii_art);

    // Close the file
    fclose(fp);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <input image> <output ASCII art>\n", argv[0]);
        return -1;
    }

    // Get the input image filename
    char *input_filename = argv[1];

    // Get the output ASCII art filename
    char *output_filename = argv[2];

    // Get the width and height of the image
    int width, height;
    if (get_image_dimensions(input_filename, &width, &height) != 0) {
        printf("Error getting image dimensions\n");
        return -1;
    }

    // Read the pixel data from the image
    unsigned char *data = malloc(width * height * 3 * sizeof(unsigned char));
    if (data == NULL) {
        printf("Error allocating memory for pixel data\n");
        return -1;
    }

    if (read_pixel_data(input_filename, data, width, height) != 0) {
        printf("Error reading pixel data\n");
        return -1;
    }

    // Convert the pixel data to ASCII art
    char *ascii_art = convert_to_ascii_art(data, width, height);
    if (ascii_art == NULL) {
        printf("Error converting pixel data to ASCII art\n");
        return -1;
    }

    // Write the ASCII art to a file
    if (write_ascii_art_to_file(output_filename, ascii_art, width, height) != 0) {
        printf("Error writing ASCII art to file\n");
        return -1;
    }

    // Free the memory allocated for the pixel data
    free(data);

    // Free the memory allocated for the ASCII art
    free(ascii_art);

    return 0;
}