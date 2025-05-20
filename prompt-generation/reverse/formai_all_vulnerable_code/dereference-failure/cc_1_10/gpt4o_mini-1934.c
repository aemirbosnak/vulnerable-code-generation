//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_BUFFER_SIZE 1024

void print_usage(const char *prog_name) {
    printf("Usage: %s <filename>\n", prog_name);
    printf("Counts the number of words, lines, and characters in the specified text file.\n");
}

int is_word_char(char c) {
    return isalnum(c) || c == '\'' || c == '-'; // Handle alphanumeric, apostrophe, and hyphen
}

void count_words_lines_chars(const char *filename, int *word_count, int *line_count, int *char_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    int in_word = 0;

    *word_count = *line_count = *char_count = 0;

    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        (*line_count)++;
        for (int i = 0; buffer[i] != '\0'; i++) {
            (*char_count)++;
            if (is_word_char(buffer[i])) {
                if (!in_word) {
                    in_word = 1; // We are entering a word
                    (*word_count)++;
                }
            } else {
                in_word = 0; // We are leaving a word
            }
        }
    }

    fclose(file);
}

void write_results(const char *filename, int word_count, int line_count, int char_count) {
    printf("File: %s\n", filename);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);
    printf("Characters: %d\n", char_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    if (strlen(filename) > MAX_FILENAME_LENGTH) {
        fprintf(stderr, "Error: filename is too long (max %d characters).\n", MAX_FILENAME_LENGTH);
        return EXIT_FAILURE;
    }

    int word_count, line_count, char_count;
    count_words_lines_chars(filename, &word_count, &line_count, &char_count);
    write_results(filename, word_count, line_count, char_count);

    return EXIT_SUCCESS;
}