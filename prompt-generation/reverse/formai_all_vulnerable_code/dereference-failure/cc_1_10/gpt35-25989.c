//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int get_gray_scale_value(int r, int g, int b) {
    return (r + g + b) / 3;
}

int get_ascii_char_index(int gray_scale_value) {
    float step = 255.0 / (sizeof(ascii_chars) - 1);
    return (int)(gray_scale_value / step);
}

void convert_image_to_ascii(char* image_path, int width, int height) {
    FILE* image_file = fopen(image_path, "rb");
    if (!image_file) {
        printf("Error: cannot open file \n");
        exit(EXIT_FAILURE);
    }

    unsigned char image_data[height][width][3];
    if (fread(image_data, sizeof(unsigned char), width * height * 3, image_file) != width * height * 3) {
        printf("Error: cannot read pixel data \n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray_scale_value = get_gray_scale_value(image_data[i][j][0], image_data[i][j][1], image_data[i][j][2]);
            int ascii_char_index = get_ascii_char_index(gray_scale_value);

            printf("%c", ascii_chars[ascii_char_index]);
        }
        printf("\n");
    }

    fclose(image_file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s image_file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* image_path = argv[1];
    convert_image_to_ascii(image_path, MAX_WIDTH, MAX_HEIGHT);

    return 0;
}