//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024

// Function prototypes
void print_usage(const char *prog_name);
int count_words_in_line(const char *line);
void count_words_in_file(const char *filename);
void process_command_line_arguments(int argc, char *argv[], char *filename);

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    
    // Process command line arguments for the filename
    process_command_line_arguments(argc, argv, filename);
    
    // Count words in the specified file
    count_words_in_file(filename);

    return 0;
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <filename>\n", prog_name);
    printf("Counts the number of words in the specified file.\n");
}

void process_command_line_arguments(int argc, char *argv[], char *filename) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH);
    filename[MAX_FILENAME_LENGTH - 1] = '\0'; // Ensure null termination
}

int count_words_in_line(const char *line) {
    int count = 0;
    const char *ptr = line;
    int in_word = 0;

    while (*ptr) {
        if (isspace(*ptr)) {
            if (in_word) {
                in_word = 0; // End of a word
            }
        } else {
            if (!in_word) {
                in_word = 1; // Found the beginning of a word
                count++;
            }
        }
        ptr++;
    }

    return count;
}

void count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int total_word_count = 0;

    while (fgets(line, sizeof(line), file)) {
        total_word_count += count_words_in_line(line);
    }

    fclose(file);
    printf("Total word count in '%s': %d\n", filename, total_word_count);
}