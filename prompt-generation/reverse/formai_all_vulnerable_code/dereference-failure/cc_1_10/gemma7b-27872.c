//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **word_frequency(char *text) {
    Word **words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    char *word = NULL;
    int word_count = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (word == NULL) {
            word = malloc(20 * sizeof(char));
            words[word_count] = malloc(sizeof(Word));
            words[word_count]->word = word;
            words[word_count]->frequency = 0;
            word_count++;
        } else if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            words[word_count]->frequency++;
            word = NULL;
        } else {
            word = realloc(word, 20 * sizeof(char));
            word[0] = text[i];
            word[1] = '\0';
            words[word_count]->word = word;
            words[word_count]->frequency = 0;
            word_count++;
        }
    }

    return words;
}

int main() {
    char *text = "This is a sample text with many words. Some words are repeated multiple times. The frequency of each word is counted and printed below.";

    Word **words = word_frequency(text);

    for (int i = 0; words[i] != NULL; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    free(words);

    return 0;
}