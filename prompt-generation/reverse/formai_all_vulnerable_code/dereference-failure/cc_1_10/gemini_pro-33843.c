//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Custom data structure to store words and their frequencies
typedef struct word_freq {
    char *word;
    int count;
} word_freq;

// Compare two word_freq structs by word
int compare_words(const void *a, const void *b) {
    const word_freq *wa = (const word_freq *)a;
    const word_freq *wb = (const word_freq *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // A nice C string to parse
    char *text = "this is a string with words to count the frequency of each word in this string";

    // Allocate memory for an array of word_freq structs
    int max_words = 100;
    word_freq *word_freqs = malloc(sizeof(word_freq) * max_words);

    // Initialize the word_freq structs
    for (int i = 0; i < max_words; i++) {
        word_freqs[i].word = NULL;
        word_freqs[i].count = 0;
    }

    // Tokenize the string into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Find the word in the array of word_freq structs
        int word_index = -1;
        for (int i = 0; i < max_words; i++) {
            if (word_freqs[i].word != NULL && strcmp(word_freqs[i].word, token) == 0) {
                word_index = i;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (word_index == -1) {
            for (int i = 0; i < max_words; i++) {
                if (word_freqs[i].word == NULL) {
                    word_freqs[i].word = strdup(token);
                    word_freqs[i].count = 1;
                    break;
                }
            }
        } else {
            // If the word is found, increment its count
            word_freqs[word_index].count++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the array of word_freq structs by word
    qsort(word_freqs, max_words, sizeof(word_freq), compare_words);

    // Print the word frequencies
    for (int i = 0; i < max_words; i++) {
        if (word_freqs[i].word != NULL) {
            printf("%s: %d\n", word_freqs[i].word, word_freqs[i].count);
        }
    }

    // Free the memory allocated for the array of word_freq structs
    for (int i = 0; i < max_words; i++) {
        if (word_freqs[i].word != NULL) {
            free(word_freqs[i].word);
        }
    }
    free(word_freqs);

    return 0;
}