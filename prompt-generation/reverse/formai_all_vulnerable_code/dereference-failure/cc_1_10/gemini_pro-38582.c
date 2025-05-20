//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} word_count;

int compare_words(const void *a, const void *b) {
    word_count *wa = (word_count *)a;
    word_count *wb = (word_count *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    char input[1000];
    char *words[MAX_WORDS];
    int counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter some text:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string into words
    char *word = strtok(input, " ");
    while (word != NULL) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it
        if (!found) {
            words[num_words] = strdup(word);
            counts[num_words] = 1;
            num_words++;
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Sort the words by frequency
    qsort(words, num_words, sizeof(word_count), compare_words);

    // Print the word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}