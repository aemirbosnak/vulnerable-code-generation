//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for ASCII characters
#define CHAR_MAX 255
#define CHAR_MIN 0

// Define the dimensions of the image and the ASCII art
#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define ASCII_WIDTH 80
#define ASCII_HEIGHT 40

// Define a function to read in the image
void read_image(char* filename, int image[MAX_ROWS][MAX_COLUMNS], int* rows, int* columns) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "File '%s' not found\n", filename);
        exit(1);
    }

    fscanf(file, "%d %d", rows, columns);
    if (*rows > MAX_ROWS || *columns > MAX_COLUMNS) {
        fprintf(stderr, "Image dimensions must be <= %d rows and %d columns\n", MAX_ROWS, MAX_COLUMNS);
        exit(1);
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
}

// Define a function to convert an image to ASCII art
void convert_to_ascii(int image[MAX_ROWS][MAX_COLUMNS], int rows, int columns, char ascii_art[ASCII_HEIGHT][ASCII_WIDTH]) {
    float row_ratio = (float)rows / ASCII_HEIGHT;
    float column_ratio = (float)columns / ASCII_WIDTH;

    for (int i = 0; i < ASCII_HEIGHT; i++) {
        for (int j = 0; j < ASCII_WIDTH; j++) {
            int row_index = (int)(i * row_ratio);
            int column_index = (int)(j * column_ratio);

            int value = image[row_index][column_index];
            int index = (int)((float)(value - CHAR_MIN) / (CHAR_MAX - CHAR_MIN) * strlen(" .,:;ox%#@"));
            ascii_art[i][j] = " .,:;ox%#@"[index];
        }
    }
}

int main(int argc, char* argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image>\n", argv[0]);
        exit(1);
    }

    // Read in the image
    int image[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;
    read_image(argv[1], image, &rows, &columns);

    // Convert the image to ASCII art
    char ascii_art[ASCII_HEIGHT][ASCII_WIDTH];
    convert_to_ascii(image, rows, columns, ascii_art);

    // Print the ASCII art to the console
    for (int i = 0; i < ASCII_HEIGHT; i++) {
        for (int j = 0; j < ASCII_WIDTH; j++) {
            putchar(ascii_art[i][j]);
        }
        putchar('\n');
    }

    return 0;
}