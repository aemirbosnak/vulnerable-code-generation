//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char ascii_image[MAX_HEIGHT][MAX_WIDTH];

void convert_to_ascii(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width);
int get_ascii_index(int pixel_value, int is_negative);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ascii_converter image.bmp\n");
        return 1;
    }

    char *filename = argv[1];

    FILE *input = fopen(filename, "rb");
    if (!input) {
        printf("Error opening file.\n");
        return 1;
    }

    unsigned char image_header[54];
    fread(image_header, sizeof(unsigned char), 54, input);
    int width = *(int *)&image_header[18];
    int height = *(int *)&image_header[22];
    int num_pixels = width * height;

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image is too large. Maximum size is %dx%d pixels.\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    char image[MAX_HEIGHT][MAX_WIDTH];
    unsigned char pixel_data[num_pixels * 3];
    fread(pixel_data, sizeof(unsigned char), num_pixels * 3, input);

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int red = pixel_data[(row * width + col) * 3 + 2];
            int green = pixel_data[(row * width + col) * 3 + 1];
            int blue = pixel_data[(row * width + col) * 3];
            image[row][col] = (char)get_ascii_index((red + green + blue) / 3, 1);
        }
    }

    convert_to_ascii(image, height, width);

    fclose(input);

    return 0;
}

void convert_to_ascii(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    char ascii_chars[] = "@#S%?*+:,.";
    int num_chars = strlen(ascii_chars);
    int char_value_range = 255 / num_chars;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int pixel_value = (int)image[row][col];
            int is_negative = (pixel_value < 0) ? 1 : 0;
            pixel_value = (is_negative) ? pixel_value * -1 : pixel_value;
            int ascii_index = get_ascii_index(pixel_value, is_negative);
            ascii_image[row][col] = ascii_chars[ascii_index];
            printf("%c", ascii_chars[ascii_index]);
        }
        printf("\n");
    }
}

int get_ascii_index(int pixel_value, int is_negative) {
    char ascii_chars[] = "@#S%?*+:,.";
    int num_chars = strlen(ascii_chars);
    int char_value_range = 255 / num_chars;

    if (is_negative) {
        pixel_value = 255 - pixel_value;
    }
    int ascii_index = pixel_value / char_value_range;
    if (ascii_index >= num_chars) {
        ascii_index = num_chars - 1;
    }
    return ascii_index;
}