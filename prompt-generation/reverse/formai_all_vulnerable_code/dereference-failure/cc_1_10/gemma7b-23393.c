//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char word[MAX_WORD_LENGTH];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordCreate() {
    AlienWord* newWord = malloc(sizeof(AlienWord));
    newWord->next = NULL;
    return newWord;
}

void alienWordAdd(AlienWord* wordList, char* word) {
    AlienWord* newWord = alienWordCreate();
    strcpy(newWord->word, word);
    if (wordList) {
        wordList->next = newWord;
    } else {
        wordList = newWord;
    }
}

char* alienWordTranslate(AlienWord* wordList, char* alienWord) {
    for (AlienWord* currentWord = wordList; currentWord; currentWord = currentWord->next) {
        if (strcmp(currentWord->word, alienWord) == 0) {
            return currentWord->word;
        }
    }
    return NULL;
}

int main() {
    AlienWord* alienWordList = alienWordCreate();
    alienWordAdd(alienWordList, "glorb");
    alienWordAdd(alienWordList, "snork");
    alienWordAdd(alienWordList, "blorg");

    char* alienWord = "snork";
    char* translatedWord = alienWordTranslate(alienWordList, alienWord);

    if (translatedWord) {
        printf("Translated word: %s\n", translatedWord);
    } else {
        printf("Word not found.\n");
    }

    return 0;
}