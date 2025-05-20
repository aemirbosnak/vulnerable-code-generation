//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} word_t;

int cmp(const void *a, const void *b) {
    word_t *wa = (word_t *)a;
    word_t *wb = (word_t *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    char *text = "This is a sample text with some words that are repeated multiple times. We will count the frequency of each word and print the results.";
    char *words[MAX_WORDS];
    int counts[MAX_WORDS];
    int nwords = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[nwords] = token;
        counts[nwords] = 1;
        nwords++;
        token = strtok(NULL, " ");
    }

    // Sort the words alphabetically
    qsort(words, nwords, sizeof(char *), cmp);

    // Count the frequency of each word
    for (int i = 0; i < nwords; i++) {
        if (strcmp(words[i], words[i+1]) == 0) {
            counts[i+1] += counts[i];
            counts[i] = 0;
        }
    }

    // Print the results
    printf("Word\tCount\n");
    for (int i = 0; i < nwords; i++) {
        if (counts[i] > 0) {
            printf("%s\t%d\n", words[i], counts[i]);
        }
    }

    return 0;
}