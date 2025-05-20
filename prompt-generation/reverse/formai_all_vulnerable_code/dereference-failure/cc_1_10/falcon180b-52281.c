//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

// Define the maximum width of the ASCII art
#define MAX_WIDTH 80

// Define the characters used to represent different shades of gray
char shades[] = "@%#*+=-:. ";

// Convert a grayscale value to an ASCII character
char grayscale_to_ascii(int value) {
    return shades[value % (sizeof(shades) - 1)];
}

// Read an image file and convert it to ASCII art
void image_to_ascii(const char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    uint8_t* data = (uint8_t*)malloc(width * height * 3);
    if (!data) {
        printf("Error: out of memory\n");
        exit(1);
    }

    if (fread(data, width * height * 3, 1, fp)!= 1) {
        printf("Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int index = y * width * 3 + x * 3;
            int value = data[index] + data[index + 1] + data[index + 2];
            value /= 3;
            printf("%c", grayscale_to_ascii(value));
        }
        printf("\n");
    }

    free(data);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    if (width <= 0 || height <= 0) {
        printf("Error: invalid image dimensions\n");
        return 1;
    }

    image_to_ascii(argv[1], width, height);

    return 0;
}