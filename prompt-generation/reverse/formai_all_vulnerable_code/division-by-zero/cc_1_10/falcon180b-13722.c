//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char filename[100], ch;
    int count = 0, i, j;
    int width, height;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read input file and count the number of characters
    while ((ch = fgetc(input_file))!= EOF) {
        if (isprint(ch)) {
            count++;
        }
    }

    // Calculate the width and height of the ASCII art
    width = count / 2;
    height = count / width;

    // Open output file
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write ASCII art to output file
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if ((i * width + j) < count) {
                fprintf(output_file, "%c", tolower(argv[1][i * width + j]));
            } else {
                fprintf(output_file, " ");
            }
        }
        fprintf(output_file, "\n");
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}