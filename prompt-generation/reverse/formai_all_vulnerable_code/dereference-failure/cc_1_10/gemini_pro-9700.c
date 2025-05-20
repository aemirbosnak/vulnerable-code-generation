//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Allocate memory for a new string of the given length.
char *new_string(size_t length) {
    char *string = malloc(length + 1);
    if (string == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    string[length] = '\0';
    return string;
}

// Read a word from the given file.
char *read_word(FILE *file) {
    char *word = new_string(MAX_WORD_LENGTH);
    int length = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF && !isspace(ch)) {
        if (length < MAX_WORD_LENGTH) {
            word[length++] = ch;
        }
    }
    word[length] = '\0';
    return word;
}

// Check if the given word is in the dictionary.
bool is_in_dictionary(char *word, char **dictionary, size_t dictionary_size) {
    for (size_t i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Print the given word with a suggestion if it is not in the dictionary.
void print_word(char *word, char **dictionary, size_t dictionary_size) {
    if (is_in_dictionary(word, dictionary, dictionary_size)) {
        printf("%s", word);
    } else {
        printf("%s (Did you mean \"%s\"?)", word, dictionary[0]);
    }
}

// Free the memory allocated for the given word.
void free_word(char *word) {
    free(word);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
        exit(1);
    }

    // Read the dictionary into memory.
    FILE *dictionary_file = fopen(argv[1], "r");
    if (dictionary_file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        exit(1);
    }

    size_t dictionary_size = 0;
    char **dictionary = NULL;
    while (!feof(dictionary_file)) {
        char *word = read_word(dictionary_file);
        if (strlen(word) > 0) {
            dictionary_size++;
            dictionary = realloc(dictionary, dictionary_size * sizeof(char *));
            dictionary[dictionary_size - 1] = word;
        } else {
            free_word(word);
        }
    }
    fclose(dictionary_file);

    // Read the input text and check each word for spelling errors.
    char *word;
    while ((word = read_word(stdin)) != NULL) {
        print_word(word, dictionary, dictionary_size);
        putchar(' ');
        free_word(word);
    }

    // Free the memory allocated for the dictionary.
    for (size_t i = 0; i < dictionary_size; i++) {
        free_word(dictionary[i]);
    }
    free(dictionary);

    return 0;
}