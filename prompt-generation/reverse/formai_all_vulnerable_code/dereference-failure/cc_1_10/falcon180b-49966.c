//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to print the ASCII art
void print_ascii_art(char *ascii_art, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i * width + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(FILE *fp, char *ascii_art, int width, int height) {
    int i, j, k;
    unsigned char pixel;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = 0;
            while (k < 3) {
                fread(&pixel, 1, 1, fp);
                if (pixel < 128) {
                    ascii_art[i * width + j] = '@';
                } else if (pixel < 192) {
                    ascii_art[i * width + j] = '#';
                } else if (pixel < 224) {
                    ascii_art[i * width + j] = '$';
                } else {
                    ascii_art[i * width + j] = '%';
                }
                k++;
            }
        }
    }
}

// Function to read image dimensions from file
void read_image_dimensions(FILE *fp, int *width, int *height) {
    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Extract image dimensions from header
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE *fp_in, *fp_out;
    char *ascii_art = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    int width, height;

    // Open input image file
    fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input image file.\n");
        return 1;
    }

    // Read image dimensions from file
    read_image_dimensions(fp_in, &width, &height);

    // Convert image to ASCII art
    image_to_ascii_art(fp_in, ascii_art, width, height);

    // Close input image file
    fclose(fp_in);

    // Open output ASCII art file
    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: Could not open output ASCII art file.\n");
        return 1;
    }

    // Print ASCII art
    print_ascii_art(ascii_art, width, height);

    // Close output ASCII art file
    fclose(fp_out);

    free(ascii_art);
    return 0;
}