//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char **words;
    int numWords;
    int maxWords;
} AlienWord;

AlienWord *alienWord_create(int maxWords) {
    AlienWord *word = malloc(sizeof(AlienWord));
    word->words = malloc(sizeof(char *) * maxWords);
    word->numWords = 0;
    word->maxWords = maxWords;
    return word;
}

void alienWord_add(AlienWord *word, char *wordStr) {
    if (word->numWords >= word->maxWords) {
        return;
    }

    word->words[word->numWords] = malloc(sizeof(char) * MAX_WORD_LENGTH);
    strcpy(word->words[word->numWords], wordStr);
    word->numWords++;
}

int alienWord_search(AlienWord *word, char *wordStr) {
    for (int i = 0; i < word->numWords; i++) {
        if (strcmp(word->words[i], wordStr) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    AlienWord *alienWord = alienWord_create(MAX_WORDS);

    alienWord_add(alienWord, "Zaphod");
    alienWord_add(alienWord, "Trillian");
    alienWord_add(alienWord, "Arthur");

    int searchResult = alienWord_search(alienWord, "Trillian");

    if (searchResult != -1) {
        printf("Word found at index %d\n", searchResult);
    } else {
        printf("Word not found\n");
    }

    return 0;
}