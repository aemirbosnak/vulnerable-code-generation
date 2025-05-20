//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET_SIZE 94

char char_set[] = "!\"#$%&'()*+,-./0123456789:;<=>? @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void print_char_set(void) {
    printf("Char set:\n");
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        printf("%c", char_set[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fread(buffer, file_size, 1, input_file);
    fclose(input_file);

    int x = 0;
    int y = 0;

    for (int i = 0; i < file_size; i += 3) {
        int r = buffer[i] / 8;
        int g = buffer[i + 1] / 8;
        int b = buffer[i + 2] / 8;

        int index = (r * 5 + g * 3 + b) % CHAR_SET_SIZE;

        if (x == WIDTH) {
            x = 0;
            y++;
        }

        fprintf(output_file, "%c", char_set[index]);
        x++;
    }

    fclose(output_file);

    printf("Conversion completed.\n");

    return 0;
}