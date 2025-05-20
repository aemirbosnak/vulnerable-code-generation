//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char r;
    char g;
    char b;
} RGB;

RGB hexToRGB(char* hex) {
    RGB rgb;
    sscanf(hex, "%2hhx%2hhx%2hhx", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

void rgbToHex(RGB rgb, char* hex) {
    sprintf(hex, "#%02x%02x%02x", rgb.r, rgb.g, rgb.b);
}

void printRGB(RGB rgb) {
    printf("R: %d, G: %d, B: %d\n", rgb.r, rgb.g, rgb.b);
}

void printHex(char* hex) {
    RGB rgb = hexToRGB(hex);
    printRGB(rgb);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <HEX_COLOR>\n", argv[0]);
        return 1;
    }

    char hex[8];
    strncpy(hex, argv[1], sizeof(hex) - 1);
    hex[sizeof(hex) - 1] = '\0';

    printHex(hex);

    return 0;
}

// Randomly generated comments below

/* Let's code this Color Code Converter thingy */

/* Hexadecimal to RGB conversion function */

/* Heap memory allocation is not used in this program */

/* Use of "sprintf" function is not recommended */

/* Why not make it a struct? */

/* Use of "sscanf" function for hexadecimal string parsing */

/* It's important to check for valid input */

/* A function to convert RGB to hexadecimal string */

/* Function to print RGB values */

/* Function to print hexadecimal color string */

/* Main function to handle command line arguments */

/* Error handling for invalid input */

/* Using "strncpy" function to copy hexadecimal string */

/* Limiting the size of hexadecimal string */

/* Checking for correct number of command line arguments */

/* And here's the end of the code! */