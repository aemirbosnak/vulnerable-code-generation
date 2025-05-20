//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *createWord(char *word) {
    Word *w = (Word *)malloc(sizeof(Word));
    w->word = strdup(word);
    w->frequency = 0;
    return w;
}

void incrementWordFrequency(Word *w) {
    w->frequency++;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    Word **words = (Word **)malloc(MAX_WORDS * sizeof(Word *));

    char *word = NULL;
    int i = 0;

    // Tokenize the text
    word = strtok(text, " ");

    // Create a word for each token
    while (word) {
        Word *w = createWord(word);
        words[i++] = w;
        word = strtok(NULL, " ");
    }

    // Increment the frequency of each word
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i]) {
            incrementWordFrequency(words[i]);
        }
    }

    // Print the word frequency
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i]) {
            printf("%s: %d\n", words[i]->word, words[i]->frequency);
        }
    }

    return 0;
}