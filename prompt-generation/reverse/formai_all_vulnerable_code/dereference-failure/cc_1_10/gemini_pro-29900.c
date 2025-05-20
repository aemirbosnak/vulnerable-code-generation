//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *word;
    int count;
} word_count;

int compare_words(const void *a, const void *b) {
    word_count *wc1 = (word_count *)a;
    word_count *wc2 = (word_count *)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    char *text = "This is a sample text to demonstrate text processing. This text contains multiple words that appear multiple times. We can use this text to count the frequency of each word and sort the words by their frequency.";

    // Tokenize the text into words
    char *token = strtok(text, " ");
    int num_words = 0;
    word_count *words = NULL;
    while (token != NULL) {
        // Convert the word to lowercase
        char *word = strdup(token);
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Find the word in the list of words
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found) {
            words = realloc(words, (num_words + 1) * sizeof(word_count));
            words[num_words].word = word;
            words[num_words].count = 1;
            num_words++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the words by their frequency
    qsort(words, num_words, sizeof(word_count), compare_words);

    // Print the words and their frequencies
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free the memory allocated for the words
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}