//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants for ASCII characters used in conversion
const char* ASCII_CHARS = " .:-=+*#%@";
const int NUM_CHARS = 10;

// Function to load image file
int** load_image(char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }

    // Read image header
    char magic[3];
    int maxval;
    fscanf(fp, "%s\n%d %d\n%d\n", magic, width, height, &maxval);
    if (!strcmp(magic, "P2") == 0) {
        printf("Invalid file format\n");
        exit(1);
    }

    // Allocate memory for image pixel values
    int** image = (int**)malloc(*height * sizeof(int*));
    for (int i = 0; i < *height; i++) {
        image[i] = (int*)malloc(*width * sizeof(int));
    }

    // Read image pixel values
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);
    return image;
}

// Function to convert pixel values to ASCII characters
char pixel_to_ascii(int pixel_val) {
    int range = (255 / NUM_CHARS) + 1;
    int index = pixel_val / range;
    return ASCII_CHARS[index];
}

// Function to print ASCII art
void print_ascii_art(int** image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixel_to_ascii(image[i][j]));
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    int width, height;
    int** image = load_image(argv[1], &width, &height);
    print_ascii_art(image, width, height);

    // Free memory used for image
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}