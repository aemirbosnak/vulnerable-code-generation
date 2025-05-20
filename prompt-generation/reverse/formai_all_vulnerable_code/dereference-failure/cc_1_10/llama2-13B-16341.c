//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to hold the list of words
typedef struct {
    char *word;
    int count;
} word_t;

// Function to sort the list of words
void sort_words(word_t *words) {
    int i, j, min_idx;

    // Loop through the list of words
    for (i = 0; i < MAX_SIZE; i++) {
        // Find the smallest index
        min_idx = i;
        for (j = i + 1; j < MAX_SIZE; j++) {
            if (words[j].count < words[min_idx].count) {
                min_idx = j;
            }
        }

        // Swap the words
        word_t temp = words[min_idx];
        words[min_idx] = words[i];
        words[i] = temp;
    }
}

// Function to get the list of words from the user
word_t *get_words(void) {
    int i, count;
    word_t *words = calloc(MAX_SIZE, sizeof(word_t));

    // Loop through the list of words
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i].word);
        words[i].count = 1;
    }

    return words;
}

int main(void) {
    srand(time(NULL));

    // Get the list of words from the user
    word_t *words = get_words();

    // Sort the list of words
    sort_words(words);

    // Print the sorted list of words
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d. %s (%d)\n", i + 1, words[i].word, words[i].count);
    }

    return 0;
}