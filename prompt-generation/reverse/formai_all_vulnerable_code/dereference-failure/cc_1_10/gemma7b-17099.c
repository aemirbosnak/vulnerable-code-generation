//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

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
    char* translatedWord = malloc(MAX_WORD_LENGTH);
    for (AlienWord* currentWord = wordList; currentWord; currentWord = currentWord->next) {
        if (strcmp(currentWord->word, alienWord) == 0) {
            strcpy(translatedWord, currentWord->word);
            break;
        }
    }
    return translatedWord;
}

int main() {
    AlienWord* alienWordList = alienWordCreate();
    alienWordAdd(alienWordList, "Blorg");
    alienWordAdd(alienWordList, "Zork");
    alienWordAdd(alienWordList, "Quux");

    char* alienWord = "Blorg";
    char* translatedWord = alienWordTranslate(alienWordList, alienWord);

    printf("Translated word: %s\n", translatedWord);

    free(translatedWord);
    free(alienWordList);

    return 0;
}