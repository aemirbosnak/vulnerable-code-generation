//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 50

// Function to read a line from the file
char* read_line(FILE* fp) {
    char* line = (char*)malloc(MAX_LINE_SIZE*sizeof(char));
    fgets(line, MAX_LINE_SIZE, fp);
    return line;
}

// Function to write a line to the file
void write_line(FILE* fp, char* line) {
    fprintf(fp, "%s", line);
}

// Function to read all lines from the file and store them in an array
char** read_all_lines(FILE* fp, int* num_lines) {
    char* line;
    char** lines = (char**)malloc((*num_lines)*sizeof(char*));
    int i = 0;
    while ((line = read_line(fp))!= NULL) {
        lines[i] = line;
        i++;
        (*num_lines)++;
    }
    return lines;
}

// Function to write all lines to the file
void write_all_lines(FILE* fp, char** lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        write_line(fp, lines[i]);
    }
}

// Function to sort the lines in alphabetical order
void sort_lines(char** lines, int num_lines) {
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char* temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read all lines from the input file
    int num_lines = 0;
    char** lines = read_all_lines(input_file, &num_lines);

    // Sort the lines in alphabetical order
    sort_lines(lines, num_lines);

    // Open the output file
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write all lines to the output file
    write_all_lines(output_file, lines, num_lines);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}