//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count_words_lines_chars(FILE *file, long *word_count, long *line_count, long *char_count) {
    int ch, in_word = 0;

    *word_count = *line_count = *char_count = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*char_count)++;
        
        if (ch == '\n') {
            (*line_count)++;
        }

        if (isspace(ch)) {
            if (in_word) {
                in_word = 0; // we are now out of a word
            }
        } else {
            if (!in_word) {
                in_word = 1; // we are entering a new word
                (*word_count)++;
            }
        }
    }

    // If the file doesn't end with a newline, we need to account for the last line
    if (*char_count > 0 && (*char_count != *line_count * (ftell(file) / *line_count))) {
        (*line_count)++;
    }
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <filename>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1; // Exit with error code if the required argument is not provided.
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1; // Return error if file cannot be opened
    }

    long word_count, line_count, char_count;
    count_words_lines_chars(file, &word_count, &line_count, &char_count);
    fclose(file);

    printf("Lines: %ld\n", line_count);
    printf("Words: %ld\n", word_count);
    printf("Characters: %ld\n", char_count);

    return 0; // Return success code on completion
}