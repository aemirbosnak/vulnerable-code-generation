//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH 80      /* maximum width of the ASCII art */
#define MAX_HEIGHT 80     /* maximum height of the ASCII art */
#define ASCII_SCALE 4     /* scaling factor for ASCII conversion */
#define COLOR_SCALE 3     /* scaling factor for color conversion */
#define MAX_CHARS 69      /* maximum number of ASCII characters used for conversion */
#define MAX_COLORS 16     /* maximum number of colors used in the original image */

/* function prototypes */
bool is_color(int pixel, int *colors, int num_colors);
char get_char(int pixel, int *chars, int *colors, int num_chars, int num_colors);
void convert_image(unsigned char *image_data, int image_width, int image_height, char *output, int *chars, int *colors, int num_chars, int num_colors);

int main() {
    /* initialize variables */
    unsigned char image_data[MAX_WIDTH * MAX_HEIGHT];
    int image_width = 0, image_height = 0;
    char output[MAX_WIDTH * MAX_HEIGHT * ASCII_SCALE];
    char ascii_chars[MAX_CHARS] = {' ', '.', '\'', '`', '^', '"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_', '-', '/', '|', '(', ')', '1', '{', '}', '[', ']', '?', '-', '@', 'C', '$', '%', '&', '#', '*', 'o', 'c', 'r', 'v', 'u', 'n', 'x', 'z', 'X', 'Z', 'Y', 'U', 'J', 'L', 'Q', '0', 'O', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'h', 'a', 'e', 'r', 'y', 't', 'f', 's', 'g'};
    int colors[MAX_COLORS] = {0, 28, 56, 85, 113, 141, 170, 198, 226, 255};
    int num_chars = sizeof(ascii_chars) / sizeof(char);
    int num_colors = sizeof(colors) / sizeof(int);

    /* read image data from file */
    FILE *image_file = fopen("image.raw", "rb");
    if (image_file == NULL) {
        printf("Could not open image file.\n");
        return 1;
    }
    fread(&image_width, sizeof(int), 1, image_file);
    fread(&image_height, sizeof(int), 1, image_file);
    fread(image_data, sizeof(unsigned char), image_width * image_height, image_file);
    fclose(image_file);

    /* convert image data to ASCII art */
    convert_image(image_data, image_width, image_height, output, ascii_chars, colors, num_chars, num_colors);

    /* output ASCII art */
    printf("%s\n", output);

    return 0;
}

/* check if pixel color is one of the specified colors */
bool is_color(int pixel, int *colors, int num_colors) {
    for (int i = 0; i < num_colors; i++) {
        if (pixel == colors[i]) {
            return true;
        }
    }
    return false;
}

/* convert pixel to ASCII character */
char get_char(int pixel, int *chars, int *colors, int num_chars, int num_colors) {
    if (is_color(pixel, colors, num_colors)) {
        /* find closest ASCII character match based on pixel intensity */
        int intensity = (int)((float)pixel / 255 * (num_chars - 1));
        return chars[intensity];
    } else {
        /* pixel is not one of the specified colors, return empty space */
        return ' ';
    }
}

/* convert image to ASCII art */
void convert_image(unsigned char *image_data, int image_width, int image_height, char *output, int *chars, int *colors, int num_chars, int num_colors) {
    int output_index = 0;
    /* loop over image pixels */
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            int pixel = image_data[i * image_width + j];
            char ascii_char = get_char(pixel, chars, colors, num_chars, num_colors);
            /* loop over ASCII scale factor */
            for (int k = 0; k < ASCII_SCALE; k++) {
                output[output_index++] = ascii_char;   /* add ASCII character to output */
            }
        }
        output[output_index++] = '\n';   /* add newline to end of row */
    }
    output[output_index] = '\0';   /* add null terminator to end of output */
}