//Falcon-180B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1000

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    fgets(line, MAX_LINE_SIZE, file);
    line[strcspn(line, "\n")] = '\0'; // Remove newline character
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s\n", line);
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char* line = read_line(file);
    while (line!= NULL) {
        count++;
        free(line);
        line = read_line(file);
    }
    return count;
}

// Function to reverse the order of lines in a file
void reverse_lines(FILE* input_file, FILE* output_file) {
    char* line = read_line(input_file);
    while (line!= NULL) {
        write_line(output_file, line);
        free(line);
        line = read_line(input_file);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int line_count = count_lines(input_file);
    printf("Number of lines: %d\n", line_count);

    reverse_lines(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}