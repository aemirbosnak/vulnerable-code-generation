//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList(char **text, int textLength) {
    Word **wordList = malloc(textLength * sizeof(Word *));
    for (int i = 0; i < textLength; i++) {
        wordList[i] = malloc(sizeof(Word));
        wordList[i]->word = strdup(text[i]);
        wordList[i]->frequency = 1;
    }
    return wordList;
}

void calculateWordFrequencies(Word **wordList, int textLength) {
    for (int i = 0; i < textLength; i++) {
        for (int j = 0; j < textLength; j++) {
            if (wordList[i]->word == wordList[j]->word) {
                wordList[i]->frequency++;
            }
        }
    }
}

void printWordFrequencies(Word **wordList, int textLength) {
    for (int i = 0; i < textLength; i++) {
        printf("%s: %d\n", wordList[i]->word, wordList[i]->frequency);
    }
}

int main() {
    char **text = malloc(1024 * sizeof(char *));
    text[0] = "The quick brown fox jumps over the lazy dog.";
    text[1] = "The quick brown fox jumps over the lazy dog.";
    text[2] = "The quick brown fox jumps over the lazy dog.";

    int textLength = 3;

    Word **wordList = createWordList(text, textLength);
    calculateWordFrequencies(wordList, textLength);
    printWordFrequencies(wordList, textLength);

    return 0;
}