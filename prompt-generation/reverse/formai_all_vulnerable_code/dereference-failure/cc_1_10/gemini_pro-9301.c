//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *pa = (const word_count_pair *)a;
    const word_count_pair *pb = (const word_count_pair *)b;

    return strcmp(pa->word, pb->word);
}

int main() {
    char *text;
    char *word;
    int word_count;
    word_count_pair word_counts[MAX_WORDS];

    // Read the text from the standard input.
    text = (char *)malloc(10000);
    fgets(text, 10000, stdin);

    // Tokenize the text into words.
    word = strtok(text, " ");
    word_count = 0;
    while (word != NULL) {
        // Convert the word to lowercase.
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the word counts array.
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the word counts array, add it.
        if (!found) {
            word_counts[word_count].word = (char *)malloc(strlen(word) + 1);
            strcpy(word_counts[word_count].word, word);
            word_counts[word_count].count = 1;
            word_count++;
        }

        // Get the next word.
        word = strtok(NULL, " ");
    }

    // Sort the word counts array by word.
    qsort(word_counts, word_count, sizeof(word_count_pair), compare_word_count_pairs);

    // Print the word counts.
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Free the allocated memory.
    for (int i = 0; i < word_count; i++) {
        free(word_counts[i].word);
    }
    free(text);

    return 0;
}