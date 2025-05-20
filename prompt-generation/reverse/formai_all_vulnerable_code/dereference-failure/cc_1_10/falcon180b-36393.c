//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to convert image to ASCII art
void image_to_ascii(FILE *file, int width, int height, char *data) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            char c = data[i * width + j];
            if (c == 0) {
                fprintf(file, " ");
            } else {
                fprintf(file, "%c", c);
            }
        }
        fprintf(file, "\n");
    }
}

// Function to read image data from file
void read_image(FILE *file, int *width, int *height, char **data) {
    int c;
    char header[6] = {0};

    // Read header
    c = fgetc(file);
    while (c!= EOF && strncmp(header, "P6\n", 3)!= 0) {
        if (c == '#') {
            // Skip comment line
            while (c!= '\n') {
                c = fgetc(file);
            }
        } else {
            header[strlen(header)] = c;
        }
        c = fgetc(file);
    }

    // Read dimensions
    *width = atoi(header + 2);
    *height = atoi(header + 4);

    // Allocate memory for image data
    *data = malloc(*width * *height);
    if (*data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        exit(1);
    }

    // Read image data
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int c = fgetc(file);
            if (c == EOF) {
                fprintf(stderr, "Error: Unexpected end of file.\n");
                exit(1);
            }
            (*data)[i * *width + j] = c;
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file, *output_file;
    int width, height;
    char *data;

    // Open input file
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    // Read image data from input file
    read_image(input_file, &width, &height, &data);

    // Close input file
    fclose(input_file);

    // Open output file
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        free(data);
        return 1;
    }

    // Convert image to ASCII art
    image_to_ascii(output_file, width, height, data);

    // Close output file
    fclose(output_file);

    // Free memory
    free(data);

    return 0;
}