//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Word frequency counter data structure
typedef struct {
    char *word;
    int count;
} WordFreq;

// Function to compare two WordFreq structs by count
int compareWordFreq(const void *a, const void *b) {
    const WordFreq *wa = (const WordFreq *)a;
    const WordFreq *wb = (const WordFreq *)b;
    return wb->count - wa->count;
}

// Function to print a WordFreq struct
void printWordFreq(const WordFreq *wf) {
    printf("%s: %d\n", wf->word, wf->count);
}

// Function to split a string into an array of words
char **splitString(const char *str, int *nwords) {
    char **words = NULL;
    *nwords = 0;

    // Allocate memory for the first word
    words = (char **)malloc(sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    // Split the string into words
    char *word = strtok(str, " ");
    while (word != NULL) {
        // Allocate memory for the next word
        words = (char **)realloc(words, (*nwords + 1) * sizeof(char *));
        if (words == NULL) {
            return NULL;
        }

        // Copy the word into the array
        words[*nwords] = strdup(word);
        if (words[*nwords] == NULL) {
            return NULL;
        }

        // Increment the number of words
        (*nwords)++;

        // Get the next word
        word = strtok(NULL, " ");
    }

    return words;
}

// Function to count the frequency of words in a string
WordFreq *countWords(const char *str, int *nwords) {
    char **words = splitString(str, nwords);
    if (words == NULL) {
        return NULL;
    }

    // Create a hash table to store the word frequencies
    WordFreq *wf = (WordFreq *)malloc(*nwords * sizeof(WordFreq));
    if (wf == NULL) {
        return NULL;
    }

    for (int i = 0; i < *nwords; i++) {
        wf[i].word = words[i];
        wf[i].count = 1;
    }

    // Sort the word frequencies by count
    qsort(wf, *nwords, sizeof(WordFreq), compareWordFreq);

    return wf;
}

// Function to print the word frequencies
void printWordFrequencies(const WordFreq *wf, int nwords) {
    for (int i = 0; i < nwords; i++) {
        printWordFreq(&wf[i]);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char str[1024];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count the frequency of words in the string
    int nwords;
    WordFreq *wf = countWords(str, &nwords);
    if (wf == NULL) {
        return EXIT_FAILURE;
    }

    // Print the word frequencies
    printWordFrequencies(wf, nwords);

    // Free the memory allocated for the word frequencies
    for (int i = 0; i < nwords; i++) {
        free(wf[i].word);
    }
    free(wf);

    return EXIT_SUCCESS;
}