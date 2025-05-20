//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a file
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Define the structure of a word list
typedef struct {
    Word words[MAX_WORDS];
    int size;
} WordList;

// Create a new word list
WordList *createWordList() {
    WordList *wordList = malloc(sizeof(WordList));
    wordList->size = 0;
    return wordList;
}

// Add a word to the word list
void addWord(WordList *wordList, char *word) {
    // Check if the word is already in the word list
    for (int i = 0; i < wordList->size; i++) {
        if (strcmp(wordList->words[i].word, word) == 0) {
            wordList->words[i].count++;
            return;
        }
    }

    // If the word is not in the word list, add it
    strcpy(wordList->words[wordList->size].word, word);
    wordList->words[wordList->size].count = 1;
    wordList->size++;
}

// Print the word list
void printWordList(WordList *wordList) {
    for (int i = 0; i < wordList->size; i++) {
        printf("%s: %d\n", wordList->words[i].word, wordList->words[i].count);
    }
}

// Free the memory allocated for the word list
void freeWordList(WordList *wordList) {
    free(wordList);
}

// Read a file and count the words in it
WordList *countWords(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Create a new word list
    WordList *wordList = createWordList();

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into words
        char *words[MAX_WORDS];
        int numWords = 0;
        char *word = strtok(line, " ");
        while (word != NULL) {
            words[numWords++] = word;
            word = strtok(NULL, " ");
        }

        // Add the words to the word list
        for (int i = 0; i < numWords; i++) {
            addWord(wordList, words[i]);
        }
    }

    // Close the file
    fclose(file);

    // Return the word list
    return wordList;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the file and count the words in it
    WordList *wordList = countWords(argv[1]);

    // Print the word list
    printWordList(wordList);

    // Free the memory allocated for the word list
    freeWordList(wordList);

    return 0;
}