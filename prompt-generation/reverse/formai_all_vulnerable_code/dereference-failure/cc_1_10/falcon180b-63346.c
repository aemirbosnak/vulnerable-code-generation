//Falcon-180B DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 256

void handle_error(const char* message) {
    fprintf(stderr, "ERROR: %s\n", message);
    exit(1);
}

char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        handle_error("Out of memory");
    }

    size_t length = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF && ch!= '\n') {
        if (length >= MAX_LINE_LENGTH) {
            handle_error("Line too long");
        }
        line[length++] = ch;
    }

    if (ferror(file)) {
        handle_error("Error reading line");
    }

    line[length] = '\0';
    return line;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        handle_error("Incorrect number of arguments");
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        handle_error("Could not open input file");
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        handle_error("Could not open output file");
    }

    char* line;
    while ((line = read_line(input_file))!= NULL) {
        if (fputs(line, output_file) == EOF) {
            handle_error("Error writing to output file");
        }
    }

    if (ferror(input_file)) {
        handle_error("Error reading input file");
    }

    if (fclose(input_file)!= 0) {
        handle_error("Error closing input file");
    }

    if (fclose(output_file)!= 0) {
        handle_error("Error closing output file");
    }

    return 0;
}