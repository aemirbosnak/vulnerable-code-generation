//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to count words in a line
int count_words(const char *line) {
    int state = 0; // 0 means we are outside a word, 1 means we are inside a word
    int word_count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isspace(line[i])) {
            if (state == 1) {
                state = 0; // We found a space, end of a word
            }
        } else {
            if (state == 0) {
                // Found the start of a new word
                state = 1;
                word_count++;
            }
        }
    }
    return word_count;
}

// Function to read lines from a file and count total words
void count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int total_word_count = 0;
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        int words_in_line = count_words(line);
        total_word_count += words_in_line;
        printf("Line %d: %d words\n", line_number, words_in_line);
    }

    printf("\nTotal words in file: %d\n", total_word_count);
    fclose(file);
}

// Function to get user input for a filename
void get_file_from_user(char *filename, size_t size) {
    printf("Enter the filename to count words from: ");
    fgets(filename, size, stdin);
    // Remove newline character if present
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
}

// Main function to drive program
int main(int argc, char *argv[]) {
    char filename[256];

    if (argc > 1) {
        // If filename is provided as a command-line argument
        strncpy(filename, argv[1], sizeof(filename));
        filename[sizeof(filename) - 1] = '\0'; // Ensure null termination
    } else {
        // Prompt user for the filename instead
        get_file_from_user(filename, sizeof(filename));
    }

    count_words_in_file(filename);
    return 0;
}