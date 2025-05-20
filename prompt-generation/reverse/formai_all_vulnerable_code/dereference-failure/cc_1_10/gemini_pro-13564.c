//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Create a hash table to store the dictionary words
struct Dictionary {
    char *words[MAX_WORDS];
    int size;
};

// Create a new dictionary
struct Dictionary *create_dictionary() {
    struct Dictionary *dict = malloc(sizeof(struct Dictionary));
    dict->size = 0;
    return dict;
}

// Add a word to the dictionary
void add_word(struct Dictionary *dict, char *word) {
    dict->words[dict->size++] = strdup(word);
}

// Load the dictionary from a file
void load_dictionary(struct Dictionary *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        char *word = strtok(line, "\n");
        add_word(dict, word);
    }

    fclose(file);
}

// Check if a word is in the dictionary
int is_in_dictionary(struct Dictionary *dict, char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1;
        }
    }

    return 0;
}

// Check the spelling of a word
void check_spelling(struct Dictionary *dict, char *word) {
    if (is_in_dictionary(dict, word)) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is spelled incorrectly\n", word);
    }
}

// Get a word from the user
char *get_word() {
    char *word = malloc(MAX_WORD_LENGTH);
    printf("Enter a word: ");
    scanf("%s", word);
    return word;
}

// Main function
int main() {
    // Create a new dictionary
    struct Dictionary *dict = create_dictionary();

    // Load the dictionary from a file
    load_dictionary(dict, "dictionary.txt");

    // Get a word from the user
    char *word = get_word();

    // Check the spelling of the word
    check_spelling(dict, word);

    // Free the memory allocated for the word
    free(word);

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i]);
    }
    free(dict);

    return 0;
}