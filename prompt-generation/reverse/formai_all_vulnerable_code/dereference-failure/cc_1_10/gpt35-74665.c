//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the width and height of the ASCII image
#define WIDTH 80
#define HEIGHT 60

// Function to convert an RGB pixel to grayscale
int rgb_to_grayscale(int r, int g, int b) {
    return (int)(0.299 * r + 0.587 * g + 0.114 * b);
}

// Function to read an image from a file
int **read_image(char *filename) {
    // Open the image file for binary reading
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file \"%s\"\n", filename);
        exit(1);
    }

    // Read in the image header
    char magic_number[3];
    fscanf(fp, "%s", magic_number);
    int width, height, maxval;
    fscanf(fp, "%d %d %d", &width, &height, &maxval);
    if (strcmp(magic_number, "P6") != 0) {
        printf("Error: Invalid image format (must be P6)\n");
        exit(1);
    }
    if (width != WIDTH || height != HEIGHT || maxval != 255) {
        printf("Error: Unsupported image format or size\n");
        exit(1);
    }

    // Allocate memory for the image data and read it in
    int **image_data = malloc(sizeof(int*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        image_data[i] = malloc(sizeof(int) * WIDTH);
    }
    unsigned char buffer[3];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fread(buffer, sizeof(unsigned char), 3, fp);
            image_data[i][j] = rgb_to_grayscale((int)buffer[0], (int)buffer[1], (int)buffer[2]);
        }
    }

    // Close the image file and return the image data
    fclose(fp);
    return image_data;
}

// Function to convert a grayscale value to an ASCII character
char grayscale_to_ascii(int value) {
    static char *ascii_chars = " .,-~:;=*^#@";
    int num_chars = strlen(ascii_chars);
    return ascii_chars[(int)((value / 255.0) * (num_chars - 1))];
}

// Function to print an ASCII image
void print_ascii_image(int **image_data) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grayscale_to_ascii(image_data[i][j]));
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        exit(1);
    }
    int **image_data = read_image(argv[1]);
    print_ascii_image(image_data);
    return 0;
}