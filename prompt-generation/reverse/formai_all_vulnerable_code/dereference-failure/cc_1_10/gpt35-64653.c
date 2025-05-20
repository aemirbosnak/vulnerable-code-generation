//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

// Function to read image data from a file
void read_image(const char* filename, unsigned char image[MAX_SIZE][MAX_SIZE], int* rows, int* cols) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    // Read image header
    fscanf(file, "P5\n%d %d\n255\n", cols, rows);
    // Read image data
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            image[i][j] = (unsigned char) fgetc(file);
        }
    }
    fclose(file);
}

// Function to write image data to a file
void write_image(const char* filename, unsigned char image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    // Write image header
    fprintf(file, "P5\n%d %d\n255\n", cols, rows);
    // Write image data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fputc(image[i][j], file);
        }
    }
    fclose(file);
}

// Function to apply a horizontal flip to an image
void flip_horizontal(unsigned char image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    unsigned char temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols - j - 1];
            image[i][cols - j - 1] = temp;
        }
    }
}

// Function to apply a vertical flip to an image
void flip_vertical(unsigned char image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    unsigned char temp;
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            temp = image[i][j];
            image[i][j] = image[rows - i - 1][j];
            image[rows - i - 1][j] = temp;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: image_editor <filename> [commands...]\n");
        exit(1);
    }
    // Read image data from file
    unsigned char image[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    read_image(argv[1], image, &rows, &cols);
    printf("Image size: %d x %d\n", cols, rows);
    // Apply optional commands
    for (int i = 2; i < argc; i++) {
        if (argv[i][0] == '-') {
            char cmd = argv[i][1];
            switch (cmd) {
                case 'h':
                    flip_horizontal(image, rows, cols);
                    printf("Applied horizontal flip.\n");
                    break;
                case 'v':
                    flip_vertical(image, rows, cols);
                    printf("Applied vertical flip.\n");
                    break;
                default:
                    printf("Unknown command: %s\n", argv[i]);
                    break;
            }
        } else {
            printf("Unknown command: %s\n", argv[i]);
        }
    }
    // Write image data back to file
    write_image("output.pgm", image, rows, cols);
    printf("Output file written: output.pgm\n");
    return 0;
}