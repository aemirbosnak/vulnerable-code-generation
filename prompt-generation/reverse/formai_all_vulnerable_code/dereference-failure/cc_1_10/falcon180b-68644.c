//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_line[MAX_LINE_LENGTH];
    char *word;
    int word_count = 0;
    int line_count = 0;

    // Open input and output files
    if ((input_file = fopen(argv[1], "r")) == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    if ((output_file = fopen(argv[2], "w")) == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;

        // Remove leading and trailing whitespace from input line
        input_line[strcspn(input_line, "\n")] = '\0';
        input_line[0] = toupper(input_line[0]);

        // Count number of words in input line
        word = strtok(input_line, " ");
        while (word!= NULL) {
            word_count++;
            word = strtok(NULL, " ");
        }

        // Write modified input line to output file
        fprintf(output_file, "Line %d has %d words.\n", line_count, word_count);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}