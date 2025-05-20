//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024

// Function declarations
void shuffle_word(char *word);
void process_file(const char *input_filename, const char *output_filename);

// Main function
int main() {
    const char *input_filename = "input.txt";
    const char *output_filename = "output.txt";

    // Process the file
    process_file(input_filename, output_filename);

    printf("File processed! Check '%s' for the output.\n", output_filename);
    return 0;
}

// Function to shuffle a word by reversing its characters
void shuffle_word(char *word) {
    int n = strlen(word);
    for (int i = 0; i < n / 2; ++i) {
        char temp = word[i];
        word[i] = word[n - i - 1];
        word[n - i - 1] = temp;
    }
}

// Function to read from input file and write to output file
void process_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    // Check if the files opened successfully
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file %s for reading.\n", input_filename);
        exit(EXIT_FAILURE);
    }
    if (output_file == NULL) {
        fprintf(stderr, "Error opening file %s for writing.\n", output_filename);
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    
    // Read each line from input file
    while (fgets(line, sizeof(line), input_file)) {
        char *word = strtok(line, " \n");
        
        // Process each word in the line
        while (word != NULL) {
            // Shuffle the word
            shuffle_word(word);
            // Write the shuffled word to the output file
            fprintf(output_file, "%s ", word);
            // Get the next word
            word = strtok(NULL, " \n");
        }
        
        // Write a new line in the output file
        fprintf(output_file, "\n");
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);
}