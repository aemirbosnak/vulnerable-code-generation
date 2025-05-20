//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// The character set we will use for our ASCII art
#define CHAR_SET "@#SB8XOo+=:-. " 
#define CHAR_SET_SIZE 13

// Each character in the character set has an associated brightness value
// that we use to determine which character to use for each pixel
const int CHAR_SET_BRIGHTNESS[CHAR_SET_SIZE+1] = {230, 200, 180, 160, 130, 100, 70, 50, 30, 20, 10, 5, 0};

// Helper function that returns the brightness of a given pixel
int pixel_brightness(unsigned char r, unsigned char g, unsigned char b) {
    // We use the luminosity method to calculate the brightness
    // luminosity = 0.21 * R + 0.72 * G + 0.07 * B
    int brightness = 0.21*r + 0.72*g + 0.07*b;
    return brightness;
}

// Helper function that finds the closest character in the character set to a given brightness value
char closest_char(int brightness) {
    int min_distance = 255*255*3; // Max distance possible
    char closest_char = ' '; // Default closest char is space
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        int distance = abs(brightness - CHAR_SET_BRIGHTNESS[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_char = CHAR_SET[i];
        }
    }
    return closest_char;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the header of the input file to get image width and height
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Make sure the image is not too big
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image is too big\n");
        return 1;
    }

    // Calculate the padding size, since each row of pixels must be a multiple of 4 bytes
    int padding_size = 4 - (width * 3) % 4;
    if (padding_size == 4) padding_size = 0;

    // Allocate memory for the image buffer
    unsigned char image[height][width][3];

    // Read the pixels of the image into the buffer
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(image[y][x], sizeof(unsigned char), 3, input_file);
        }
        fseek(input_file, padding_size, SEEK_CUR); // Skip padding
    }

    // Close the input file
    fclose(input_file);

    // Open the output file for writing
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Error: could not open file %s\n", argv[2]);
        return 1;
    }

    // Write the ASCII art to the output file
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the brightness of the pixel
            int brightness = pixel_brightness(image[y][x][0], image[y][x][1], image[y][x][2]);
            // Find the closest character in the character set to the brightness value
            char c = closest_char(brightness);
            // Write the character to the output file
            fputc(c, output_file);
        }
        // Add a newline character at the end of each row
        fputc('\n', output_file);
    }

    // Close the output file
    fclose(output_file);

    printf("Done!\n");
    return 0;
}