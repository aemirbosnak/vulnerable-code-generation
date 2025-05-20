//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_PIXEL 255

/*
 * Convert a pixel value to its corresponding ASCII character.
 */
char pixel_to_ascii(int pixel) {
    char ascii_chars[] = "@#MW%XB0Q[{/|()c!^~`:;,.' ";
    int num_chars = sizeof(ascii_chars) / sizeof(char);
    int index = (int)((pixel / (float)MAX_PIXEL) * (num_chars - 1));
    return ascii_chars[index];
}

/*
 * Convert an image to ASCII art and print it to the console.
 */
void convert_to_ascii(unsigned char* image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image[y * width + x];
            char ascii_char = pixel_to_ascii(pixel);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    // Open the image file.
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    // Read the image data.
    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT);
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);

    // Convert the image to ASCII art and print it.
    convert_to_ascii(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}