//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25

void print_ascii_art(char* ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

void convert_image_to_ascii_art(FILE* input_file, FILE* output_file) {
    int width, height;
    char* image_data;
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);
    image_data = (char*) malloc(file_size);
    fread(image_data, 1, file_size, input_file);
    fclose(input_file);

    int ascii_art_index = 0;
    for (int i = 0; i < file_size; ++i) {
        int grayscale_value = image_data[i];
        if (grayscale_value < 128) {
            fprintf(output_file, " ");
        } else {
            fprintf(output_file, "X");
        }
        if (++ascii_art_index == WIDTH) {
            fprintf(output_file, "\n");
            ascii_art_index = 0;
        }
    }

    free(image_data);
    fclose(output_file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    convert_image_to_ascii_art(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}