//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    char* result = fgets(line, MAX_LINE_LENGTH, file);
    if (result == NULL) {
        printf("Error reading line from file\n");
        exit(1);
    }
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
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
void reverse_lines(FILE* file) {
    char* line;
    int count = count_lines(file);
    rewind(file);
    for (int i = 0; i < count; i++) {
        line = read_line(file);
        write_line(file, line);
        free(line);
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        fclose(input_file);
        return 1;
    }

    reverse_lines(input_file);
    fclose(input_file);
    fclose(output_file);

    return 0;
}