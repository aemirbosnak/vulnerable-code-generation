//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Function to print the ASCII art
void print_ascii_art(int width, int height, char *ascii_art) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i * width + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(int width, int height, unsigned char *image_data, char *ascii_art) {
    // Base case: single pixel
    if (width == 1 && height == 1) {
        ascii_art[0] = (image_data[0] < 128)? '.' : '*';
        return;
    }

    // Recursive case
    int half_width = width / 2;
    int half_height = height / 2;

    unsigned char *top_left = image_data;
    unsigned char *top_right = image_data + half_width;
    unsigned char *bottom_left = image_data + half_height * width;
    unsigned char *bottom_right = image_data + (half_height * width) + half_width;

    image_to_ascii_art(half_width, half_height, top_left, ascii_art);
    image_to_ascii_art(half_width, half_height, top_right, ascii_art + half_height * width);
    image_to_ascii_art(half_width, half_height, bottom_left, ascii_art + (2 * half_height) * width);
    image_to_ascii_art(half_width, half_height, bottom_right, ascii_art + (3 * half_height) * width);
}

int main() {
    // Example image data
    unsigned char image_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 0, 0, 0, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 0, 0, 0, 0, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 0
    };

    // Convert image to ASCII art
    int width = 8;
    int height = 8;
    char ascii_art[width * height];
    image_to_ascii_art(width, height, image_data, ascii_art);

    // Print ASCII art
    print_ascii_art(width, height, ascii_art);

    return 0;
}