//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char **words;
    int size;
} AlienWord;

AlienWord *createAlienWord() {
    AlienWord *word = malloc(sizeof(AlienWord));
    word->words = malloc(MAX_WORDS * sizeof(char *));
    word->size = 0;
    return word;
}

void addAlienWord(AlienWord *word, char *wordStr) {
    if (word->size >= MAX_WORDS) {
        return;
    }

    word->words[word->size] = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(word->words[word->size], wordStr);
    word->size++;
}

int translateAlienWord(AlienWord *word, char *englishStr) {
    for (int i = 0; i < word->size; i++) {
        if (strcmp(englishStr, word->words[i]) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    AlienWord *alienWord = createAlienWord();
    addAlienWord(alienWord, "Blorg");
    addAlienWord(alienWord, "Zork");
    addAlienWord(alienWord, "Nibble");

    char *englishStr = "Zork";
    int translationIndex = translateAlienWord(alienWord, englishStr);

    if (translationIndex != -1) {
        printf("Translation index: %d\n", translationIndex);
    } else {
        printf("Word not found.\n");
    }

    return 0;
}