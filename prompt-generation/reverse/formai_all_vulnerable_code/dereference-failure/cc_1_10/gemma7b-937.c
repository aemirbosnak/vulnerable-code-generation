//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *word_frequency_counter(char *text) {
    Word *words = malloc(MAX_WORDS * sizeof(Word));
    words[0].word = NULL;

    char *token = strtok(text, " ");
    int i = 0;

    while (token) {
        int found = 0;
        for (int j = 0; words[j].word != NULL; j++) {
            if (strcmp(token, words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
            }
        }

        if (!found) {
            words[i].word = strdup(token);
            words[i].frequency = 1;
            i++;
        }
        token = strtok(NULL, " ");
    }

    return words;
}

int main() {
    char *text = "This is a sample text for word frequency counter. It has many words, some of them are repeated. The repeated words should have their frequency increased.";

    Word *words = word_frequency_counter(text);

    for (int i = 0; words[i].word != NULL; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    free(words);

    return 0;
}