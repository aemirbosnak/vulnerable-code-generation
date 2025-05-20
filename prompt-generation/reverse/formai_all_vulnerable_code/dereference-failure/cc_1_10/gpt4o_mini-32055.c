//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_FILE "dictionary.txt"

char *dictionary[MAX_WORDS];
int word_count = 0;

// Function to load the dictionary file
int load_dictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        perror("Could not open dictionary file");
        return 0;
    }

    while (fgets(dictionary[word_count], MAX_WORD_LENGTH, file)) {
        dictionary[word_count][strcspn(dictionary[word_count], "\n")] = 0; // Remove newline
        word_count++;
    }
    fclose(file);
    return 1;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcasecmp(dictionary[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to suggest corrections for a misspelled word
void suggest_corrections(const char *word) {
    printf("Did you mean:\n");
    for (int i = 0; i < word_count; i++) {
        if (strlen(dictionary[i]) == strlen(word)) { // Same length
            int diff_count = 0;
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] != dictionary[i][j]) {
                    diff_count++;
                }
            }
            if (diff_count == 1) { // Only one character differs
                printf(" - %s\n", dictionary[i]);
            }
        }
    }
}

// Main function
int main() {
    char input[MAX_WORD_LENGTH];

    // Load the dictionary
    if (!load_dictionary()) {
        return 1;
    }

    printf("Welcome to the minimalist spell checker!\n");
    printf("Enter a word to check (type 'exit' to quit): \n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        // Check for exit condition
        if (strcasecmp(input, "exit") == 0) {
            break;
        }

        // Check spelling
        if (is_word_in_dictionary(input)) {
            printf("'%s' is spelled correctly.\n", input);
        } else {
            printf("'%s' is misspelled.\n", input);
            suggest_corrections(input);
        }
    }
    
    // Cleanup
    for (int i = 0; i < word_count; i++) {
        free(dictionary[i]);
    }
    printf("Exiting spell checker. Goodbye!\n");
    return 0;
}