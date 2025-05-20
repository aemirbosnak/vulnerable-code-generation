//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

void generate_ascii_art(FILE *input_file, FILE *output_file) {
    char input_line[MAX_LINE_LENGTH];
    char *ascii_art_line = NULL;
    size_t ascii_art_line_size = 0;
    int ascii_art_line_index = 0;

    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        ascii_art_line_size = strlen(input_line) + 1;
        ascii_art_line = realloc(ascii_art_line, ascii_art_line_size);
        if (ascii_art_line == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for ASCII art line.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(ascii_art_line + ascii_art_line_index, input_line);
        ascii_art_line_index += strlen(input_line);
    }

    ascii_art_line[ascii_art_line_index] = '\0';
    fprintf(output_file, "%s", ascii_art_line);

    free(ascii_art_line);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        fclose(input_file);
        return 1;
    }

    generate_ascii_art(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}