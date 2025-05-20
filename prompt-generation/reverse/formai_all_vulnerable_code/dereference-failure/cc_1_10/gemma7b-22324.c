//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 255

typedef struct AlienWord {
    char word[MAX_WORD_LENGTH];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWord_create(char* word)
{
    AlienWord* newWord = malloc(sizeof(AlienWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void alienWord_append(AlienWord* wordList, char* word)
{
    AlienWord* newWord = alienWord_create(word);
    if (wordList == NULL) {
        wordList = newWord;
    } else {
        wordList->next = newWord;
    }
    wordList = newWord;
}

int alienWord_translate(AlienWord* wordList, char* alienWord)
{
    for (AlienWord* word = wordList; word; word = word->next) {
        if (strcmp(word->word, alienWord) == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    AlienWord* alienWordList = NULL;
    alienWord_append(alienWordList, "Blorg");
    alienWord_append(alienWordList, "Zork");
    alienWord_append(alienWordList, "Quux");

    if (alienWord_translate(alienWordList, "Zork") == 1) {
        printf("Zork is in the list.\n");
    } else {
        printf("Zork is not in the list.\n");
    }

    return 0;
}