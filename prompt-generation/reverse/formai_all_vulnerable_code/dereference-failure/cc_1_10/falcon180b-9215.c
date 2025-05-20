//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_WORD 100
#define MAX_ERR 100

void print_error(char *message) {
    printf("Error: %s\n", message);
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char word[MAX_WORD];
    char *words[MAX_WORD];
    int word_count = 0;
    int line_count = 0;
    FILE *input_file;
    FILE *output_file;
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";
    char *delimiters = " \t\n\r\f\v";

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        print_error("Error opening input file");
        exit(1);
    }

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        print_error("Error opening output file");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE, input_file)!= NULL) {
        // Count lines
        line_count++;

        // Split line into words
        word_count = 0;
        char *token = strtok(line, delimiters);
        while (token!= NULL) {
            strcpy(word, token);
            words[word_count] = word;
            word_count++;
            token = strtok(NULL, delimiters);
        }

        // Write words to output file
        for (int i = 0; i < word_count; i++) {
            fprintf(output_file, "%s\n", words[i]);
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Successfully processed %d lines and %d words\n", line_count, word_count);

    return 0;
}