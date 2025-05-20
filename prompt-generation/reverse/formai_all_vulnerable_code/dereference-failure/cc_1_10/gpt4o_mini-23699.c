//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from the file
void extract_metadata(const char *filename, const char *search_word) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0, word_count = 0, char_count = 0;
    int search_word_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_count++;
        char_count += strlen(line);

        // Tokenize the line to count words
        char *token = strtok(line, " \n");
        while (token != NULL) {
            word_count++;
            // Check for the search word
            if (strcmp(token, search_word) == 0) {
                search_word_count++;
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);

    // Display the metadata
    printf("Metadata for file: %s\n", filename);
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of characters: %d\n", char_count);
    printf("Occurrences of the word '%s': %d\n", search_word, search_word_count);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <word to search>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *search_word = argv[2];

    // Extract metadata from the given file
    extract_metadata(filename, search_word);

    return EXIT_SUCCESS;
}