//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50

void print_ascii_art(char* ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (ascii_art[i * WIDTH + j] == '1') {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE* input_file;
    char* ascii_art = NULL;
    int image_size = 0;

    // Open the input file
    input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the image data into memory
    fseek(input_file, 0, SEEK_END);
    image_size = ftell(input_file);
    rewind(input_file);
    ascii_art = malloc(image_size);
    fread(ascii_art, image_size, 1, input_file);

    // Convert the image data to ASCII art
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int pixel_value = ascii_art[i * WIDTH + j];
            if (pixel_value < 128) {
                ascii_art[i * WIDTH + j] = '1';
            } else {
                ascii_art[i * WIDTH + j] = '0';
            }
        }
    }

    // Print the ASCII art
    print_ascii_art(ascii_art);

    // Free memory and close the input file
    free(ascii_art);
    fclose(input_file);

    return 0;
}