//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_filename[100] = "";
    char output_filename[100] = "";
    char line[MAX_LINE_LENGTH] = "";
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    // Get input filename from user
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get output filename from user
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file line by line and write to output file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;
        character_count += strlen(line);
        word_count += count_words(line);

        // Write line to output file
        fprintf(output_file, "%s", line);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Print statistics
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", character_count);
    printf("Word count: %d\n", word_count);

    return 0;
}

// Function to count words in a line
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " \t\n\r\f\v");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }

    return count;
}