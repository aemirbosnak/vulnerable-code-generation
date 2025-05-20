//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the file name and the number of lines to read
#define FILE_NAME "the_great_gatsby.txt"
#define LINE_COUNT 100

// Define a struct to hold the line data
typedef struct {
    char *line;
    size_t len;
} line_t;

// Function to read the file and allocate memory for the line array
line_t *read_file(FILE *file) {
    line_t *lines = calloc(LINE_COUNT, sizeof(line_t));
    size_t i = 0;

    // Read the file line by line
    while (fgets(lines[i].line, sizeof(lines[i].line), file) != NULL) {
        lines[i].len = strlen(lines[i].line);
        i++;
    }

    return lines;
}

// Function to print the line array
void print_lines(line_t *lines) {
    size_t i = 0;

    // Print each line, with a line break between them
    for (i = 0; i < LINE_COUNT; i++) {
        printf("%s\n", lines[i].line);
    }

    free(lines);
}

int main() {
    // Open the file in read mode
    FILE *file = fopen(FILE_NAME, "r");

    // Read the file and allocate memory for the line array
    line_t *lines = read_file(file);

    // Print the line array
    print_lines(lines);

    // Close the file
    fclose(file);

    return 0;
}