//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 30

// Function to print the ASCII art
void print_ascii_art(char image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

// Function to read the image file and store it in a 2D character array
bool read_image(char image[HEIGHT][WIDTH], FILE *fp) {
    int ch;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            ch = fgetc(fp);
            if (ch == EOF) {
                return false;
            }
            image[i][j] = ch;
        }
    }
    return true;
}

// Function to convert the image to ASCII art
void convert_to_ascii_art(char image[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int gray = (int) (0.3 * image[i][j] + 0.5); // Convert to grayscale
            if (gray < 0) {
                gray = 0;
            } else if (gray > 127) {
                gray = 127;
            }
            image[i][j] = gray;
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("image.bmp", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the image file
    char image[HEIGHT][WIDTH];
    if (!read_image(image, fp)) {
        printf("Error reading file.\n");
        exit(1);
    }

    // Convert the image to ASCII art
    convert_to_ascii_art(image);

    // Print the ASCII art
    print_ascii_art(image);

    return 0;
}