//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

void toChar(double, char *);
void toGray(char *, double);
void load_image(double **, char *);
void convert_image(double **, char (*)[WIDTH + 1], int, int);

int main(int argc, char **argv) {
    char filename[100], ascii_filename[100];
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strncpy(filename, argv[1], sizeof(filename) - 1);
    sprintf(ascii_filename, "%s.txt", filename);

    // Load image data from file
    double **data = malloc(HEIGHT * sizeof(double *));
    for (int i = 0; i < HEIGHT; i++) {
        data[i] = malloc(WIDTH * sizeof(double));
    }
    load_image(data, filename);

    // Convert image to ASCII art
    char ascii[HEIGHT][WIDTH + 1];
    convert_image(data, ascii, HEIGHT, WIDTH);

    // Write ASCII art to file
    FILE *fp = fopen(ascii_filename, "w");
    for (int i = 0; i < HEIGHT; i++) {
        fprintf(fp, "%s\n", ascii[i]);
    }
    fclose(fp);

    // Clean up
    for (int i = 0; i < HEIGHT; i++) {
        free(data[i]);
    }
    free(data);

    return EXIT_SUCCESS;
}

void toChar(double val, char *c) {
    static char chars[] = "@#MW*!+;:,.'` ";
    int idx = floor(val / (256.0 / (sizeof(chars) - 1)));
    *c = chars[idx];
}

void toGray(char *gray, double val) {
    char c;
    toChar(val, &c);
    *gray = c;
}

void load_image(double **data, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Unable to open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fread(data, sizeof(double), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void convert_image(double **data, char (*ascii)[WIDTH + 1], int height, int width) {
    double max_val = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }
        }
    }
    max_val = max_val / 2.0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double val = data[i][j];
            toGray(&ascii[i][j], val / max_val);
        }
        ascii[i][width] = '\0';
    }
}