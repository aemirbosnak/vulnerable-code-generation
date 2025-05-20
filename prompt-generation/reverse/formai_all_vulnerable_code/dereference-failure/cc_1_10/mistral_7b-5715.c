//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITERS " \t\n\r.,;:!?(){}[]"

bool is_delimiter(char c) {
    char *delimiters = WORD_DELIMITERS;
    size_t i;

    for (i = 0; delimiters[i]; ++i) {
        if (c == delimiters[i]) {
            return true;
        }
    }

    return false;
}

size_t word_count(const char *line) {
    size_t word_count = 0;
    size_t length = strlen(line);
    bool in_word = false;

    for (size_t i = 0; i < length; ++i) {
        if (is_delimiter(line[i])) {
            if (in_word) {
                ++word_count;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }

    if (in_word) {
        ++word_count;
    }

    return word_count;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
    size_t line_length;
    size_t total_word_count = 0;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        free(line);
        return 1;
    }

    while (getline(&line, &line_length, file) != -1) {
        size_t words_in_line = word_count(line);
        total_word_count += words_in_line;
        free(line); // free the line memory after usage
    }

    fclose(file);
    free(line);

    printf("Total word count: %zu\n", total_word_count);

    return 0;
}