//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// function to load image from file and return pixel data
uint32_t* load_image(const char * filename, int * width, int * height) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: could not open file %s for reading\n", filename);
        exit(1);
    }

    // read BMP header
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, f);

    // extract image dimensions from header
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // decode image pixel data from file
    uint32_t* pixels = (uint32_t*)malloc(sizeof(uint32_t) * (*width) * (*height));
    fseek(f, *(int*)&header[10], SEEK_SET);
    fread(pixels, sizeof(uint32_t), (*width) * (*height), f);
    fclose(f);

    return pixels;
}

// function to convert image pixel to ASCII character
char pixel_to_ascii(uint32_t pixel) {
    // extract red, green, and blue color values
    uint8_t red = (uint8_t)(pixel >> 16);
    uint8_t green = (uint8_t)(pixel >> 8);
    uint8_t blue = (uint8_t)pixel;

    // calculate grayscale value from RGB using luminosity method
    int grayscale = (int)(0.21 * red + 0.72 * green + 0.07 * blue);

    // map grayscale value to ASCII character
    char ascii_char = ' ';
    if (grayscale >= 0 && grayscale < 25) {
        ascii_char = '@';
    }
    else if (grayscale >= 25 && grayscale < 50) {
        ascii_char = '%';
    }
    else if (grayscale >= 50 && grayscale < 75) {
        ascii_char = '#';
    }
    else if (grayscale >= 75 && grayscale < 100) {
        ascii_char = '*';
    }
    else if (grayscale >= 100 && grayscale < 125) {
        ascii_char = '+';
    }
    else if (grayscale >= 125 && grayscale < 150) {
        ascii_char = '=';
    }
    else if (grayscale >= 150 && grayscale < 175) {
        ascii_char = '-';
    }
    else if (grayscale >= 175 && grayscale < 200) {
        ascii_char = ':';
    }
    else if (grayscale >= 200 && grayscale < 225) {
        ascii_char = '.';
    }
    else if (grayscale >= 225 && grayscale < 255) {
        ascii_char = ' ';
    }

    return ascii_char;
}

// main function to convert image to ASCII art
int main(int argc, char * argv[]) {
    // parse command-line arguments
    if (argc != 2) {
        printf("Usage: %s <image filename>\n", argv[0]);
        exit(1);
    }

    // load image from file
    int width, height;
    uint32_t* pixels = load_image(argv[1], &width, &height);

    // allocate memory for ASCII art buffer and convert pixels to ASCII characters
    char* ascii_art = (char*)malloc(sizeof(char) * (width + 1) * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint32_t pixel = pixels[y * width + x];
            char ascii_char = pixel_to_ascii(pixel);
            ascii_art[y * (width + 1) + x] = ascii_char;
        }
        ascii_art[y * (width + 1) + width] = '\n'; // add newline character at end of each row
    }

    // print ASCII art to console
    printf("%s", ascii_art);

    // free memory
    free(pixels);
    free(ascii_art);

    return 0;
}