//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

char ascii_map[] = {'.', ',', '+', '*', 'o', 'x', 'O', '#', '%', '&', '@'};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");

    if (input_file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    unsigned char image[HEIGHT][WIDTH];
    size_t bytes_read = fread(image, sizeof(unsigned char), WIDTH*HEIGHT, input_file);

    if (bytes_read != WIDTH*HEIGHT) {
        printf("Could not read file: %s\n", argv[1]);
        return 1;
    }

    fclose(input_file);

    char ascii_image[HEIGHT][WIDTH];
    size_t ascii_map_len = strlen(ascii_map);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int intensity = image[i][j]/(256/ascii_map_len);
            ascii_image[i][j] = ascii_map[intensity];
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}