//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct {
    unsigned char r, g, b;
} Pixel;

void image_to_ascii(FILE *img_file, FILE *art_file) {
    Pixel pixels[WIDTH][HEIGHT];
    int x, y;

    fread(pixels, sizeof(Pixel), WIDTH * HEIGHT, img_file);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Pixel p = pixels[x][y];
            char ascii_char = ' ';

            if (p.r > 128)
                ascii_char = 'X';
            else if (p.g > 128)
                ascii_char = 'O';
            else if (p.b > 128)
                ascii_char = '*';

            fprintf(art_file, "%c", ascii_char);
        }
        fprintf(art_file, "\n");
    }
}

int main(int argc, char **argv) {
    FILE *img_file = fopen("input.bmp", "rb");
    FILE *art_file = fopen("output.asc", "w");

    if (img_file == NULL || art_file == NULL) {
        fprintf(stderr, "Error: Could not open input or output files.\n");
        exit(1);
    }

    image_to_ascii(img_file, art_file);

    fclose(img_file);
    fclose(art_file);

    printf("Image to ASCII art conversion completed!\n");

    return 0;
}

// This is an exciting BMP image to ASCII art converter program!
// It reads a BMP image file and converts it into a beautiful ASCII art.
// The conversion is done using simple logic:
// - Pixels with red color above 128 become 'X'
// - Pixels with green color above 128 become 'O'
// - Pixels with blue color above 128 become '*'
//
// Give it a try with an input.bmp file and see the magic happen!
// The output will be saved in a file named output.asc.
//
// Let's celebrate the power of C programming language and create amazing stuff!
//
// Press Ctrl+C to compile and run the program.
//
// HURRAY!