//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 120 // Maximum image width
#define HEIGHT 60 // Maximum image height
#define MAX_PIXEL_VALUE 255 // Maximum pixel value of the image

char ascii_list[] = {'#', 'M', 'X', 'N', 'W', 'Z', 'V', 'U', 'Y', 'K', 'H', 'Q', 'A', 'O', 'B', 'D', 'P', 'R', 'C', 'J', 'L', 'F', 'T', 'I', 'G', 'S', 'E', ' ', '.', ',', ':', ';', '!', '*', '+', '~', '%', 'S', 'o', 's', 'i', '>', '<'}; // List of ASCII characters to use for conversion
int ascii_count = sizeof(ascii_list) / sizeof(char); // Length of ASCII list

void print_ascii(int val) {
    int ascii_range = MAX_PIXEL_VALUE / ascii_count; // Range of each ASCII character

    for (int i = 0; i < ascii_count - 1; i++) {
        // If the pixel value falls within the range of this character and the next, print the character
        if (val >= i * ascii_range && val < (i + 1) * ascii_range) {
            printf("%c", ascii_list[i]);
            return;
        }
    }

    // If the pixel value is greater than or equal to the maximum pixel value, print the last character in the ASCII list
    printf("%c", ascii_list[ascii_count - 1]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input-image>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char magic_number[3];
    fgets(magic_number, 3, fp);
    if (strcmp(magic_number, "P5") != 0) {
        printf("Error: Invalid file format (%s).\n", magic_number);
        return 1;
    }

    char width_string[10];
    fgets(width_string, 10, fp);
    int width = atoi(width_string);
    if (width > WIDTH) {
        printf("Error: Image width exceeds maximum allowed width.\n");
        return 1;
    }

    char height_string[10];
    fgets(height_string, 10, fp);
    int height = atoi(height_string);
    if (height > HEIGHT) {
        printf("Error: Image height exceeds maximum allowed height.\n");
        return 1;
    }

    char max_value_string[10];
    fgets(max_value_string, 10, fp);
    int max_value = atoi(max_value_string);
    if (max_value > MAX_PIXEL_VALUE) {
        printf("Error: Image max pixel value exceeds maximum allowed pixel value.\n");
        return 1;
    }

    unsigned char image[WIDTH * HEIGHT]; // Array to store image data
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            print_ascii(image[i * width + j]); // Convert pixel values to ASCII characters
        }
        printf("\n");
    }

    return 0;
}