//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int main() {
    FILE *input_file = fopen(INPUT_FILE, "r");
    FILE *output_file = fopen(OUTPUT_FILE, "w");

    if (!input_file || !output_file) {
        perror("Could not open files");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, input_file)) {
        char *token = strtok(line, " ");
        int token_count = 0;

        // Process each token in the line
        while (token != NULL) {
            // Replace all occurrences of "sorry" with "awesome"
            size_t len = strlen(token);
            if (len >= 6 && strncmp(token, "sorry", len) == 0) {
                char new_token[MAX_LINE_LEN];
                strncpy(new_token, "awesome", 6);
                new_token[6] = '\0';
                strtok(line, " "); // Free the previous token
                size_t pos = strlen(line);
                strcat(line, " ");
                strcat(line, new_token);
                pos += strlen(new_token);
                memmove(line + pos, line + pos + strlen(token), strlen(line + pos + strlen(token)) - strlen(line + pos));
                line[strlen(line)] = '\0';
            }

            // Get the next token
            token = strtok(NULL, " ");
            token_count++;
        }

        // Write the modified line to the output file
        fprintf(output_file, "%s\n", line);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("Replaced all occurrences of 'sorry' with 'awesome' in the input file and saved the output to %s.\n", OUTPUT_FILE);

    return EXIT_SUCCESS;
}