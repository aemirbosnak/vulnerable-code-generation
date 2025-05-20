//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define initial capacity as 10 words
#define INITIAL_CAPACITY 10

// Define a structure for a word with its frequency
typedef struct {
    char *word;
    int freq;
} Word;

// Define a structure for a dynamic array of words
typedef struct {
    Word *words;
    int size;
    int capacity;
} WordArray;

// Function to initialize a word array
void initWordArray(WordArray *wordArray) {
    wordArray->words = malloc(sizeof(Word) * INITIAL_CAPACITY);
    wordArray->size = 0;
    wordArray->capacity = INITIAL_CAPACITY;
}

// Function to add a new word to the word array
void addWord(WordArray *wordArray, char *word) {
    // Check if the word already exists in the array
    for (int i = 0; i < wordArray->size; i++) {
        if (strcmp(wordArray->words[i].word, word) == 0) {
            wordArray->words[i].freq++;
            return;
        }
    }
    // If the word does not exist in the array, add it to the end
    if (wordArray->size == wordArray->capacity) {
        // If the array is full, double its capacity
        wordArray->capacity *= 2;
        wordArray->words = realloc(wordArray->words, sizeof(Word) * wordArray->capacity);
    }
    Word newWord = { word, 1 };
    wordArray->words[wordArray->size] = newWord;
    wordArray->size++;
}

// Function to sort the word array by frequency in descending order
void sortWordArray(WordArray *wordArray) {
    // Bubble sort algorithm
    for (int i = 0; i < wordArray->size - 1; i++) {
        for (int j = 0; j < wordArray->size - i - 1; j++) {
            if (wordArray->words[j].freq < wordArray->words[j+1].freq) {
                Word temp = wordArray->words[j];
                wordArray->words[j] = wordArray->words[j+1];
                wordArray->words[j+1] = temp;
            }
        }
    }
}

int main(void) {
    // Prompt the user for input
    printf("Enter a sentence: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    // Initialize a word array
    WordArray wordArray;
    initWordArray(&wordArray);

    // Parse the sentence and add each word to the array
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // Remove any leading or trailing spaces and punctuation
        int i = 0, j = strlen(word) - 1;
        while (isspace(word[i])) i++;
        while (ispunct(word[j])) j--;
        word[j+1] = '\0';
        // Convert to lowercase
        for (int k = 0; k <= j; k++) {
            word[k] = tolower(word[k]);
        }
        addWord(&wordArray, word);
        word = strtok(NULL, " ");
    }

    // Sort the word array by frequency in descending order
    sortWordArray(&wordArray);

    // Print the word count results
    printf("Word count results:\n");
    for (int i = 0; i < wordArray.size; i++) {
        printf("%s: %d\n", wordArray.words[i].word, wordArray.words[i].freq);
    }

    // Free the memory allocated for the word array
    for (int i = 0; i < wordArray.size; i++) {
        free(wordArray.words[i].word);
    }
    free(wordArray.words);

    return 0;
}