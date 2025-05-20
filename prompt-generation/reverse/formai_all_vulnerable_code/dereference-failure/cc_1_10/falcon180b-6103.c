//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line of text from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line of text to a file
void write_line(FILE* file, char* line) {
    if (fputs(line, file) == EOF) {
        printf("Error writing file.\n");
        exit(1);
    }
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count++;
    }
    return count;
}

// Function to replace a word in a line of text
char* replace_word(char* line, char* old_word, char* new_word) {
    char* start = strstr(line, old_word);
    if (start == NULL) {
        return line;
    }
    char* end = start + strlen(old_word);
    char* result = malloc(end - start + strlen(new_word) + 1);
    memcpy(result, line, start - line);
    memcpy(result + (start - line), new_word, strlen(new_word));
    memcpy(result + (start - line) + strlen(new_word), end, strlen(end));
    return result;
}

int main() {
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the output file
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Count the number of lines in the input file
    int num_lines = count_lines(input_file);

    // Loop through each line in the input file
    char* line;
    for (int i = 0; i < num_lines; i++) {
        line = read_line(input_file);

        // Replace a word in the line of text
        char* old_word = "apple";
        char* new_word = "orange";
        line = replace_word(line, old_word, new_word);

        // Write the modified line to the output file
        write_line(output_file, line);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}