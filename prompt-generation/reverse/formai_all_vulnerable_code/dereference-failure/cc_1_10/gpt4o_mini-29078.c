//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILENAME 255

// Function declarations
void print_usage();
void count_words_lines_chars(FILE *file, int *word_count, int *line_count, int *char_count);
void clear_counts(int *word_count, int *line_count, int *char_count);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *filename = argv[1];
    // Capture commands
    char *command = argv[2];
    int word_count = 0, line_count = 0, char_count = 0;
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    count_words_lines_chars(file, &word_count, &line_count, &char_count);
    fclose(file);
   
    // Process commands
    if (strcmp(command, "words") == 0) {
        printf("Total Words: %d\n", word_count);
    } else if (strcmp(command, "lines") == 0) {
        printf("Total Lines: %d\n", line_count);
    } else if (strcmp(command, "chars") == 0) {
        printf("Total Characters: %d\n", char_count);
    } else if (strcmp(command, "all") == 0) {
        printf("Total Words: %d\n", word_count);
        printf("Total Lines: %d\n", line_count);
        printf("Total Characters: %d\n", char_count);
    } else {
        printf("Invalid command. Use 'words', 'lines', 'chars', or 'all'.\n");
        return 1;
    }

    return 0;
}

void print_usage() {
    printf("Usage: word_count <filename> <command>\n");
    printf("Commands:\n");
    printf("  words  - Count the number of words in the file\n");
    printf("  lines  - Count the number of lines in the file\n");
    printf("  chars  - Count the number of characters in the file\n");
    printf("  all    - Display all counts\n");
}

void count_words_lines_chars(FILE *file, int *word_count, int *line_count, int *char_count) {
    char c;
    int in_word = 0;  // flag to check if we are inside a word
    while ((c = fgetc(file)) != EOF) {
        (*char_count)++; // Increment character count
        if (c == '\n') {
            (*line_count)++; // Increment line count
        }
        if (isspace(c)) {
            in_word = 0; // we're outside a word
        } else {
            if (in_word == 0) {
                (*word_count)++; // Increment word count
                in_word = 1; // we're inside a word
            }
        }
    }
    // Handle case of an empty file
    if (*line_count == 0 && *char_count > 0) {
        (*line_count)++;
    }
}

void clear_counts(int *word_count, int *line_count, int *char_count) {
    *word_count = 0;
    *line_count = 0;
    *char_count = 0;
}