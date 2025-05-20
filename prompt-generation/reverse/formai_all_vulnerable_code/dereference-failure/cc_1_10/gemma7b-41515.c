//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **words;

void incrementWord(char *word) {
    Word *wordNode = NULL;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i] == NULL) {
            words[i] = malloc(sizeof(Word));
            words[i]->word = strdup(word);
            words[i]->frequency = 1;
            return;
        } else if (strcmp(words[i]->word, word) == 0) {
            words[i]->frequency++;
            return;
        }
    }

    // Word not found, so add it to the end
    words[MAX_WORDS - 1] = malloc(sizeof(Word));
    words[MAX_WORDS - 1]->word = strdup(word);
    words[MAX_WORDS - 1]->frequency = 1;
}

int main() {
    words = malloc(MAX_WORDS * sizeof(Word));

    // Distributed word counting
    char *sentence = "This is a sample sentence with many words. The words are repeated several times.";
    char *wordsArray[] = {"the", "sample", "sentence", "with", "many", "words", "are", "repeated", "several", "times"};

    for (int i = 0; i < 10; i++) {
        incrementWord(wordsArray[i]);
    }

    // Print the word frequencies
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i] != NULL) {
            printf("%s: %d\n", words[i]->word, words[i]->frequency);
        }
    }

    free(words);
    return 0;
}