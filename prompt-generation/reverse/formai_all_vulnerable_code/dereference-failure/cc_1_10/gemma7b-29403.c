//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
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

int alienWordSearch(AlienWord* wordList, char* word) {
    for (AlienWord* currentWord = wordList; currentWord; currentWord = currentWord->next) {
        if (strcmp(currentWord->word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    AlienWord* alienWordHead = alienWordCreate();

    // Multiplayer code begins here

    // Client connects to server
    // Server sends list of alien words
    // Client searches for alien word and sends result

    // Example alien words
    alienWordAdd(alienWordHead, "Blork");
    alienWordAdd(alienWordHead, "Zork");
    alienWordAdd(alienWordHead, "Quork");

    // Client searches for alien word
    if (alienWordSearch(alienWordHead, "Zork") == 1) {
        printf("Word found.\n");
    } else {
        printf("Word not found.\n");
    }

    return 0;
}