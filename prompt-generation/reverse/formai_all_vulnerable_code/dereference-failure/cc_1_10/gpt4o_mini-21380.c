//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 50000

// Structure to hold dictionary words
typedef struct {
    char** words;
    size_t size;
} Dictionary;

// Function to create a dictionary from a file
Dictionary* load_dictionary(const char* dictionary_file) {
    Dictionary* dict = malloc(sizeof(Dictionary));
    dict->words = malloc(DICTIONARY_SIZE * sizeof(char*));
    dict->size = 0;

    FILE* file = fopen(dictionary_file, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        free(dict->words);
        free(dict);
        return NULL;
    }

    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        dict->words[dict->size] = strdup(buffer);
        dict->size++;
    }

    fclose(file);
    return dict;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const Dictionary* dict, const char* word) {
    for (size_t i = 0; i < dict->size; i++) {
        if (strcasecmp(dict->words[i], word) == 0) {
            return 1; // Word is found
        }
    }
    return 0; // Word not found
}

// Function to check for spelling in the input text
void check_spelling(Dictionary* dict, const char* text_file) {
    FILE* file = fopen(text_file, "r");
    if (!file) {
        perror("Failed to open text file");
        return;
    }

    char buffer[MAX_WORD_LENGTH];
    printf("Spelling check results:\n");
    while (fscanf(file, "%s", buffer) != EOF) {
        // Clean the word from punctuation
        int start = 0, end = strlen(buffer) - 1;

        while (!isalpha(buffer[start]) && start <= end) start++;
        while (!isalpha(buffer[end]) && end >= start) end--;
        
        if (start <= end) {
            buffer[end + 1] = '\0'; // Null-terminate the cleaned word
            if (!is_word_in_dictionary(dict, buffer)) {
                printf("Misspelled word: %s\n", buffer);
            }
        }
    }

    fclose(file);
}

// Function to free the dictionary memory
void free_dictionary(Dictionary* dict) {
    for (size_t i = 0; i < dict->size; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Dictionary* dict = load_dictionary(argv[1]);
    if (!dict) {
        return EXIT_FAILURE;
    }

    check_spelling(dict, argv[2]);

    free_dictionary(dict);
    return EXIT_SUCCESS;
}