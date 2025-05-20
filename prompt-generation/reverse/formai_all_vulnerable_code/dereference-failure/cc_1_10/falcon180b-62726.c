//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 //maximum width of the ASCII art
#define HEIGHT 60 //maximum height of the ASCII art

void print_ascii_art(char ascii_art[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char input_filename[100];
    char ascii_art[HEIGHT][WIDTH];
    int i, j, gray_level, max_gray_level = 0;

    if (argc!= 2) {
        printf("Usage: %s <input_image>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    input_file = fopen(input_filename, "rb");

    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    fseek(input_file, 18, SEEK_SET); //skip header
    fread(ascii_art, sizeof(char), WIDTH * HEIGHT, input_file);

    fclose(input_file);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            gray_level = ascii_art[i][j] * (1.0 / 255);
            if (gray_level > max_gray_level) {
                max_gray_level = gray_level;
            }
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            gray_level = ascii_art[i][j] * (HEIGHT - 1) / max_gray_level;
            ascii_art[i][j] = (char)gray_level + 32;
        }
    }

    print_ascii_art(ascii_art);

    return 0;
}