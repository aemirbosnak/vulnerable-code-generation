//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *p1 = (const word_count_pair *)a;
    const word_count_pair *p2 = (const word_count_pair *)b;
    return p2->count - p1->count;
}

int main() {
    FILE *fp;
    char *filename = "input.txt";
    char *word;
    int i, j, word_count = 0;
    word_count_pair *word_count_pairs;

    // Allocate memory for the array of word count pairs
    word_count_pairs = (word_count_pair *)malloc(sizeof(word_count_pair) * MAX_WORDS);
    if (word_count_pairs == NULL) {
        fprintf(stderr, "Error allocating memory for word count pairs\n");
        return 1;
    }

    // Open the input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }

    // Read the words from the file and count their occurrences
    while ((word = fgets(NULL, 0, fp)) != NULL) {
        // Remove the newline character from the word
        word[strlen(word) - 1] = '\0';

        // Check if the word is already in the array of word count pairs
        for (i = 0; i < word_count; i++) {
            if (strcmp(word, word_count_pairs[i].word) == 0) {
                word_count_pairs[i].count++;
                break;
            }
        }

        // If the word is not in the array, add it
        if (i == word_count) {
            word_count_pairs[word_count].word = strdup(word);
            word_count_pairs[word_count].count = 1;
            word_count++;
        }
    }

    // Close the input file
    fclose(fp);

    // Sort the array of word count pairs in descending order of count
    qsort(word_count_pairs, word_count, sizeof(word_count_pair), compare_word_count_pairs);

    // Print the word count pairs
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_count_pairs[i].word, word_count_pairs[i].count);
    }

    // Free the memory allocated for the array of word count pairs
    for (i = 0; i < word_count; i++) {
        free(word_count_pairs[i].word);
    }
    free(word_count_pairs);

    return 0;
}