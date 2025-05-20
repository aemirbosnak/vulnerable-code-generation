//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store word and its count
typedef struct WordCount {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

// Function to count the occurrences of each word in a string
WordCount *countWords(const char *str) {
    // Split the string into words
    char *words[1000];
    int num_words = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Create an array of WordCount structures
    WordCount *wc = malloc(sizeof(WordCount) * num_words);

    // Initialize the WordCount structures
    for (int i = 0; i < num_words; i++) {
        wc[i].word = words[i];
        wc[i].count = 0;
    }

    // Count the occurrences of each word
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(wc[i].word, wc[j].word) == 0) {
                wc[i].count++;
                wc[j].word = NULL;
            }
        }
    }

    // Remove the NULL words
    int new_num_words = 0;
    for (int i = 0; i < num_words; i++) {
        if (wc[i].word != NULL) {
            wc[new_num_words++] = wc[i];
        }
    }

    // Sort the WordCount structures
    qsort(wc, new_num_words, sizeof(WordCount), compareWordCount);

    // Return the WordCount structures
    return wc;
}

// Function to print the WordCount structures
void printWordCount(WordCount *wc, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }
}

// Main function
int main() {
    // Get the input string
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    // Count the words in the string
    WordCount *wc = countWords(str);

    // Get the number of words
    int num_words = 0;
    while (wc[num_words].word != NULL) {
        num_words++;
    }

    // Print the word counts
    printWordCount(wc, num_words);

    // Free the memory allocated for the WordCount structures
    free(wc);

    return 0;
}