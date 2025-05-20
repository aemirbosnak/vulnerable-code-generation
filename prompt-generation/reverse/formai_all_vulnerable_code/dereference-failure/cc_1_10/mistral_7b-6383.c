//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define WORDS_TO_REMOVE_COUNT 5

char *words_to_remove[WORDS_TO_REMOVE_COUNT] = {
    "apology",
    "sorry",
    "excuse",
    "regret",
    "mistake"
};

bool should_remove_word(char *line, char *word) {
    size_t line_length = strlen(line);
    size_t word_length = strlen(word);
    size_t i;

    for (i = 0; i < line_length - word_length; ++i) {
        if (strncmp(&line[i], word, word_length) == 0) {
            return true;
        }
    }

    return false;
}

void process_line(char *line, FILE *input_file, FILE *output_file) {
    char *token;
    bool remove_line = false;

    token = strtok(line, " ");

    while (token != NULL) {
        if (should_remove_word(line, token)) {
            remove_line = true;
            break;
        }

        token = strtok(NULL, " ");
    }

    if (!remove_line) {
        fprintf(output_file, "%s\n", line);
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        line_number++;
        process_line(line, input_file, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processed %d lines in the input file.\n", line_number);

    return 0;
}