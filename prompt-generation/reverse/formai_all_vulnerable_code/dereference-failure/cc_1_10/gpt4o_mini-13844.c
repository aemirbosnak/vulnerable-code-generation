//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int count_words(const char *text) {
    int state = 0; // 0 is outside a word, 1 is inside a word
    int word_count = 0;

    while (*text) {
        if (isspace(*text)) {
            state = 0; // We found a space, indicate outside a word
        } else if (state == 0) {
            state = 1; // We found a non-space character, indicate inside a word
            word_count++;
        }
        text++;
    }
    return word_count;
}

// Function to read text from a file and return it as a string
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);
    if (!content) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0'; // Null-terminate the string

    fclose(file);
    return content;
}

// Function to count characters, lines, and words in a given text
void count_text_metrics(const char *text, int *lines, int *characters, int *words) {
    *lines = 0;
    *characters = 0;
    *words = 0;

    while (*text) {
        if (*text == '\n') {
            (*lines)++;
        }
        (*characters)++;
        text++;
    }

    // Add 1 to lines for the last line if it doesn't end with a newline
    if (*(text - 1) != '\n') {
        (*lines)++;
    }

    // Count words in the text
    *words = count_words(text - *characters);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Welcome to the Peaceful C Word Count Tool!\n");
        printf("Usage: %s <filename>\n", argv[0]);
        printf("Please provide a text file to count words, lines, and characters.\n");
        return 1;
    }

    const char *filename = argv[1];
    char *text_content = read_file(filename);
    
    int lines, words, characters;
    count_text_metrics(text_content, &lines, &characters, &words);

    printf("Peaceful Analysis of '%s':\n", filename);
    printf("Lines:       %d\n", lines);
    printf("Words:       %d\n", words);
    printf("Characters:  %d\n", characters);

    free(text_content); // Remember to free allocated memory
    printf("Thank you for using the C Word Count Tool!\n");
    return 0;
}