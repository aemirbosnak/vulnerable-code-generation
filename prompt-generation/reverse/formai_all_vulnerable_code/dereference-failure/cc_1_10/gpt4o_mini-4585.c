//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CAPACITY 10
#define MAX_WORD_LENGTH 100

typedef struct {
    char **words;
    int *frequencies;
    int size;
    int capacity;
} WordFrequencyCounter;

// Function to create a new word frequency counter
WordFrequencyCounter* createCounter() {
    WordFrequencyCounter *counter = malloc(sizeof(WordFrequencyCounter));
    counter->size = 0;
    counter->capacity = INITIAL_CAPACITY;
    counter->words = malloc(counter->capacity * sizeof(char*));
    counter->frequencies = malloc(counter->capacity * sizeof(int));
    return counter;
}

// Function to add a word to the counter
void addWord(WordFrequencyCounter *counter, const char *word) {
    for (int i = 0; i < counter->size; i++) {
        if (strcmp(counter->words[i], word) == 0) {
            counter->frequencies[i]++;
            return;
        }
    }
    if (counter->size >= counter->capacity) {
        counter->capacity *= 2;
        counter->words = realloc(counter->words, counter->capacity * sizeof(char*));
        counter->frequencies = realloc(counter->frequencies, counter->capacity * sizeof(int));
    }
    counter->words[counter->size] = strdup(word);
    counter->frequencies[counter->size] = 1;
    counter->size++;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

// Function to display word frequencies
void displayFrequencies(WordFrequencyCounter *counter) {
    int *indices = malloc(counter->size * sizeof(int));
    for (int i = 0; i < counter->size; i++) {
        indices[i] = i;
    }
    
    qsort(indices, counter->size, sizeof(int), compare);

    printf("Word Frequencies:\n");
    for (int i = 0; i < counter->size; i++) {
        int index = indices[i];
        printf("%s: %d\n", counter->words[index], counter->frequencies[index]);
    }

    free(indices);
}

// Function to clean up resources
void cleanup(WordFrequencyCounter *counter) {
    for (int i = 0; i < counter->size; i++) {
        free(counter->words[i]);
    }
    free(counter->words);
    free(counter->frequencies);
    free(counter);
}

// Main function
int main() {
    WordFrequencyCounter *counter = createCounter();
    char buffer[MAX_WORD_LENGTH];
    printf("Enter text (end with Ctrl+D):\n");

    while (scanf("%99s", buffer) == 1) {
        // Convert to lowercase and remove punctuation
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
            if (ispunct(buffer[i])) {
                buffer[i] = '\0'; // Remove punctuation
                break;
            }
        }
        addWord(counter, buffer);
    }

    displayFrequencies(counter);
    cleanup(counter);
    
    return 0;
}