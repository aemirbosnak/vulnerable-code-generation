//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct AlienWord {
    char *word;
    struct AlienWord *next;
} AlienWord;

AlienWord *alienWordHead = NULL;

void alienWordAdd(char *word) {
    AlienWord *newWord = malloc(sizeof(AlienWord));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (alienWordHead == NULL) {
        alienWordHead = newWord;
    } else {
        AlienWord *currentWord = alienWordHead;
        while (currentWord->next) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }
}

char *alienWordTranslate(char *word) {
    char *translatedWord = malloc(MAX_WORDS);

    AlienWord *currentWord = alienWordHead;
    while (currentWord) {
        if (strcmp(word, currentWord->word) == 0) {
            strcpy(translatedWord, currentWord->word);
            break;
        }
        currentWord = currentWord->next;
    }

    return translatedWord;
}

int main() {
    alienWordAdd("Blorg");
    alienWordAdd("Zork");
    alienWordAdd("Quux");

    char *translatedWord = alienWordTranslate("Blorg");

    printf("%s\n", translatedWord);

    free(translatedWord);

    return 0;
}