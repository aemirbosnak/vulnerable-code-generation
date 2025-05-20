//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading line from file\n");
        exit(1);
    }
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to reverse the order of lines in a file
void reverse_file(FILE* input_file, FILE* output_file) {
    char* line;
    while ((line = read_line(input_file))!= NULL) {
        write_line(output_file, line);
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file '%s'\n", argv[1]);
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file '%s'\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    reverse_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}