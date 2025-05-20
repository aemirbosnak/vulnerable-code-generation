//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_VOCAB_SIZE 50000

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordEntry;

WordEntry* wordEntries;
int vocabSize = 0;

void initializeVocab(WordEntry* wordEntries, int size) {
    vocabSize = size;
    wordEntries = (WordEntry*) malloc(sizeof(WordEntry) * size);
}

int isWordInVocab(char* word) {
    int i;
    for (i = 0; i < vocabSize; i++) {
        if (strcmp(wordEntries[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void addWordToVocab(char* word, char* translation) {
    int i;
    for (i = 0; i < vocabSize; i++) {
        if (strcmp(wordEntries[i].word, word) == 0) {
            strcpy(wordEntries[i].translation, translation);
            return;
        }
    }
    WordEntry newEntry = {.word = strcpy(malloc(MAX_WORD_LENGTH * sizeof(char)), word),.translation = strcpy(malloc(MAX_WORD_LENGTH * sizeof(char)), translation) };
    wordEntries[vocabSize++] = newEntry;
}

void translateWord(char* word) {
    if (isWordInVocab(word)) {
        printf("%s => %s\n", word, wordEntries[vocabSize - 1].translation);
    } else {
        printf("Unknown word: %s\n", word);
    }
}

int main() {
    WordEntry* wordEntries = (WordEntry*) malloc(sizeof(WordEntry) * MAX_VOCAB_SIZE);
    initializeVocab(wordEntries, MAX_VOCAB_SIZE);

    addWordToVocab("Hello", "Omnivoros");
    addWordToVocab("World", "Galaxy");

    translateWord("Hello");
    translateWord("World");

    free(wordEntries);

    return 0;
}