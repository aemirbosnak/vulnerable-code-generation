//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80        // Number of characters in a row
#define HEIGHT 25       // Number of rows
#define MAX_PIXEL 256   // Maximum value for a pixel

// Structure to hold a RGB color
typedef struct Color {
    int r, g, b;
} Color;

// Function pointer type to convert a pixel to char
typedef char (*PixelToCharFn)(unsigned char);

// Predefined char mapping functions
char map_pixels_1(unsigned char);
char map_pixels_2(unsigned char);
char map_pixels_3(unsigned char);
char map_pixels_4(unsigned char);

// The main conversion function, takes a file pointer to read the image from and a funtion pointer to map the pixel to a char
char* convert_to_ascii(FILE* img_file, PixelToCharFn map_func);

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file
    FILE* img_file = fopen(argv[1], "rb");
    if (!img_file) {
        printf("Error: can't open file\n");
        exit(EXIT_FAILURE);
    }

    // Convert the image to ASCII art using one of the predefined mapping functions
    char* ascii_img = convert_to_ascii(img_file, map_pixels_1);

    // Open the output file and write the ASCII art to it
    FILE* out_file = fopen(argv[2], "w");
    if (!out_file) {
        printf("Error: can't open file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(out_file, "%s", ascii_img);

    // Clean up and exit
    fclose(img_file);
    fclose(out_file);
    free(ascii_img);
    return 0;
}

char* convert_to_ascii(FILE* img_file, PixelToCharFn map_func) {
    // Read the header of the BMP file
    char header[54];
    fread(header, sizeof(char), 54, img_file);

    // Extract image width, height and bit depth from the header
    int stride = (WIDTH * 3 + 3) & ~3;
    int row_size = WIDTH * 3;
    int img_width = *(int*)(header + 18);
    int img_height = *(int*)(header + 22);
    int bit_depth = *(short*)(header + 28);

    // Check if the image is 24-bit BMP image
    if (bit_depth != 24) {
        printf("Error: the file is not a 24-bit BMP image\n");
        exit(EXIT_FAILURE);
    }

    // Check if the image size matches the desired ASCII art size
    if (img_width != WIDTH || img_height != HEIGHT) {
        printf("Error: the image size must be %dx%d\n", WIDTH, HEIGHT);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the ASCII art buffer (+1 for the terminating null character)
    char* ascii_buf = (char*)malloc(sizeof(char) * (WIDTH * HEIGHT + 1));
    if (!ascii_buf) {
        printf("Error: can't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Read the image pixel data from the file
    Color img_buf[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; ++i) {
        fseek(img_file, 54 + (img_height - i - 1) * stride, SEEK_SET);
        for (int j = 0; j < WIDTH; ++j) {
            unsigned char rgb[3];
            fread(rgb, sizeof(unsigned char), 3, img_file);
            img_buf[i][j].r = rgb[2];
            img_buf[i][j].g = rgb[1];
            img_buf[i][j].b = rgb[0];
        }
    }

    // Convert the image to ASCII art
    char* p = ascii_buf;
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            unsigned char gray = (img_buf[i][j].r + img_buf[i][j].g + img_buf[i][j].b) / 3;
            *p++ = map_func(gray);
        }
        *p++ = '\n';
    }
    *p = '\0';

    // Return the resulting ASCII art buffer
    return ascii_buf;
}

char map_pixels_1(unsigned char gray) {
    char chars[] = {'#', 'M', 'H', 'X', 'G', 'I', ':', '.', ' ', ' '};
    int size = sizeof(chars) / sizeof(char);
    return chars[gray / (MAX_PIXEL / size)];
}

char map_pixels_2(unsigned char gray) {
    char chars[] = {'@', '%', '#', '*', '+', '=', '-', ':', '.', ' '};
    int size = sizeof(chars) / sizeof(char);
    return chars[gray / (MAX_PIXEL / size)];
}

char map_pixels_3(unsigned char gray) {
    char chars[] = {'@', 'B', '%', '8', '&', 'W', 'M', '#', '*', 'o', 'a', 'h', 'k', 'b', 'd', 'p', 'q', 'w', 'm', 'Z', 'O', '0', 'Q', 'L', 'C', 'J', 'U', 'Y', 'X', 'z', 'c', 'v', 'u', 'n', 'x', 'r', 'j', 'f', 't', '/', '|', '(', ')', '1', '{', '}', '[', ']', '?', '-', '_', '+', '~', '<', '>', 'i', '!', 'l', 'I', ';', ':', ',', '"', '^', '`', '\'', '.', ' '};
    int size = sizeof(chars) / sizeof(char);
    return chars[gray / (MAX_PIXEL / size)];
}

char map_pixels_4(unsigned char gray) {
    char chars[] = {'M', 'N', 'H', 'Q', 'O', 'C', '>', '?', ' ', ' '};
    int size = sizeof(chars) / sizeof(char);
    return chars[gray / (MAX_PIXEL / size)];
}