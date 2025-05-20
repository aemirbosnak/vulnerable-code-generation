//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char *word;
    int length;
} AlienWord;

AlienWord *createAlienWord(char *word, int length) {
    AlienWord *alienWord = malloc(sizeof(AlienWord));
    alienWord->word = strdup(word);
    alienWord->length = length;
    return alienWord;
}

void translateAlienWord(AlienWord *alienWord) {
    char *translatedWord = malloc(MAX_WORD_LENGTH);
    int i = 0;
    for (i = 0; i < alienWord->length; i++) {
        switch (alienWord->word[i]) {
            case 'a':
                translatedWord[i] = 'e';
                break;
            case 'b':
                translatedWord[i] = 'h';
                break;
            case 'c':
                translatedWord[i] = 't';
                break;
            case 'd':
                translatedWord[i] = 'r';
                break;
            case 'e':
                translatedWord[i] = 'a';
                break;
            default:
                translatedWord[i] = alienWord->word[i];
                break;
        }
    }
    translatedWord[alienWord->length] = '\0';
    printf("%s\n", translatedWord);
    free(translatedWord);
}

int main() {
    AlienWord *alienWord = createAlienWord("Tr'al'nak'la", 12);
    translateAlienWord(alienWord);
    free(alienWord);
    return 0;
}