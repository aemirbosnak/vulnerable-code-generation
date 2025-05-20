//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(const char *str) {
    int count = 0;
    char *temp = strdup(str); // Duplicate string for manipulation
    char *token = strtok(temp, " \n\t"); // Tokenize based on spaces, newlines, and tabs

    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n\t"); // Continue tokenizing
    }

    free(temp); // Free duplicate string
    return count;
}

// Function to check if a character is punctuation
int isPunctuation(char c) {
    return ispunct(c) && c != '\''; // Ignore apostrophes
}

// Function to count characters excluding punctuation
int countCharacters(const char *str) {
    int count = 0;
    while (*str) {
        if (!isPunctuation(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to count lines in a string
int countLines(const char *str) {
    int count = 0;
    while (*str) {
        if (*str == '\n') {
            count++;
        }
        str++;
    }
    return count + 1; // Add one to count the last line
}

// Function to analyze the text
void analyzeText(const char *text) {
    int words = countWords(text);
    int characters = countCharacters(text);
    int lines = countLines(text);

    printf("Text Analysis:\n");
    printf("Word Count: %d\n", words);
    printf("Character Count (excluding punctuation): %d\n", characters);
    printf("Line Count: %d\n", lines);
}

// Function to read text from a file
char *readTextFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *content = malloc(length + 1);
    if (content == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0'; // Null-terminate the string
    fclose(file);
    return content;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = readTextFile(argv[1]);
    if (text == NULL) {
        return EXIT_FAILURE; // Exit if reading the file failed
    }

    analyzeText(text);
    free(text); // Free the allocated memory
    return EXIT_SUCCESS;
}