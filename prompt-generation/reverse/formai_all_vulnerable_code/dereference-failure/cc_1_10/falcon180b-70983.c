//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, const char* line) {
    fprintf(file, "%s", line);
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char* line = read_line(file);
    while (line!= NULL) {
        count++;
        line = read_line(file);
    }
    return count;
}

// Function to reverse the order of lines in a file
void reverse_lines(FILE* input_file, FILE* output_file) {
    char* line = read_line(input_file);
    while (line!= NULL) {
        write_line(output_file, line);
        line = read_line(input_file);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    int line_count = count_lines(input_file);
    printf("Number of lines in input file: %d\n", line_count);

    reverse_lines(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;
}