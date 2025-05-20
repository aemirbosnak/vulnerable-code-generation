//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET_SIZE 58

// The character set used to represent different shades of grey in the ASCII art
char char_set[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void generate_ascii_art(unsigned char* image_data, char* ascii_art) {
    int x, y, value;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            value = image_data[(y * WIDTH + x) * 3];
            ascii_art[y * WIDTH + x] = char_set[value / 16];
        }
        ascii_art[(y * WIDTH + WIDTH - 1)] = '\n';
    }
}

void print_ascii_art(char* ascii_art) {
    int i;
    for (i = 0; i < HEIGHT; i++) {
        printf("%s", ascii_art + i * WIDTH);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE* image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    unsigned char* image_data = malloc(image_size);
    if (image_data == NULL) {
        printf("Error allocating memory for image data.\n");
        fclose(image_file);
        return 1;
    }

    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    char* ascii_art = malloc(HEIGHT * WIDTH + 1);
    if (ascii_art == NULL) {
        printf("Error allocating memory for ASCII art.\n");
        free(image_data);
        return 1;
    }

    generate_ascii_art(image_data, ascii_art);

    print_ascii_art(ascii_art);

    free(image_data);
    free(ascii_art);

    return 0;
}