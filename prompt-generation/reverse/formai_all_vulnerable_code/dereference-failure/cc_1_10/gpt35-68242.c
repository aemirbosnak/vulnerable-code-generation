//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char r, g, b;
} RGB_pixel;

char ASCII_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

void convert_to_greyscale(RGB_pixel image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            unsigned char greyscale_value = (image[i][j].r * 0.299) + (image[i][j].g * 0.587) + (image[i][j].b * 0.114);
            image[i][j].r = greyscale_value;
            image[i][j].g = greyscale_value;
            image[i][j].b = greyscale_value;
        }
    }
}

char get_ascii_char(unsigned char value) {
    int num_chars = strlen(ASCII_chars);
    int increment = 255 / num_chars;
    int index = value / increment;
    if(index >= num_chars) index = num_chars - 1;
    return ASCII_chars[index];
}

void convert_to_ascii(RGB_pixel image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            char ascii_char = get_ascii_char(image[i][j].r);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];

    FILE *file_ptr;
    RGB_pixel image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    file_ptr = fopen(input_file, "rb");

    if(file_ptr == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    char magic_number[2];
    fscanf(file_ptr, "%s", magic_number);

    if(strcmp(magic_number, "P6") != 0) {
        printf("Error: Invalid input file format\n");
        return 1;
    }

    fscanf(file_ptr, "%d %d", &width, &height);
    if(width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image size exceeds the maximum width and height\n");
        return 1;
    }

    int max_color;
    fscanf(file_ptr, "%d", &max_color);

    if(max_color > 255) {
        printf("Error: Maximum color value cannot be greater than 255\n");
        return 1;
    }

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            unsigned char red, green, blue;
            fread(&red, 1, 1, file_ptr);
            fread(&green, 1, 1, file_ptr);
            fread(&blue, 1, 1, file_ptr);
            image[i][j].r = red;
            image[i][j].g = green;
            image[i][j].b = blue;
        }
    }

    fclose(file_ptr);

    convert_to_greyscale(image, height, width);
    convert_to_ascii(image, height, width);

    return 0;
}