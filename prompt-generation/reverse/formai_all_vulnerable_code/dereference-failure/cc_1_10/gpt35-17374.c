//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 80
#define SPACING 3
#define MAX_GRAYSCALE 255
#define CHARSET_SIZE 10

char charset[CHARSET_SIZE+1] = "@#$%&*;:";
int charset_map[MAX_GRAYSCALE+1];

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <input_image>\n", argv[0]);
        return 0;
    }

    // open the input image file
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("error: could not open input file\n");
        return 1;
    }

    // read the input image data
    unsigned char *image_data = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_WIDTH);
    fread(image_data, sizeof(unsigned char), IMAGE_WIDTH * IMAGE_WIDTH, input_file);
    fclose(input_file);

    // determine the character to use for each grayscale level
    int step = MAX_GRAYSCALE / CHARSET_SIZE;
    for (int i = 0; i <= MAX_GRAYSCALE; i++) {
        charset_map[i] = i / step;
    }

    // convert the image to ASCII art and print it to console
    for (int y = 0; y < IMAGE_WIDTH; y += SPACING) {
        for (int x = 0; x < IMAGE_WIDTH; x += SPACING) {
            int gray_value = image_data[y * IMAGE_WIDTH + x];
            int char_index = charset_map[gray_value];
            printf("%c%c", charset[char_index], charset[char_index]);
        }
        printf("\n");
    }

    free(image_data);

    return 0;
}