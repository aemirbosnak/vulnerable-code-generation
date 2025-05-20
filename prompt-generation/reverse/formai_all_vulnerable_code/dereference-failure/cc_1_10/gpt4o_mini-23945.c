//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_BUFFER_SIZE 1024

// Function to determine if a character is a word delimiter
int is_delimiter(char ch) {
    return isspace(ch) || ispunct(ch);
}

// Function to count words in a given file
int count_words_in_file(const char *filename) {
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];
    int word_count = 0;
    int in_word = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (is_delimiter(buffer[i])) {
                if (in_word) {
                    in_word = 0; // We've hit a delimiter after a word
                }
            } else {
                if (!in_word) {
                    in_word = 1; // We've hit a non-delimiter after a delimiter
                    word_count++;
                }
            }
        }
    }

    fclose(file);
    return word_count;
}

// Function to display the word count result
void display_word_count(const char *filename, int count) {
    if (count >= 0) {
        printf("The file '%s' contains %d word(s).\n", filename, count);
    } else {
        printf("Could not count words in the file '%s'.\n", filename);
    }
}

// Main function to drive the word counting program
int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_SIZE];
    int word_count;

    // Check if filename is provided as an argument
    if (argc > 1) {
        strncpy(filename, argv[1], MAX_FILENAME_SIZE - 1);
        filename[MAX_FILENAME_SIZE - 1] = '\0'; // Ensure null-termination
    } else {
        printf("Please enter a filename: ");
        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            fprintf(stderr, "Error reading filename.\n");
            return 1;
        }
        // Remove newline character if present
        filename[strcspn(filename, "\n")] = '\0';
    }

    // Count words in the specified file
    word_count = count_words_in_file(filename);

    // Display the result
    display_word_count(filename, word_count);

    return 0;
}