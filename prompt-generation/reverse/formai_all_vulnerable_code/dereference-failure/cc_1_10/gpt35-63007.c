//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Color struct to hold RGB values
typedef struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

// Function to convert RGB color to grayscale value using standard formula
unsigned char rgb_to_gray(Color c) {
    return 0.2126*c.r + 0.7152*c.g + 0.0722*c.b;
}

// Function to convert grayscale value to ASCII character
char gray_to_char(unsigned char gray) {
    char *chars = " .:-=+*#%@";
    int num_chars = strlen(chars);
    int gray_range = 255/num_chars; // divide grayscale range into intervals for each character
    int idx = gray/gray_range;
    return chars[idx];
}

// Function to convert image to ASCII art
void image_to_ascii(Color img[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    char ascii[MAX_HEIGHT][MAX_WIDTH]; // buffer for ASCII art image
    // convert each pixel to grayscale and then to ASCII character
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            unsigned char gray = rgb_to_gray(img[i][j]);
            ascii[i][j] = gray_to_char(gray);
        }
    }
    // print ASCII art to console
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            putchar(ascii[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    // read image from file
    FILE *fp = fopen("input.ppm", "r");
    if(!fp) {
        fprintf(stderr, "Error: Couldn't open file.\n");
        exit(1);
    }
    char magic_num[3];
    fscanf(fp, "%s", magic_num); // read magic number
    if(strcmp(magic_num, "P3") != 0) { // make sure file is PPM format
        fprintf(stderr, "Error: Invalid file format.\n");
        exit(1);
    }
    int width, height, max_val;
    fscanf(fp, "%d %d %d", &width, &height, &max_val); // read image metadata
    if(width > MAX_WIDTH || height > MAX_HEIGHT) { // check image dimensions
        fprintf(stderr, "Error: Image too large.\n");
        exit(1);
    }
    Color img[MAX_HEIGHT][MAX_WIDTH]; // buffer for image
    for(int i = 0; i < height; i++) { // read image pixel data
        for(int j = 0; j < width; j++) {
            int r, g, b;
            fscanf(fp, "%d %d %d", &r, &g, &b);
            if(r > max_val || g > max_val || b > max_val) { // check pixel values
                fprintf(stderr, "Error: Pixel value out of range.\n");
                exit(1);
            }
            img[i][j].r = r;
            img[i][j].g = g;
            img[i][j].b = b;
        }
    }
    fclose(fp);
    // convert image to ASCII art and print
    image_to_ascii(img, height, width);
    return 0;
}