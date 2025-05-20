//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grayscale[] = " .:-=+*#%@";
int graylength = 10;

void resize(int rows, int cols, int *newrows, int *newcols, int ratio) {
    *newrows = rows / ratio;
    *newcols = cols / (ratio * 2);
}

void convert(char *input_filename, int ratio) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int rows = 0, cols = 0;
    int newrows, newcols;
    int i, j, k;
    char c;
    int intensity;

    // Open input file
    fp = fopen(input_filename, "r");
    if (fp == NULL) {
        perror("Error: Could not open input file.");
        exit(EXIT_FAILURE);
    }

    // Read the PGM header to get image size
    getline(&line, &len, fp);
    if (strncmp(line, "P5", 2) != 0) {
        perror("Error: Input file is not a valid PGM file.");
        exit(EXIT_FAILURE);
    }
    while (rows == 0 || cols == 0) {
        getline(&line, &len, fp);
        if (strncmp(line, "#", 1) != 0) {
            sscanf(line, "%d %d", &cols, &rows);
        }
    }
    while (fgetc(fp) != '\n') {}

    // Compute new image size after resizing
    resize(rows, cols, &newrows, &newcols, ratio);

    // Allocate new image buffer
    unsigned char *image = malloc(sizeof(unsigned char) * rows * cols);
    unsigned char *newimage = calloc(newrows * newcols, sizeof(unsigned char));

    // Read image data from input file into image buffer
    fread(image, sizeof(unsigned char), rows * cols, fp);

    // Close input file
    fclose(fp);

    // Generate ASCII art from image data
    for (i = 0; i < newrows; i++) {
        for (j = 0; j < newcols; j++) {
            intensity = 0;
            for (k = 0; k < ratio; k++) {
                if (i * ratio + k < rows && j * ratio * 2 + k * 2 < cols) {
                    intensity += image[(i * ratio + k) * cols + (j * ratio * 2 + k * 2)];
                }
            }
            intensity /= ratio * graylength;
            c = grayscale[intensity];
            newimage[i * newcols + j] = c;
        }
    }

    // Print ASCII art to console
    for (i = 0; i < newrows; i++) {
        for (j = 0; j < newcols; j++) {
            printf("%c%c", newimage[i * newcols + j], newimage[i * newcols + j]);
        }
        printf("\n");
    }

    // Free memory
    free(image);
    free(newimage);
}

int main(int argc, char **argv) {
    int ratio = 1;
    char *filename = argv[1];
    if (argv[2] != NULL) {
        ratio = atoi(argv[2]);
    }
    convert(filename, ratio);
    return 0;
}