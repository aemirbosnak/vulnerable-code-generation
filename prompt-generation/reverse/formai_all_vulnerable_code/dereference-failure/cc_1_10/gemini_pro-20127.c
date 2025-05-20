//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Create a hash table to store the dictionary words
struct HashTable {
    char *words[MAX_WORDS];
    int size;
};

// Create a new hash table
struct HashTable* createHashTable() {
    struct HashTable* table = malloc(sizeof(struct HashTable));
    table->size = 0;
    return table;
}

// Insert a word into the hash table
void insertWord(struct HashTable* table, char *word) {
    int index = hashFunction(word);
    while (table->words[index] != NULL) {
        index = (index + 1) % MAX_WORDS;
    }
    table->words[index] = strdup(word);
    table->size++;
}

// Check if a word is in the hash table
int isWordInTable(struct HashTable* table, char *word) {
    int index = hashFunction(word);
    while (table->words[index] != NULL) {
        if (strcmp(table->words[index], word) == 0) {
            return 1;
        }
        index = (index + 1) % MAX_WORDS;
    }
    return 0;
}

// Hash function to map words to indices in the hash table
int hashFunction(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += word[i];
    }
    return hash % MAX_WORDS;
}

// Load the dictionary into the hash table
void loadDictionary(struct HashTable* table, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        char *word = strtok(line, "\n");
        insertWord(table, word);
    }
    fclose(file);
}

// Check the spelling of a word
int checkSpelling(struct HashTable* table, char *word) {
    return isWordInTable(table, word);
}

// Get suggestions for a misspelled word
char **getSuggestions(struct HashTable* table, char *word) {
    char **suggestions = malloc(sizeof(char *) * 10);
    int numSuggestions = 0;

    // Try adding or removing one character at each position
    for (int i = 0; i < strlen(word); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            char *newWord = malloc(strlen(word) + 1);
            strcpy(newWord, word);
            newWord[i] = c;
            if (isWordInTable(table, newWord)) {
                suggestions[numSuggestions++] = newWord;
            }
        }
    }

    // Try swapping two adjacent characters
    for (int i = 0; i < strlen(word) - 1; i++) {
        char *newWord = malloc(strlen(word) + 1);
        strcpy(newWord, word);
        char temp = newWord[i];
        newWord[i] = newWord[i + 1];
        newWord[i + 1] = temp;
        if (isWordInTable(table, newWord)) {
            suggestions[numSuggestions++] = newWord;
        }
    }

    return suggestions;
}

// Print the suggestions for a misspelled word
void printSuggestions(char **suggestions, int numSuggestions) {
    printf("Suggestions:\n");
    for (int i = 0; i < numSuggestions; i++) {
        printf("%s\n", suggestions[i]);
    }
}

// Free the memory allocated for the suggestions
void freeSuggestions(char **suggestions, int numSuggestions) {
    for (int i = 0; i < numSuggestions; i++) {
        free(suggestions[i]);
    }
    free(suggestions);
}

// Main function
int main() {
    // Create a hash table to store the dictionary words
    struct HashTable* table = createHashTable();

    // Load the dictionary into the hash table
    loadDictionary(table, "dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int isCorrect = checkSpelling(table, word);

    // Print the result
    if (isCorrect) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");

        // Get suggestions for the misspelled word
        char **suggestions = getSuggestions(table, word);

        // Print the suggestions
        printSuggestions(suggestions, 10);

        // Free the memory allocated for the suggestions
        freeSuggestions(suggestions, 10);
    }

    return 0;
}