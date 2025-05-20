//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image_file> <output_ascii_art_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file '%s'.\n", argv[1]);
        return 2;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file '%s'.\n", argv[2]);
        fclose(input_file);
        return 3;
    }

    unsigned char header[54];
    fread(header, 1, 54, input_file);

    int width, height;
    if (header[18] & 0x80) {
        width = *(int *)&header[18];
        height = *(int *)&header[22];
    } else {
        width = *(int *)&header[22];
        height = *(int *)&header[18];
    }

    unsigned char *data = malloc(width * height);
    fread(data, 1, width * height, input_file);

    int max_value = 0;
    for (int i = 0; i < width * height; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = data[y * width + x];
            int ascii_character = value * (MAX_WIDTH - 32) / max_value + 32;

            fprintf(output_file, "%c", ascii_character);
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}