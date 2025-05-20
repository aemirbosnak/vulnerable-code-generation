//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *createWord(char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;
    return newWord;
}

void incrementWord(Word *word) {
    word->frequency++;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    Word **words = malloc(MAX_WORDS * sizeof(Word *));

    int numWords = 0;

    char *word = strtok(text, " ");

    while (word) {
        Word *existingWord = NULL;

        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i]->word) == 0) {
                existingWord = words[i];
            }
        }

        if (existingWord) {
            incrementWord(existingWord);
        } else {
            words[numWords++] = createWord(word);
        }
        word = strtok(NULL, " ");
    }

    printf("Word frequency:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    free(words);

    return 0;
}