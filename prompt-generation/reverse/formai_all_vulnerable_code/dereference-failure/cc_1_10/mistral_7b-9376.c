//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5
#define CHAR_PER_PIXEL 4

void read_image(unsigned char *image_data, int width, int height) {
    FILE *file = fopen("image.bmp", "rb");
    fseek(file, 18, SEEK_SET);
    fread(image_data, 1, 3 * width * height, file);
    fclose(file);
}

void convert_to_ascii(unsigned char *image_data, char *ascii_art, int width, int height) {
    int i, j, kernel_sum;
    char ascii_chars[CHAR_PER_PIXEL][128];

    memset(ascii_chars, 0, sizeof(ascii_chars));
    for (int i = 0; i < CHAR_PER_PIXEL; i++) {
        ascii_chars[i][0] = ' ';
        ascii_chars[i][47] = '*';
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            kernel_sum = 0;
            int x, y;

            for (x = -1; x <= 1; x++) {
                for (y = -1; y <= 1; y++) {
                    if (x == -1 || x == 1 || y == -1 || y == 1) {
                        kernel_sum += image_data[(i + y) * width + (j + x)];
                    }
                }
            }

            int grayscale = kernel_sum / 9;
            int ascii_index = grayscale * (CHAR_PER_PIXEL - 1);
            for (int k = 0; k < CHAR_PER_PIXEL; k++) {
                ascii_art[(i * width + j) * CHAR_PER_PIXEL + k] = ascii_chars[k][ascii_index];
            }
        }
    }
}

void print_ascii_art(char *ascii_art, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < CHAR_PER_PIXEL; k++) {
                putchar(ascii_art[(i * width + j) * CHAR_PER_PIXEL + k]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

int main() {
    unsigned char image_data[3 * WIDTH * HEIGHT];
    char ascii_art[WIDTH * HEIGHT * CHAR_PER_PIXEL];

    read_image(image_data, WIDTH, HEIGHT);
    convert_to_ascii(image_data, ascii_art, WIDTH, HEIGHT);
    print_ascii_art(ascii_art, WIDTH, HEIGHT);

    return 0;
}