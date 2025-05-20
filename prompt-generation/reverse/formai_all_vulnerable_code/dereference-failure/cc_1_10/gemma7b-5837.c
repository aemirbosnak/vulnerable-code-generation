//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord {
    char word[20];
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

int alienWordTranslate(AlienWord* wordList, char* alienWord) {
    for (AlienWord* word = wordList; word; word = word->next) {
        if (strcmp(word->word, alienWord) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    AlienWord* alienWordList = alienWordCreate();
    alienWordAdd(alienWordList, "Blorg");
    alienWordAdd(alienWordList, "Zork");
    alienWordAdd(alienWordList, "Florg");

    char* alienWord = "Florg";
    if (alienWordTranslate(alienWordList, alienWord)) {
        printf("Translation found: %s\n", alienWord);
    } else {
        printf("Translation not found.\n");
    }

    return 0;
}