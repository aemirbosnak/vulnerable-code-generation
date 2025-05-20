//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_SIZE 100

typedef struct {
    char **words;
    int *counts;
    int size;
    int capacity;
} WordFreq;

// Function to create an empty WordFreq structure
WordFreq* create_word_freq() {
    WordFreq* wf = (WordFreq*)malloc(sizeof(WordFreq));
    wf->words = (char**)malloc(INITIAL_SIZE * sizeof(char*));
    wf->counts = (int*)malloc(INITIAL_SIZE * sizeof(int));
    wf->size = 0;
    wf->capacity = INITIAL_SIZE;
    return wf;
}

// Function to resize the arrays if needed
void resize_word_freq(WordFreq* wf) {
    wf->capacity *= 2;
    wf->words = (char**)realloc(wf->words, wf->capacity * sizeof(char*));
    wf->counts = (int*)realloc(wf->counts, wf->capacity * sizeof(int));
}

// Function to process and count words
void count_words(WordFreq* wf, const char* text) {
    char word[MAX_WORD_LENGTH];
    const char* p = text;
    int idx = 0;

    while (*p) {
        // Skip non-alphabetic characters
        while (*p && !isalpha(*p)) {
            p++;
        }

        // If an alphabetic character is found, read the word
        if (*p) {
            idx = 0;
            while (*p && isalpha(*p) && idx < MAX_WORD_LENGTH - 1) {
                word[idx++] = tolower(*p);
                p++;
            }
            word[idx] = '\0';  // Null-terminate the word

            // Check if the word is already in the list
            int found = 0;
            for (int i = 0; i < wf->size; i++) {
                if (strcmp(wf->words[i], word) == 0) {
                    wf->counts[i]++;
                    found = 1;
                    break;
                }
            }

            // If not found, we need to insert it
            if (!found) {
                if (wf->size == wf->capacity) {
                    resize_word_freq(wf);
                }
                wf->words[wf->size] = strdup(word);
                wf->counts[wf->size] = 1;
                wf->size++;
            }
        }
    }
}

// Function to print the word frequencies
void print_word_frequencies(const WordFreq* wf) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wf->size; i++) {
        printf("%s: %d\n", wf->words[i], wf->counts[i]);
    }
}

// Function to clean up and free the allocated memory
void free_word_freq(WordFreq* wf) {
    for (int i = 0; i < wf->size; i++) {
        free(wf->words[i]); // Free each word
    }
    free(wf->words);
    free(wf->counts);
    free(wf);
}

// Main function to run the word frequency counter
int main() {
    printf("Welcome to the Word Frequency Counter!\n");
    printf("Please enter your text (Ctrl+D to end input):\n");

    // Reading multiple lines of text from stdin
    char* input_text = NULL;
    size_t len = 0;
    ssize_t read;

    WordFreq* wf = create_word_freq();

    while ((read = getline(&input_text, &len, stdin)) != -1) {
        count_words(wf, input_text);
    }
    
    print_word_frequencies(wf);

    // Dispose the resources used
    free(input_text);
    free_word_freq(wf);

    printf("\nThank you for using the Word Frequency Counter!\n");
    return 0;
}