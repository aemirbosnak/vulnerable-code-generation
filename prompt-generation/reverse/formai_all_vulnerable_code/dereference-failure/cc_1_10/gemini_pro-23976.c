//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A simple text summarizer in Dennis Ritchie style.
 *
 * Usage:
 *   ./text_summarizer <input_file> <output_file>
 *
 * The input file should contain one sentence per line.
 * The output file will contain a summary of the input file.
 */

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Open the output file.
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the input file line by line.
    char line[1024];
    while (fgets(line, sizeof(line), input_file) != NULL) {
        // Remove the newline character from the line.
        line[strlen(line) - 1] = '\0';

        // Tokenize the line.
        char *tokens[1024];
        int num_tokens = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, " ");
        }

        // Find the most important word in the line.
        int most_important_word_index = -1;
        int max_frequency = 0;
        for (int i = 0; i < num_tokens; i++) {
            int frequency = 0;
            for (int j = 0; j < num_tokens; j++) {
                if (strcmp(tokens[i], tokens[j]) == 0) {
                    frequency++;
                }
            }
            if (frequency > max_frequency) {
                max_frequency = frequency;
                most_important_word_index = i;
            }
        }

        // Add the most important word to the summary.
        fprintf(output_file, "%s ", tokens[most_important_word_index]);
    }

    // Close the input and output files.
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}