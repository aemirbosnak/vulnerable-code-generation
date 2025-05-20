//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold the dictionary words
typedef struct Word {
    char word[50];
    struct Word *next;
} Word;

// Function declarations
void loadDictionary(Word **dict, const char *filename);
void checkSpelling(Word *dict, const char *input);
int isWordInDictionary(Word *dict, const char *word);
void freeDictionary(Word *dict);
void toLowerCase(char *str);

#define MAX_WORD_LENGTH 50
#define BUFFER_SIZE 1024

// Main function
int main() {
    Word *dictionary = NULL;
    char input[BUFFER_SIZE];

    // Load the dictionary from a file
    loadDictionary(&dictionary, "dictionary.txt");
    
    // User instructions
    printf("=== Retro Spell Checker ===\n");
    printf("Enter words to check spelling ('exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Check spelling
        checkSpelling(dictionary, input);
    }

    // Cleanup
    freeDictionary(dictionary);
    printf("Thank you for using the Retro Spell Checker!\n");
    return 0;
}

// Load words from the dictionary file into a linked list
void loadDictionary(Word **dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    char tempWord[MAX_WORD_LENGTH];
    while (fgets(tempWord, sizeof(tempWord), file)) {
        tempWord[strcspn(tempWord, "\n")] = 0; // Remove newline character
        Word *newWord = malloc(sizeof(Word));
        strcpy(newWord->word, tempWord);
        newWord->next = *dict;
        *dict = newWord;
    }

    fclose(file);
}

// Check the spelling of the input word
void checkSpelling(Word *dict, const char *input) {
    char word[MAX_WORD_LENGTH];
    strcpy(word, input);
    toLowerCase(word);

    if (isWordInDictionary(dict, word)) {
        printf("'%s' is spelled correctly!\n", input);
    } else {
        printf("'%s' is misspelled!\n", input);
    }
}

// Check if a word is in the dictionary
int isWordInDictionary(Word *dict, const char *word) {
    while (dict) {
        if (strcmp(dict->word, word) == 0) {
            return 1; // Word found
        }
        dict = dict->next;
    }
    return 0; // Word not found
}

// Free the memory allocated for the dictionary
void freeDictionary(Word *dict) {
    Word *temp;
    while (dict) {
        temp = dict;
        dict = dict->next;
        free(temp);
    }
}

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char) tolower(str[i]);
    }
}