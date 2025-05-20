//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT_MAX 10000

struct word {
    char *word;
    int count;
};

int main() {
    srand(time(NULL));

    // Generate a random text for the word count
    char *text = malloc(100);
    for (int i = 0; i < 100; i++) {
        text[i] = 'a' + (rand() % 26);
    }

    // Initialize an array to store the word count
    struct word *word_count = malloc(WORD_COUNT_MAX * sizeof(struct word));
    int word_count_size = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Check if the word is not already in the word count array
        for (int i = 0; i < word_count_size; i++) {
            if (strcmp(word_count[i].word, token) == 0) {
                word_count[i].count++;
                break;
            }
        }

        // Add the word to the array if it's not already there
        if (word_count_size == WORD_COUNT_MAX) {
            printf("Error: Maximum word count exceeded! (%s)\n", token);
            break;
        }

        word_count_size++;
        word_count[word_count_size - 1].word = token;
        word_count[word_count_size - 1].count = 1;

        token = strtok(NULL, " ");
    }

    // Print the word count
    for (int i = 0; i < word_count_size; i++) {
        printf("%d %s\n", word_count[i].count, word_count[i].word);
    }

    free(text);
    free(word_count);

    return 0;
}