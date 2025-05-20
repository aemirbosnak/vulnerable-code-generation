//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_LENGTH 10000000

/* Function to convert a RGB pixel to grayscale */
unsigned char rgb_to_gray(unsigned char r, unsigned char g, unsigned char b) {
    return 0.21 * r + 0.71 * g + 0.07 * b;
}

/* Function to apply grayscale filter to an image */
void grayscale_filter(unsigned char *pixels, int width, int height) {
    int i, j;
    unsigned char red, green, blue, gray;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            /* Get the RGB values for the current pixel */
            red = pixels[(i * width + j) * 3];
            green = pixels[(i * width + j) * 3 + 1];
            blue = pixels[(i * width + j) * 3 + 2];

            /* Convert RGB to grayscale */
            gray = rgb_to_gray(red, green, blue);

            /* Set the pixel to grayscale value */
            pixels[(i * width + j) * 3] = gray;
            pixels[(i * width + j) * 3 + 1] = gray;
            pixels[(i * width + j) * 3 + 2] = gray;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[256], output_filename[256];
    unsigned char *pixels, *pixels_copy, *temp;
    char command;

    /* Ask the user for the input filename */
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    /* Open the input file */
    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: Could not open file %s\n", input_filename);
        return 1;
    }

    /* Allocate memory for the pixels */
    pixels = (unsigned char *) malloc(MAX_FILE_LENGTH);
    pixels_copy = (unsigned char *) malloc(MAX_FILE_LENGTH);

    /* Read the contents of the input file into memory */
    fread(pixels, sizeof(char), MAX_FILE_LENGTH, input_file);

    /* Close the input file */
    fclose(input_file);

    /* Ask the user for the desired command */
    printf("Enter command (g for grayscale, q to quit): ");
    while (scanf("%c", &command) == 1 && command != 'q') {
        /* Copy the pixels to the copy buffer */
        memcpy(pixels_copy, pixels, MAX_FILE_LENGTH);

        switch (tolower(command)) {
            case 'g':
                printf("Applying grayscale filter...\n");
                grayscale_filter(pixels_copy, 512, 512);
                break;
            default:
                printf("Command not recognized.\n");
                break;
        }

        /* Ask the user for the output filename */
        printf("Enter the name of the output file: ");
        scanf("%s", output_filename);

        /* Open the output file */
        output_file = fopen(output_filename, "wb");
        if (!output_file) {
            printf("Error: Could not open file %s\n", output_filename);
            return 1;
        }

        /* Write the contents of the pixels to the output file */
        fwrite(pixels_copy, sizeof(char), MAX_FILE_LENGTH, output_file);

        /* Close the output file */
        fclose(output_file);

        /* Swap the pointers to the pixels buffers */
        temp = pixels;
        pixels = pixels_copy;
        pixels_copy = temp;

        /* Ask the user for the desired command */
        printf("Enter command (g for grayscale, q to quit): ");
    }

    /* Free memory */
    free(pixels);
    free(pixels_copy);

    return 0;
}