//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *word_create(char *word) {
    Word *w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = 0;
    return w;
}

void word_increment(Word *w) {
    w->frequency++;
}

int main() {
    char text[] = "This is a sample text for word frequency counting. The text contains many different words, but some words appear more than others. For example, the word 'the' appears three times, while the word 'sample' appears only once.";

    Word **words = NULL;
    int word_count = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token) {
        Word *w = word_create(token);
        words = realloc(words, (word_count + 1) * sizeof(Word *));
        words[word_count++] = w;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    for (int i = 0; i < word_count; i++) {
        word_increment(words[i]);
    }

    // Print the word frequency
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    return 0;
}